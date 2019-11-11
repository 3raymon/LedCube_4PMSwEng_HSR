/*
	Name:       ledcube_audio.ino
	Created:	04.10.2019
	Author:     Michael Guntli
	Edited:		11.11.2019
	Edited by:	Thomas Kuhn
	Rev:		1.0
*/

////////////////////////////////////////////////////
//Includes
////////////////////////////////////////////////////
#include "Cube.h"
#include "Arduino_FreeRTOS.h"

////////////////////////////////////////////////////
//Defines for debugging
////////////////////////////////////////////////////
//#define DEBUG 1					//Wenn Zeile nicht auskommiert Debugging auf UART
//#define DEBUGWITHOUTDELAY 1		//Wenn Zeile nicht auskommiert Debugging auf UART

////////////////////////////////////////////////////
//Konstanten & Variablen Deklarationen
////////////////////////////////////////////////////
const int stackSize = 1000;
Cube cube;
int programm = 0;
int numberofDatabytes = 0;
int changeFlag = 0;
int defaultFlag = 0;
byte Data[17] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

enum {
		RESERVED = 0,
		RAIN,
		RANDOM,
		PYRAMID,
		STROBO,
		AUFAB,
		LINKSRECHTS,
		SCHLANGE,
		AUDIO,
		MATRIX
	};

TaskHandle_t  TaskCommunication = NULL;
TaskHandle_t  TaskLedCubeUpdate= NULL;
TaskHandle_t  TaskHandler = NULL;
TaskHandle_t  TaskLedCubeActive = NULL;
void(*ptrTaskToRun)(void *pvParameter);

////////////////////////////////////////////////////
//Funktionsprototypen
////////////////////////////////////////////////////
void printData(void);

//Funktionsprototypen fuer Tasks
void TaskUart(void *pvParameters);
void TaskUpdate(void *pvParameters);
void TaskTaskHandler(void *pvParameters);
void TaskRain(void *pvParameters);
void TaskRandom(void *pvParameters);
void TaskPyramid(void *pvParameters);
void TaskStrobo(void *pvParameters);
void TaskAufAb(void *pvParameters);
void TaskLinksRechts(void *pvParameters);
void TaskSchlange(void *pvParameters);
void TaskAudio(void *pvParameters);
void TaskMatrix(void *pvParameters);

////////////////////////////////////////////////////
//Setup Funktion
////////////////////////////////////////////////////
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

////////////////////////////////////////////////////
//Start Hauptprogramm
////////////////////////////////////////////////////
void loop()
{	
	//es wird alles in den Tasks erledigt
}

///////////////////////////////////////////////////////////////////////////
//Funktion printData
//Sobald ein Befehl empfangen wurde wird er mit dieser Funktion bestätigt
///////////////////////////////////////////////////////////////////////////
void printData()
{
	for (int i = 0; i < numberofDatabytes; i++)
	{
		Serial.print(Data[i], HEX);
		Serial.print("\n");
	}
}

///////////////////////////////////////////////////////////////////////////
//Task-Funktion: TaskUart
//Verarbeitet Eingaben und setzt Variablen programm und changeFlag
///////////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////
//Task-Funktion: TaskUpdate
//ruft alle 20ms die Funktion cube.ausgabe() auf
////////////////////////////////////////////////////
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

////////////////////////////////////////////////////
//Task-Funktion: TaskTaskHandler()
//steuert Tasks
////////////////////////////////////////////////////
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
			case PYRAMID:
			{
				ptrTaskToRun = &TaskPyramid;
				Serial.print("PYRAMID\n");
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
				// Funktion fehlt noch komplett
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

////////////////////////////////////////////////////
//Task-Funktion: TaskRain
//ruft Funktion cube.rain() auf
////////////////////////////////////////////////////
void TaskRain(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.rain();		
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskRandom
//ruft Funktion cube.zufall() auf
////////////////////////////////////////////////////
void TaskRandom(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.zufall();
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskPyramid
//ruft Funktion cube.gegenpyramide() auf
////////////////////////////////////////////////////
void TaskPyramid(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.gegenpyramide();
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskStrobo
//ruft Funktion cube.strobo() auf
////////////////////////////////////////////////////
void TaskStrobo(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.strobo();
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskAufAb
//ruft Funktion cube.aufab() auf
////////////////////////////////////////////////////
void TaskAufAb(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.aufab();
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskLinksRechts
//ruft noch keine Funktion auf!
////////////////////////////////////////////////////
void TaskLinksRechts(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		//noch nicht implementiert
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskSchlange
//ruft Funktion cube.snake() auf
////////////////////////////////////////////////////
void TaskSchlange(void *pvParameters) 
{
	(void)pvParameters;
	for (;;)
	{
		cube.snake();
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskAudio
//ruft Funktion cube.audioanalyse() auf
////////////////////////////////////////////////////
void TaskAudio(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		cube.audioanalyse();
	}
}

////////////////////////////////////////////////////
//Task-Funktion: TaskMatrix
//ruft noch keine Funktion auf!
////////////////////////////////////////////////////
void TaskMatrix(void *pvParameters)
{
	(void)pvParameters;
	for (;;)
	{
		//Funktion noch nicht implementiert
	}
}