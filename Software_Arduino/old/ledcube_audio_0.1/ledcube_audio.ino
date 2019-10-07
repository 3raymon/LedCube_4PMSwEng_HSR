 
/*
    Name:       ledcube_audio.ino
    Created:	25.04.2019 08:37
    Author:     Michael Guntli
	Rev:		0.1
*/

////////////////////////////////////////////////////
//Includes
////////////////////////////////////////////////////

#include <TimerOne.h>
//#include <SoftwareSerial.h>

////////////////////////////////////////////////////
//Variablen Deklaration
////////////////////////////////////////////////////

int L1 = 22;		//Ausgabewerte für jeweils 8 Leds
int L2 = 23;
int L3 = 24;
int L4 = 25;
int L5 = 26;
int L6 = 27;
int L7 = 28;
int L8 = 29;

int CLK1 = 30;		//Auswahl der Reihen einer Ebene
int CLK2 = 31;
int CLK3 = 32;
int CLK4 = 33;
int CLK5 = 34;
int CLK6 = 35;
int CLK7 = 36;
int CLK8 = 37;

int Ebene1 = 38;	//Auswahl der aktiven Ebene
int Ebene2 = 39;	
int Ebene3 = 40;
int Ebene4 = 41;
int Ebene5 = 42;
int Ebene6 = 43;
int Ebene7 = 44;
int Ebene8 = 45;

int ENABLE = 46;

int Schalter1 = 47;		//Schalter zur Funktionsauswahl Audio oder fixe Ausgabe
int Schalter2 = 48;
int Schalter3 = 49;
int Schalter4 = 50;

int Status1 = 51;		//Status Leds zur Anzeige welcher Modus gewählt ist
int Status2 = 52;
int Status3 = 53;

int analogPin_0 = A0;	//Analogeingänge der Bandpassfilter
int analogPin_1 = A1;
int analogPin_2 = A2;
int analogPin_3 = A3;
int analogPin_4 = A4;
int analogPin_5 = A5;
int analogPin_6 = A6;
int analogPin_7 = A7;

typedef struct ledarray		//Grundarray um Werte für die Ausgabe zu bestimmen
{
	char a[8][8][8] = { {{ 0 }} };
};

char ledaktvalue[8][8][8] = { {{0}} };		//Wird zur fortlaufenden Ausgabe verwendet

////////////////////////////////////////////////////
//Funktionsprototypen
////////////////////////////////////////////////////

void ausgabe(void);
void werteuebernehmen(struct ledarray* struct_ptr);
void ausschalten(void);
void rain(void);
void ebenenachunten(struct ledarray* struct_ptr);
void zufall(void);
void gegenpyramide(void);
void ebeneon(struct ledarray* struct_ptr, int i);
void ebeneoff(struct ledarray* struct_ptr, int i);
void audioanalyse(void);
void analogumrechnung(int value, int i);
void strobo(void);

////////////////////////////////////////////////////
//Pin Deklaration Arduino
////////////////////////////////////////////////////

void setup()
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
	Timer1.attachInterrupt(ausgabe);

	digitalWrite(ENABLE, LOW);
	
}

////////////////////////////////////////////////////
//Start Hauptprogramm
////////////////////////////////////////////////////
void loop()
{
	while (1)
	{
		if (Schalter1 == 1)
		{
			audioanalyse();
		}
		else
		{
			ausschalten();
			delay(200);
			einschalten();
			delay(200);
			ausschalten();
			rain();
			ausschalten();
			//zufall();
			ausschalten();
			aufab();
		}
		
	}
	
}

////////////////////////////////////////////////////
//Funktion Audioanalyse
////////////////////////////////////////////////////
void audioanalyse(void) 
{
	int value63Hz = analogRead(analogPin_0);		//WErte einlesen von Analogeingängen
	int value125Hz = analogRead(analogPin_1);
	int value250Hz = analogRead(analogPin_2);
	int value500Hz = analogRead(analogPin_3);
	int value1kHz = analogRead(analogPin_4);
	int value2kHz = analogRead(analogPin_5);
	int value4kHz = analogRead(analogPin_6);
	int value8kHz = analogRead(analogPin_7);

	analogumrechnung(value63Hz, 0);		//Übergabe zur Berechnung des Audiopegels
	analogumrechnung(value125Hz, 1);
	analogumrechnung(value250Hz, 2);
	analogumrechnung(value500Hz, 3);
	analogumrechnung(value1kHz, 4);
	analogumrechnung(value2kHz, 5);
	analogumrechnung(value4kHz, 6);
	analogumrechnung(value8kHz, 7);
}

