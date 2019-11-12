/*
	Name:       ledcube_audio.ino
	Created:	04.10.2019
	Author:     Michael Guntli
	Rev:		1.0
*/

////////////////////////////////////////////////////
//Includes
////////////////////////////////////////////////////

#include "Cube.h"
#include <TimerOne.h>

////////////////////////////////////////////////////
//Variablen Deklaration
////////////////////////////////////////////////////

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

////////////////////////////////////////////////////
//Funktionsprototypen
////////////////////////////////////////////////////

//void serialEvent(void);
//void printData(void);


////////////////////////////////////////////////////
//Pin Deklaration Arduino
////////////////////////////////////////////////////

void setup()
{
	cube_initTimerEvent(&cube);
	cube.initIO();
	Serial.begin(9600);
	while (!Serial) {}
}

////////////////////////////////////////////////////
//Start Hauptprogramm
////////////////////////////////////////////////////
void loop()
{
	if (changeFlag && Serial)
	{
		switch (programm)
		{
		case RESERVED:
		{
			Serial.print("RESERVED\n");
			//cube.ausschalten();
			break;
		}
		case RAIN:
		{
			Serial.print("RAIN\n");
			//cube.rain();
			break;
		}
		case RANDOM:
		{
			Serial.print("RANDOM\n");
			//cube.zufall();
			break;
		}
		case PYRAMID:
		{
			Serial.print("PYRAMID\n");
			//cube.gegenpyramide(); //Funktion noch nicht implementiert
			break;
		}
		case STROBO:
		{
			Serial.print("STROBO\n");
			//cube.strobo();
			break;
		}
		case AUFAB:
		{
			Serial.print("AUFAB\n");
			//cube.aufab();
			break;
		}
		case LINKSRECHTS:
		{
			Serial.print("LINKSRECHTS\n");
			// Funktion fehlt noch komplett
			break;
		}
		case SCHLANGE:
		{
			Serial.print("SCHLANGE\n");
			//cube.snake();
			break;
		}
		case AUDIO:
		{
			Serial.print("AUDIO\n");
			//cube.audioanalyse();
			break;
		}
		case MATRIX:
		{
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

		//@TODO entfernen bei Einbindung

		if ((numberofDatabytes != 0) && defaultFlag == 0)
		{
			Serial.print("With ");
			Serial.print(numberofDatabytes, DEC);
			Serial.print(" Databyte(s)\n");
		}
		changeFlag = 0;
		defaultFlag = 0;
	}

	
	
		
		
	
}

////////////////////////////////////////////////////
//Funktion serial Event
// Wird aufgerufen sobald ein Befehl empfangen wird
////////////////////////////////////////////////////

void serialEvent()
{
	int Detection; //Byte to detect which programm that is choosen and how many databytes are expected
	Detection = Serial.read();
	programm = Detection & 0x0F;
	changeFlag = 1;
	numberofDatabytes = (Detection >> 4);
	Serial.readBytes(Data, numberofDatabytes);
}

////////////////////////////////////////////////////
//Funktion printData
//Sobald ein Befehl empfangen wurde wird er mit dieser Funktion bestätigt
////////////////////////////////////////////////////

void printData()
{
	for (int i = 0; i < numberofDatabytes; i++)
	{
		Serial.print(Data[i], HEX);
		Serial.print("\n");
	}
}
