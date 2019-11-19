/*
 *	Name:			ledcube_audio.ino
 *	Created:		04.10.2019
 *	Author:			Michael Guntli
 *	Edited:			11.11.2019
 *	Edited by:		Thomas Kuhn
 *	Rev:			1.1
 *	Rev Created		15.11.2019
 */


//Includes

#include "Cube.h"
#include <Arduino_FreeRTOS.h>


//Defines for debugging

//#define DEBUG 1					//Wenn Zeile nicht auskommiert Debugging auf UART
//#define DEBUGWITHOUTDELAY 1		//Wenn Zeile nicht auskommiert Debugging auf UART


/*! \summary	Konstanten & Variablen Deklarationen. */

const int stackSize = 1000;
Cube cube;
int programm = 0;
int numberofDatabytes = 0;
int changeFlag = 0;
int defaultFlag = 0;
byte Data[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

/*!
 * \enum	Fuctions 
 */

enum {
		RESERVED = 0,
		RAIN,
		RANDOM,
		PINGPONG,
		STROBO,
		AUFAB,
		LINKSRECHTS,
		SCHLANGE,
		AUDIO,
		MATRIX
	};

/*! \brief	The task communication. */
TaskHandle_t  TaskCommunication = NULL;
/*! \brief	The task LED cube update. */
TaskHandle_t  TaskLedCubeUpdate= NULL;
/*! \brief	The task handler. */
TaskHandle_t  TaskHandler = NULL;
/*! \brief	The task LED cube active. */
TaskHandle_t  TaskLedCubeActive = NULL;

/*!
 * \fn	void(*ptrTaskToRun)(void *pvParameter);
 * \brief	Constructor.
 * \param [in,out]	pvParameter	If non-null, the pv parameter.
 */

void(*ptrTaskToRun)(void *pvParameter);


//Funktionsprototypen

void printData(void);

//Funktionsprototypen fuer Tasks
void TaskUart(void *pvParameters);
void TaskUpdate(void *pvParameters);
void TaskTaskHandler(void *pvParameters);
void TaskRain(void *pvParameters);
void TaskRandom(void *pvParameters);
void TaskPingPong(void *pvParameters);
void TaskStrobo(void *pvParameters);
void TaskAufAb(void *pvParameters);
void TaskLinksRechts(void *pvParameters);
void TaskSchlange(void *pvParameters);
void TaskAudio(void *pvParameters);
void TaskMatrix(void *pvParameters);

/*!
 * \fn	void setup()
 * \summary	Setup Funktion.
 */

void setup()
{
	cube.initIO();
	xTaskCreate(TaskUpdate, (const portCHAR *)"Update", stackSize, NULL, 2, &TaskLedCubeUpdate);
	xTaskCreate(TaskUart, (const portCHAR *)"Uart", stackSize, NULL, 2, &TaskCommunication);
	xTaskCreate(TaskTaskHandler, (const portCHAR *)"TaskHandler", stackSize, NULL, 2, &TaskHandler);
	xTaskCreate(TaskRain, (const portCHAR *)"Function", stackSize, NULL, 2, &TaskLedCubeActive);
	vTaskSuspend(TaskLedCubeActive);
	ptrTaskToRun = &TaskRain;
	Serial.begin(9600);
	while (!Serial) {}

	#ifdef DEBUGWITHOUTDELAY 
		Serial.print("Setup done\n");
	#endif
}

/*!
 * \fn	void loop()
 * \summary	Start Hauptprogramm.
 */

void loop()
{	
	//es wird alles in den Tasks erledigt
}

/*!
 * \fn	void printData()
 * \summary	Funktion printData Sobald ein Befehl empfangen wurde wird er mit dieser Funktion
 * 			best�tigt.
 */

void printData()
{
	for (int i = 0; i < numberofDatabytes; i++)
	{
		Serial.print(Data[i], HEX);
		Serial.print("\n");
	}
}

/*!
 * \fn	void TaskUart(void *pvParameters)
 * \summary	Task-Funktion: TaskUart Verarbeitet Eingaben und setzt Variablen programm und
 * 			changeFlag.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskUart(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		int Detection; //Byte to detect which programm that is choosen and how many databytes are expected
		if (Serial.available() > 0)
		{
			#ifdef DEBUGWITHOUTDELAY 
				Serial.print("TaskUart: Received Command\n");
			#endif
			vTaskSuspend(TaskLedCubeUpdate);
			Detection = Serial.read();
			programm = Detection & 0x0F;
			changeFlag = 1;
			numberofDatabytes = (Detection >> 4);
			Serial.readBytes(Data, numberofDatabytes);
		}
	}
}

/*!
 * \fn	void TaskUpdate(void *pvParameters)
 * \summary	Task-Funktion: TaskUpdate ruft alle 20ms die Funktion cube.ausgabe() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskUpdate(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		#ifdef DEBUG 
			vTaskDelay(980 / portTICK_PERIOD_MS);
			Serial.print("TaskUpdate\n");
		#endif
		vTaskDelay(20 / portTICK_PERIOD_MS);
		cube.ausgabe();
	}
}

/*!
 * \fn	void TaskTaskHandler(void *pvParameters)
 * \summary	Task-Funktion: TaskTaskHandler()
 * 			steuert Tasks.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskTaskHandler(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		#ifdef DEBUGWITHOUTDELAY
			Serial.print("TaskTaskHandler: Number of Tasks: ");
			Serial.print(uxTaskGetNumberOfTasks());
			Serial.print("\n");
		#endif
		vTaskDelay(500 / portTICK_PERIOD_MS);
		if (changeFlag && Serial)
		{
			#ifdef DEBUGWITHOUTDELAY 
				Serial.print("TaskTaskHandler: Task change detected\n");
			#endif			

			//Task delete wenn einer aktiv
			if ((TaskLedCubeActive != NULL) && (programm!=RESERVED))
			{
				vTaskDelete(TaskLedCubeActive);
				#ifdef DEBUGWITHOUTDELAY 
					Serial.print("TaskTaskHandler: Task deleted\n");
				#endif
			}

			switch (programm)
			{
			case RESERVED:
			{
				vTaskSuspend(TaskLedCubeActive);
				Serial.print("RESERVED\n");
				break;
			}
			case RAIN:
			{
				ptrTaskToRun = &TaskRain;	
				Serial.print("RAIN\n");
				break;
			}
			case RANDOM:
			{
				ptrTaskToRun = &TaskRandom;
				Serial.print("RANDOM\n");
				break;
			}
			case PINGPONG:
			{
				ptrTaskToRun = &TaskPingPong;
				Serial.print("PINGPONG\n");
				break;
			}
			case STROBO:
			{
				ptrTaskToRun = &TaskStrobo;
				Serial.print("STROBO\n");
				break;
			}
			case AUFAB:
			{
				ptrTaskToRun = &TaskAufAb;
				Serial.print("AUFAB\n");
				break;
			}
			case LINKSRECHTS:
			{
				ptrTaskToRun = &TaskLinksRechts;
				Serial.print("LINKSRECHTS\n");
				break;
			}
			case SCHLANGE:
			{
				ptrTaskToRun = &TaskSchlange;
				Serial.print("SCHLANGE\n");
				break;
			}
			case AUDIO:
			{
				ptrTaskToRun = &TaskAudio;
				Serial.print("AUDIO\n");
				break;
			}
			case MATRIX:
			{
				ptrTaskToRun = &TaskMatrix;
				Serial.print("MATRIX\n");
				//Funktion noch nicht implementiert
				break;
			}
			default:
			{
				Serial.print(programm, HEX);
				Serial.print(" is not a code for an implemented function\n");
				defaultFlag = 1;
			}
			}

			#ifdef DEBUGWITHOUTDELAY
			if ((numberofDatabytes != 0) && defaultFlag == 0)
			{
				Serial.print("With ");
				Serial.print(numberofDatabytes, DEC);
				Serial.print(" Databyte(s)\n");
			}
			#endif

			if ((ptrTaskToRun != nullptr) && (programm != RESERVED))
			{
				xTaskCreate(ptrTaskToRun, (const portCHAR *)"Funktion", stackSize, NULL, 2, &TaskLedCubeActive);
				#ifdef DEBUGWITHOUTDELAY
					Serial.print("TaskTaskHandler: Task created\n");
				#endif			
			}

			changeFlag = 0;
			defaultFlag = 0;
			vTaskResume(TaskCommunication);
			vTaskResume(TaskLedCubeUpdate);
		}
	}
}

/*!
 * \fn	void TaskRain(void *pvParameters)
 * \summary	Task-Funktion: TaskRain ruft Funktion cube.rain() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskRain(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.rain();		
	}
}

/*!
 * \fn	void TaskRandom(void *pvParameters)
 * \summary	Task-Funktion: TaskRandom ruft Funktion cube.zufall() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskRandom(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.zufall();
	}
}

/*!
 * \fn	void TaskPingPong(void *pvParameters)
 * \summary	Task-Funktion: TaskPingPong ruft Funktion cube.pingpong() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskPyramid(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.pingpong();
	}
}

/*!
 * \fn	void TaskStrobo(void *pvParameters)
 * \summary	Task-Funktion: TaskStrobo ruft Funktion cube.strobo() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskStrobo(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.strobo();
	}
}

/*!
 * \fn	void TaskAufAb(void *pvParameters)
 * \summary	Task-Funktion: TaskAufAb ruft Funktion cube.aufab() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskAufAb(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.aufab();
	}
}

/*!
 * \fn	void TaskLinksRechts(void *pvParameters)
 * \summary	Task-Funktion: TaskLinksRechts ruft noch keine Funktion auf!
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskLinksRechts(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.linksrechts();
	}
}

/*!
 * \fn	void TaskSchlange(void *pvParameters)
 * \summary	Task-Funktion: TaskSchlange ruft Funktion cube.snake() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskSchlange(void *pvParameters) 
{
	(void)pvParameters;
	for (;;)
	{
		cube.snake();
	}
}

/*!
 * \fn	void TaskAudio(void *pvParameters)
 * \summary	Task-Funktion: TaskAudio ruft Funktion cube.audioanalyse() auf.
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskAudio(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.audioanalyse();
	}
}

/*!
 * \fn	void TaskMatrix(void *pvParameters)
 * \summary	Task-Funktion: TaskMatrix ruft noch keine Funktion auf!
 * \param [in,out]	pvParameters	If non-null, options for controlling the pv.
 */

void TaskMatrix(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		//Funktion noch nicht implementiert
	}
}