////////////////////////////////////////////////////
//Funktion Analogwerte umrechnen für Ausgabe
////////////////////////////////////////////////////
void analogumrechnung(int value, int i)
{
	ledarray audioarray;
}


////////////////////////////////////////////////////
//Funktion Ausgabe auf CUBE
////////////////////////////////////////////////////
void ausgabe(void)
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
//Funktion rain
////////////////////////////////////////////////////

void rain(void)			//Darstellung von Regen auf LED CUBE
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
			rainarray.a[x][y][7] = {1};
		}
		werteuebernehmen(&rainarray);
		delay(100);
		ebenenachunten(&rainarray);
	}  
}

////////////////////////////////////////////////////
//Funktion Zufall
////////////////////////////////////////////////////
void zufall(void)
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
		werteuebernehmen(&zufallsarray);
		delay(8);
	}
	einschalten();
	delay(1000);
}

////////////////////////////////////////////////////
//Funktion Gegenpyramide
////////////////////////////////////////////////////
void gegenpyramide(void)
{
	ledarray pyramidensarray;

}

////////////////////////////////////////////////////
//Funktion Auf und Ab der Ebene
////////////////////////////////////////////////////

void aufab(void)
{
	ledarray aufabarray;

	for (int z1 = 0; z1 <= 4; z1++)
	{
		for (int z2 = 0; z2 <= 7; z2++)
		{
			ebeneon(&aufabarray, z2);
			ebeneoff(&aufabarray, (z2--));
			z2 = z2++;
			werteuebernehmen(&aufabarray);
			delay(100);

		}
		for (int z3 = 6; z3 >= 0; z3--)
		{
			ebeneon(&aufabarray, z3);
			ebeneoff(&aufabarray, z3++);
			z3 = z3--;
			werteuebernehmen(&aufabarray);
			delay(100);
		}
	}
}

////////////////////////////////////////////////////
//Funktion Einzelne Ebene einschalten
////////////////////////////////////////////////////

void ebeneon(struct ledarray* struct_ptr, int i)
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

void ebeneoff(struct ledarray* struct_ptr, int i)
{
	if ((i >= 0) & (i <= 7))
	{
		for (int x = 0; x <= 7; x++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[x][y][i] = { 0 };
			}
		}
	}

}


////////////////////////////////////////////////////
//Funktion Ebenweise nach unten schieben
////////////////////////////////////////////////////
void ebenenachunten(struct ledarray* struct_ptr)
{
	for (int z = 0; z <= 6; z++)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int x = 0; x <= 7; x++)
			{
				struct_ptr->a[x][y][z] = struct_ptr->a[x][y][z+1];
				
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
//Funktion Werte werden in das Ausgabe Array geladen
////////////////////////////////////////////////////
void werteuebernehmen(struct ledarray* struct_ptr)
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
}

////////////////////////////////////////////////////
//Funktion alle LEDs ausschalten
////////////////////////////////////////////////////
void ausschalten(void)
{
	for (int x = 0; x <= 7; x++)
	{
		for (int y = 0; y <= 7; y++)
		{
			for (int z = 0; z <= 7; z++)
			{
				ledaktvalue[x][y][z] = {0};
			}
		}
	}
	delay(20);
}

////////////////////////////////////////////////////
//Funktion alle LEDs einschalten
////////////////////////////////////////////////////
void einschalten(void)
{
	for (int x = 0; x <= 7; x++)
	{
		for (int y = 0 ; y <= 7; y++)
		{
			for (int z = 0; z <= 7; z++)
			{
				ledaktvalue[x][y][z] = {1};
			}
		}
	}
	delay(20);
}

////////////////////////////////////////////////////
//Strobo Funktion 
////////////////////////////////////////////////////
void strobo(void)
{
	for (int x = 0; x < 100; x++)
	{
		einschalten();
		delay(20);
		ausschalten();
		delay(20);
	}
}