//	Name:       cube.cpp
//	Created:	04.10.2019
//	Author :	Michael Guntli
//	Rev :		0.2

#include "cube.h"
#include <TimerOne.h>

//Deklaration
static Cube* inst = nullptr;

////////////////////////////////////////////////////
//Funktion wenn Interrupt eintrifft 
//Nicht teil von Klasse cube
////////////////////////////////////////////////////

static void timeout(void)
{
	if (inst != nullptr)
	{
		inst->ausgabe();
	}

}

////////////////////////////////////////////////////
//Funktion  
//Nicht teil von Klasse cube
////////////////////////////////////////////////////

void cube_initTimerEvent(Cube* obj)
{
	inst = obj;
}

////////////////////////////////////////////////////
//Initialisierung der I/O
////////////////////////////////////////////////////

void Cube::initIO(void)
{
	pinMode(L1, OUTPUT);
	pinMode(L2, OUTPUT);
	pinMode(L3, OUTPUT);
	pinMode(L4, OUTPUT);
	pinMode(L5, OUTPUT);
	pinMode(L6, OUTPUT);
	pinMode(L7, OUTPUT);
	pinMode(L8, OUTPUT);

	pinMode(CLK1, OUTPUT);
	pinMode(CLK2, OUTPUT);
	pinMode(CLK3, OUTPUT);
	pinMode(CLK4, OUTPUT);
	pinMode(CLK5, OUTPUT);
	pinMode(CLK6, OUTPUT);
	pinMode(CLK7, OUTPUT);
	pinMode(CLK8, OUTPUT);

	pinMode(Ebene1, OUTPUT);
	pinMode(Ebene2, OUTPUT);
	pinMode(Ebene3, OUTPUT);
	pinMode(Ebene4, OUTPUT);
	pinMode(Ebene5, OUTPUT);
	pinMode(Ebene6, OUTPUT);
	pinMode(Ebene7, OUTPUT);
	pinMode(Ebene8, OUTPUT);

	pinMode(ENABLE, OUTPUT);

	pinMode(Schalter1, INPUT);
	pinMode(Schalter2, INPUT);
	pinMode(Schalter3, INPUT);
	pinMode(Schalter4, INPUT);

	pinMode(Status1, OUTPUT);
	pinMode(Status2, OUTPUT);
	pinMode(Status3, OUTPUT);

	Timer1.initialize(20000);	//Timer Interrupt für die Ausgabe
	Timer1.setPeriod(20000);
	Timer1.attachInterrupt(timeout);

	digitalWrite(ENABLE, LOW);
};

////////////////////////////////////////////////////
//Funktion Ausgabe auf CUBE
////////////////////////////////////////////////////

void Cube::ausgabe(void)
{
	for (int gnd = 0; gnd <= 7; gnd++)
	{
		for (int spalte = 0; spalte <= 7; spalte++)
		{
			digitalWrite(L1, ledaktvalue[0][spalte][gnd]);	//Ausgabe von 8 Werten 
			digitalWrite(L2, ledaktvalue[1][spalte][gnd]);
			digitalWrite(L3, ledaktvalue[2][spalte][gnd]);
			digitalWrite(L4, ledaktvalue[3][spalte][gnd]);
			digitalWrite(L5, ledaktvalue[4][spalte][gnd]);
			digitalWrite(L6, ledaktvalue[5][spalte][gnd]);
			digitalWrite(L7, ledaktvalue[6][spalte][gnd]);
			digitalWrite(L8, ledaktvalue[7][spalte][gnd]);

			switch (spalte)			//Bestimmung Clk durchschaltung
			{
			case 0:

				digitalWrite(CLK1, HIGH);
				digitalWrite(CLK1, LOW);
				break;
			case 1:
				digitalWrite(CLK2, HIGH);
				digitalWrite(CLK2, LOW);
				break;
			case 2:

				digitalWrite(CLK3, HIGH);
				digitalWrite(CLK3, LOW);
				break;
			case 3:

				digitalWrite(CLK4, HIGH);
				digitalWrite(CLK4, LOW);
				break;
			case 4:
				digitalWrite(CLK5, HIGH);
				digitalWrite(CLK5, LOW);
				break;
			case 5:
				digitalWrite(CLK6, HIGH);
				digitalWrite(CLK6, LOW);
				break;
			case 6:
				digitalWrite(CLK7, HIGH);
				digitalWrite(CLK7, LOW);
				break;
			case 7:
				digitalWrite(CLK8, HIGH);
				digitalWrite(CLK8, LOW);
				break;
			}
		}

		switch (gnd)			//Gnd Schaltung
		{
		case 0:
			digitalWrite(Ebene1, HIGH);
			break;
		case 1:
			digitalWrite(Ebene2, HIGH);
			break;
		case 2:
			digitalWrite(Ebene3, HIGH);
			break;
		case 3:
			digitalWrite(Ebene4, HIGH);
			break;
		case 4:
			digitalWrite(Ebene5, HIGH);
			break;
		case 5:
			digitalWrite(Ebene6, HIGH);
			break;
		case 6:
			digitalWrite(Ebene7, HIGH);
			break;
		case 7:
			digitalWrite(Ebene8, HIGH);
			break;
		}
		delayMicroseconds(500);
		digitalWrite(Ebene1, LOW);
		digitalWrite(Ebene2, LOW);
		digitalWrite(Ebene3, LOW);
		digitalWrite(Ebene4, LOW);
		digitalWrite(Ebene5, LOW);
		digitalWrite(Ebene6, LOW);
		digitalWrite(Ebene7, LOW);
		digitalWrite(Ebene8, LOW);
	}
}

