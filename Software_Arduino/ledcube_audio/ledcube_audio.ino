 
/*
    Name:       ledcube_audio.ino
    Created:	04.10.2019 
    Author:     Michael Guntli
	Rev:		1.0
*/

////////////////////////////////////////////////////
//Includes
////////////////////////////////////////////////////

#include "cube.h"
#include <TimerOne.h>

////////////////////////////////////////////////////
//Variablen Deklaration
////////////////////////////////////////////////////

////////////////////////////////////////////////////
//Funktionsprototypen
////////////////////////////////////////////////////


////////////////////////////////////////////////////
//Pin Deklaration Arduino
////////////////////////////////////////////////////

void setup()
{
	
}

////////////////////////////////////////////////////
//Start Hauptprogramm
////////////////////////////////////////////////////
void loop()
{
	Cube cube;
	cube_initTimerEvent(&cube);
	cube.initIO();

	while (1)
	{
		
		cube.ausschalten();
		delay(200);
		cube.einschalten();
		delay(200);
		cube.ausschalten();
		cube.rain();
		cube.ausschalten();
		//cube.strobo();
		cube.zufall();
		cube.ausschalten();
		cube.aufab();
		
	}
}

