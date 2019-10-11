//	Name:       cube.cpp
//	Created:	04.10.2019
//	Author :	Michael Guntli
//	Rev :		1.0

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
	//pinMode(Schalter4, INPUT);

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
	for (int z = 7; z >= 0; z--)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int x = 0; x <= 7; x++)
			{
				struct_ptr->a[x][y][z] = struct_ptr->a[x][y - 1][z];

			}
		}
	}
	for (int z = 0; z <= 7; z++)
	{
		for (int x = 0; x <= 7; x++)
		{
			struct_ptr->a[x][7][z] = { 0 };
		}
	}
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
//Funktion zufällige Schlange von oben nach unten
////////////////////////////////////////////////////
void Cube::snake(void)
{
	ledarray snakearray;
	int x = 0;
	int y = 0;
	int richtungxy = 0;

	x = random(0, 8);		//Zufälliger Startwert generieren
	y = random(0, 8);

	for (int z1 = 0; z1 < 100; z1++)
	{
		richtungxy = random(0, 3);
		switch(richtungxy)
		{
		case : 0	//positive x Richtung Topansicht von links nach rechts
			if (snakearray.a[7][y][7] != 1)
			{
				x++;
			}
			break;
		case : 1	//negative x Richtung Topansicht von rechts nach links
				if (snakearray.a[0][y][7] != 1)
				{
					x--;
				}
				break;
			case : 2	//positive y Richtung Topansicht von hinten nach vorne
				if (snakearray.a[x][7][7] != 1)
				{
					y++;
				}
				break;
			case : 3	//negative y Richtung Topansicht von vorne nach hinten
				if (snakearray.a[x][0][7] != 1)
				{
					y--;
				}
				break;
		}
		werteUebernehmen(&snakearray);
		delay(50);
		ebeneNachUnten(&snakearray);
	}


}

////////////////////////////////////////////////////
//Funktion Audioanalyse
////////////////////////////////////////////////////

void Cube::audioanalyse(void)
{
	ledarray audioarray;
	int analogValues[8] = {0};

	analogValues[0] = analogRead(analogPin_0);		//WErte einlesen von Analogeingängen
	analogValues[1] = analogRead(analogPin_1);
	analogValues[2] = analogRead(analogPin_2);
	analogValues[3] = analogRead(analogPin_3);
	analogValues[4] = analogRead(analogPin_4);
	analogValues[5] = analogRead(analogPin_5);
	analogValues[6] = analogRead(analogPin_6);
	analogValues[7] = analogRead(analogPin_7);

	for (int z = 0; z < 8; z++)
	{
		analogValues[z] = analogUmrechnung(analogValues[z]);
	}

	for (int x = 0; x < 8; x++)
	{
		switch (analogValues[x])			//Gnd Schaltung
		{
		case 0:
			audioarray.a[x][7][0] = 0;
			break;
		case 1:
			audioarray.a[x][7][0] = 1;
			break;
		case 2:
			audioarray.a[x][7][0] = 1;
			audioarray.a[x][7][1] = 1;
			break;
		case 3:
			audioarray.a[x][7][0] = 1;
			audioarray.a[x][7][1] = 1;
			audioarray.a[x][7][2] = 1;
			break;
		case 4:
			for (int z = 0; z < 4; z++)
			{
				audioarray.a[x][7][z] = 1;
			}
			break;
		case 5:
			for (int z = 0; z < 5; z++)
			{
				audioarray.a[x][7][z] = 1;
			}
			break;
		case 6:
			for (int z = 0; z < 6; z++)
			{
				audioarray.a[x][7][z] = 1;
			}
			break;
		case 7:
			for (int z = 0; z < 7; z++)
			{
				audioarray.a[x][7][z] = 1;
			}
			break;
		case 8:
			for (int z = 0; z < 8; z++)
			{
				audioarray.a[x][7]][z] = 1;
			}
			break;
		default: digitalWrite(Status3, HIGH);
		}
	}
	werteUebernehmen(&audioarray);
}

////////////////////////////////////////////////////
//Funktion Analogwerte umrechnen für Ausgabe
////////////////////////////////////////////////////

int Cube::analogUmrechnung(int analogvalue)
{	
	int signalstaerke;
	if ((analogvalue > 40) & (analogvalue < 160))
	{
		signalstaerke = 1;
	}
	if ((analogvalue >= 160) & (analogvalue < 280))
	{
		signalstaerke = 2;
	}
	if ((analogvalue >= 280) & (analogvalue < 400))
	{
		signalstaerke = 3;
	}
	if ((analogvalue >= 400) & (analogvalue < 520))
	{
		signalstaerke = 4;
	}
	if ((analogvalue >= 520) & (analogvalue < 640))
	{
		signalstaerke = 5;
	}
	if ((analogvalue >= 640) & (analogvalue < 760))
	{
		signalstaerke = 6;
	}
	if ((analogvalue >= 760) & (analogvalue < 880))
	{
		signalstaerke = 7;
	}
	if (analogvalue >= 880)
	{
		signalstaerke = 8;
	}
	else signalstaerke = 0;
	return signalstaerke;
} 

////////////////////////////////////////////////////
//Funktion Analogwerte umrechnen für Ausgabe
////////////////////////////////////////////////////

void Cube::audioAusgabe(void)
{
	audioanalyse();
	delay(1000);
}

void Cube::testVersuch(void)
{

}