////////////////////////////////////////////////////
//Funktion Werte werden in das Ausgabe Array geladen
////////////////////////////////////////////////////
void Cube::werteUebernehmen(struct ledarray* struct_ptr)
{
	Timer1.stop();
	for (int x = 0; x <= 7; x++)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int z = 0; z <= 7; z++)
			{
				ledaktvalue[x][y][z] = struct_ptr->a[x][y][z];
			}
		}
	}
	Timer1.start();
};

////////////////////////////////////////////////////
//Funktion alle LEDs ausschalten
////////////////////////////////////////////////////

void Cube::ausschalten(void)
{
	for (int x = 0; x <= 7; x++)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int z = 0; z <= 7; z++)
			{
				ledaktvalue[x][y][z] = { 0 };
			}
		}
	}
	delay(20);
}

////////////////////////////////////////////////////
//Funktion alle LEDs einschalten
////////////////////////////////////////////////////

void Cube::einschalten(void)
{
	for (int x = 0; x <= 7; x++)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int z = 0; z <= 7; z++)
			{
				ledaktvalue[x][y][z] = { 1 };
			}
		}
	}
	delay(20);
}

////////////////////////////////////////////////////
//Funktion Einzelne Ebene einschalten
////////////////////////////////////////////////////

void Cube::ebeneOn(ledarray* struct_ptr, int i)
{
	if ((i >= 0) & (i <= 7))
	{
		for (int x = 0; x <= 7; x++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[x][y][i] = { 1 };
			}
		}
	}

}

////////////////////////////////////////////////////
//Funktion Einzelne Ebene ausschalten
////////////////////////////////////////////////////

void Cube::ebeneOff(ledarray* struct_ptr, int i)
{
	if ((i >= 0) & (i <= 7))
	{
		digitalWrite (Status2, 1);
		for (int x = 0; x <= 7; x++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[x][y][i] = { 0 };
			}
		}
	}
	else digitalWrite (Status3, 1);

}

////////////////////////////////////////////////////
//Funktion Ebenweise nach unten schieben
////////////////////////////////////////////////////
void Cube::ebeneNachUnten(struct ledarray* struct_ptr)
{
	for (int z = 0; z <= 6; z++)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int x = 0; x <= 7; x++)
			{
				struct_ptr->a[x][y][z] = struct_ptr->a[x][y][z + 1];

			}
		}
	}
	for (int y = 0; y <= 7; y++)
	{
		for (int x = 0; x <= 7; x++)
		{
			struct_ptr->a[x][y][7] = { 0 };
		}
	}
}

////////////////////////////////////////////////////
//Funktion Ebenenweise nach oben schieben
////////////////////////////////////////////////////

void Cube::ebeneNachOben(struct ledarray* struct_ptr)
{
	for (int z = 7; z >= 0; z--)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int x = 0; x <= 7; x++)
			{
				struct_ptr->a[x][y][z] = struct_ptr->a[x][y][z - 1];

			}
		}
	}
	for (int y = 0; y <= 7; y++)
	{
		for (int x = 0; x <= 7; x++)
		{
			struct_ptr->a[x][y][0] = { 0 };
		}
	}
}

////////////////////////////////////////////////////
//Funktion Ebenenweise nach hinten schieben
////////////////////////////////////////////////////

void Cube::ebeneNachHinten(struct ledarray* struct_ptr)
{

}

////////////////////////////////////////////////////
//Funktion rain
////////////////////////////////////////////////////

void Cube::rain(void)			//Darstellung von Regen auf LED CUBE
{
	ledarray rainarray;
	for (int z1 = 0; z1 < 60; z1++)
	{
		for (int z2 = 0; z2 < 2; z2++)
		{
			int x;
			int y;
			x = random(0, 8);		//Zufallswerte für Regen generieren
			y = random(0, 8);
			rainarray.a[x][y][7] = { 1 };
		}
		werteUebernehmen(&rainarray);
		delay(100);
		ebeneNachUnten(&rainarray);
	}
}

////////////////////////////////////////////////////
//Funktion Zufall
////////////////////////////////////////////////////

void Cube::zufall(void)
{
	ledarray zufallsarray;
	for (int z2 = 0; z2 < 1500; z2++)
	{
		int x;
		int y;
		int z;
		x = random(0, 8);		//Zufallswerte für Regen generieren
		y = random(0, 8);
		z = random(0, 8);
		zufallsarray.a[x][y][z] = { 1 };
		werteUebernehmen(&zufallsarray);
		delay(8);
	}
	einschalten();
	delay(1000);
}

////////////////////////////////////////////////////
//Funktion Gegenpyramide
////////////////////////////////////////////////////

void Cube::gegenpyramide(void)
{
	ledarray pyramidenarray;

}

////////////////////////////////////////////////////
//Strobo Funktion 
////////////////////////////////////////////////////

void Cube::strobo(void)
{
	for (int x = 0; x < 80; x++)
	{
		einschalten();
		delay(20);
		ausschalten();
		delay(20);
	}
}

////////////////////////////////////////////////////
//Funktion Auf und Ab der Ebene
////////////////////////////////////////////////////

void Cube::aufab(void)
{
	ledarray aufabarray;

	ebeneOn(&aufabarray, 0);
	werteUebernehmen(&aufabarray);
	delay(200);
	int pause = 380;

	for (int z1 = 0; z1 <= 5; z1++)
	{
		pause = pause - 30;
		for (int z2 = 1; z2 <= 7; z2++)
		{
			ebeneOn(&aufabarray, z2);
			z2--;
			ebeneOff(&aufabarray, z2);
			z2++;
			werteUebernehmen(&aufabarray);
			delay(pause);
		}
		pause = pause - 30;
		for (int z3 = 6; z3 >= 0; z3--)
		{
			ebeneOn(&aufabarray, z3);
			z3++;
			ebeneOff(&aufabarray, z3);
			z3--;
			werteUebernehmen(&aufabarray);
			delay(pause);
		}
	}
}


////////////////////////////////////////////////////
//Funktion Ping Pong mit jeweils einer Fläche 
//unten und oben 
////////////////////////////////////////////////////
void Cube::pingpong(void)
{
	ledarray pingpongarray;
	int x = 0;
	int y = 0;

	for (int z1 = 35; z1 >= 0; z1--)
	{
		x = random(0, 8);		//Zufallswerte generieren
		y = random(0, 8);
		pingpongarray.a[x][y][7] = { 1 };
	}
	for (int z2 = 0; z2 <= 7; z2++)
	{
		for (int z3 = 0; z3 <= 7; z3++)
		{
			if (pingpongarray.a[z2][z3][7] == 0)
			{
				pingpongarray.a[z2][z3][0] = 1;
			}
		}
	}
	werteUebernehmen(&pingpongarray);
	int richtung = 0; //Richtung = 0 nach unten schieben, Richtung = 1 nach oben schieben
	for (int z4 = 0; z4 < 100; z4++)
	{
		do
		{
			x = random(0, 8);		//Zufallswerte generieren}
			y = random(0, 8);
		} while (pingpongarray.a[x][y][7] == 1);
		for (int z = 7; z >= 1; z--)
		{
			pingpongarray.a[x][y][z] = 0;
			z--;
			pingpongarray.a[x][y][z] = 1;
			z++;
			werteUebernehmen(&pingpongarray);
			delay(20);
		}
		do
		{
			x = random(0, 8);		//Zufallswerte generieren}
			y = random(0, 8);
		} while (pingpongarray.a[x][y][0] == 1);
		for (int z = 0; z <= 6; z++)
		{
			pingpongarray.a[x][y][z] = 0;
			z++;
			pingpongarray.a[x][y][z] = 1;
			z--;
			werteUebernehmen(&pingpongarray);
			delay(20);
		}
	}
}

////////////////////////////////////////////////////
//Funktion Audioanalyse
////////////////////////////////////////////////////

void Cube::audioanalyse(void)
{
	int value63Hz = analogRead(analogPin_0);		//WErte einlesen von Analogeingängen
	int value125Hz = analogRead(analogPin_1);
	int value250Hz = analogRead(analogPin_2);
	int value500Hz = analogRead(analogPin_3);
	int value1kHz = analogRead(analogPin_4);
	int value2kHz = analogRead(analogPin_5);
	int value4kHz = analogRead(analogPin_6);
	int value8kHz = analogRead(analogPin_7);

	analogUmrechnung(value63Hz, 0);		//Übergabe zur Berechnung des Audiopegels
	analogUmrechnung(value125Hz, 1);
	analogUmrechnung(value250Hz, 2);
	analogUmrechnung(value500Hz, 3);
	analogUmrechnung(value1kHz, 4);
	analogUmrechnung(value2kHz, 5);
	analogUmrechnung(value4kHz, 6);
	analogUmrechnung(value8kHz, 7);
}

////////////////////////////////////////////////////
//Funktion Analogwerte umrechnen für Ausgabe
////////////////////////////////////////////////////

void Cube::analogUmrechnung(int value, int i)
{
	ledarray audioarray;
}