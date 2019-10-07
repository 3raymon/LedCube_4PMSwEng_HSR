////////////////////////////////////////////////////
//Programm zur Inbetriebnahme des LED CUBE 8x8x8
//08.10.2016
//Michael Guntli
////////////////////////////////////////////////////

////////////////////////////////////////////////////
//Includes
////////////////////////////////////////////////////

#include <TimerOne.h>

////////////////////////////////////////////////////
//Variablen Deklaration
////////////////////////////////////////////////////

int L1 = 22;
int L2 = 23;
int L3 = 24;
int L4 = 25;
int L5 = 26;
int L6 = 27;
int L7 = 28;
int L8 = 29;

int CLK1 = 30;
int CLK2 = 31;
int CLK3 = 32;
int CLK4 = 33;
int CLK5 = 34;
int CLK6 = 35;
int CLK7 = 36;
int CLK8 = 37;

int Ebene1 = 38;
int Ebene2 = 39;
int Ebene3 = 40;
int Ebene4 = 41;
int Ebene5 = 42;
int Ebene6 = 43;
int Ebene7 = 44;
int Ebene8 = 45;

int ENABLE = 46;

int Schalter1 = 47;
int Schalter2 = 48;
int Schalter3 = 49;
int Schalter4 = 50;

int Status1 = 51;
int Status2 = 52;
int Status3 = 53;

int uebernehmen;

////////////////////////////////////////////////////
//Array für Ausgabe auf LED CUBE
////////////////////////////////////////////////////

char Array_1[8][8] = {						//unterste Ebene, Ebene 1
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

char Array_2[8][8] = {						//Ebene 2
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

char Array_3[8][8] = {						//Ebene 3
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

char Array_4[8][8] = {						//Ebene 4
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

char Array_5[8][8] = {						//Ebene 5
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

char Array_6[8][8] = {						//Ebene 6
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

char Array_7[8][8] = {						//Ebene 7
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

char Array_8[8][8] = {						//oberste Ebene, Ebene 8
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
						{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
					};

////////////////////////////////////////////////////
//Array für Berechnung LED CUBE
////////////////////////////////////////////////////

char rech_Array_1[8][8] = {						//unterste Ebene, Ebene 1
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

char rech_Array_2[8][8] = {						//Ebene 2
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

char rech_Array_3[8][8] = {						//Ebene 3
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

char rech_Array_4[8][8] = {						//Ebene 4
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

char rech_Array_5[8][8] = {						//Ebene 5
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

char rech_Array_6[8][8] = {						//Ebene 6
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

char rech_Array_7[8][8] = {						//Ebene 7
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

char rech_Array_8[8][8] = {						//oberste Ebene, Ebene 8
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

////////////////////////////////////////////////////
//Array um sämtliche LEDs auszuschalten
////////////////////////////////////////////////////

char LOW_Array[8][8] = {						
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW },
	{ LOW,LOW,LOW,LOW,LOW,LOW,LOW,LOW }
};

////////////////////////////////////////////////////
//Array um sämtliche LEDs einer Ebene einzuschalten
////////////////////////////////////////////////////

char HIGH_Array[8][8] = {
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH },
	{ HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH,HIGH }
};

////////////////////////////////////////////////////
//Setup Pin Deklaration
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

	Timer1.initialize(20000);
	Timer1.setPeriod(20000);
	Timer1.attachInterrupt(ausgabe);

	digitalWrite(ENABLE, LOW);
}

////////////////////////////////////////////////////
//Start Hauptprogramm
////////////////////////////////////////////////////

void loop()
{
	rain();
	Quadrat();
	//Buchstabe_B();
	Schicht_z_Achse();
	Schicht_x_Achse();
	Schicht_y_Achse();
	x_y_Schichten();
	x_y_z_Schichten();
	Zufall();
	ein_aus_Leds();
	Schlange();
	wechseln();
	pyramide();
}

////////////////////////////////////////////////////
//Funktion 1 Ausgabe auf CUBE
////////////////////////////////////////////////////

void ausgabe(void)			//Funktion zur Ausgabe auf LED CUBE
{
	if (uebernehmen == 1)
	{
		memcpy(Array_1, rech_Array_1, sizeof(rech_Array_1));
		memcpy(Array_2, rech_Array_2, sizeof(rech_Array_2));
		memcpy(Array_3, rech_Array_3, sizeof(rech_Array_3));
		memcpy(Array_4, rech_Array_4, sizeof(rech_Array_4));
		memcpy(Array_5, rech_Array_5, sizeof(rech_Array_5));
		memcpy(Array_6, rech_Array_6, sizeof(rech_Array_6));
		memcpy(Array_7, rech_Array_7, sizeof(rech_Array_7));
		memcpy(Array_8, rech_Array_8, sizeof(rech_Array_8));

		uebernehmen = 0;
	}
	for (int gndz = 0; gndz <= 7; gndz++)	//Zähler für Ebenen (Ground bestimmung)
	{
		
		for (int z1 = 0; z1 <= 7; z1++)		//Zähler für Spalten
		{
			switch (gndz)					//Array bestimmung (verschiedene Ebenen)
			{
				case 0:
					digitalWrite(L1, Array_1[z1][0]);
					digitalWrite(L2, Array_1[z1][1]);
					digitalWrite(L3, Array_1[z1][2]);
					digitalWrite(L4, Array_1[z1][3]);
					digitalWrite(L5, Array_1[z1][4]);
					digitalWrite(L6, Array_1[z1][5]);
					digitalWrite(L7, Array_1[z1][6]);
					digitalWrite(L8, Array_1[z1][7]);
					break;
				case 1:
					digitalWrite(L1, Array_2[z1][0]);
					digitalWrite(L2, Array_2[z1][1]);
					digitalWrite(L3, Array_2[z1][2]);
					digitalWrite(L4, Array_2[z1][3]);
					digitalWrite(L5, Array_2[z1][4]);
					digitalWrite(L6, Array_2[z1][5]);
					digitalWrite(L7, Array_2[z1][6]);
					digitalWrite(L8, Array_2[z1][7]);
					break;
				case 2:
					digitalWrite(L1, Array_3[z1][0]);
					digitalWrite(L2, Array_3[z1][1]);
					digitalWrite(L3, Array_3[z1][2]);
					digitalWrite(L4, Array_3[z1][3]);
					digitalWrite(L5, Array_3[z1][4]);
					digitalWrite(L6, Array_3[z1][5]);
					digitalWrite(L7, Array_3[z1][6]);
					digitalWrite(L8, Array_3[z1][7]);
					break;
				case 3:
					digitalWrite(L1, Array_4[z1][0]);
					digitalWrite(L2, Array_4[z1][1]);
					digitalWrite(L3, Array_4[z1][2]);
					digitalWrite(L4, Array_4[z1][3]);
					digitalWrite(L5, Array_4[z1][4]);
					digitalWrite(L6, Array_4[z1][5]);
					digitalWrite(L7, Array_4[z1][6]);
					digitalWrite(L8, Array_4[z1][7]);
					break;
				case 4:
					digitalWrite(L1, Array_5[z1][0]);
					digitalWrite(L2, Array_5[z1][1]);
					digitalWrite(L3, Array_5[z1][2]);
					digitalWrite(L4, Array_5[z1][3]);
					digitalWrite(L5, Array_5[z1][4]);
					digitalWrite(L6, Array_5[z1][5]);
					digitalWrite(L7, Array_5[z1][6]);
					digitalWrite(L8, Array_5[z1][7]);
					break;
				case 5:
					digitalWrite(L1, Array_6[z1][0]);
					digitalWrite(L2, Array_6[z1][1]);
					digitalWrite(L3, Array_6[z1][2]);
					digitalWrite(L4, Array_6[z1][3]);
					digitalWrite(L5, Array_6[z1][4]);
					digitalWrite(L6, Array_6[z1][5]);
					digitalWrite(L7, Array_6[z1][6]);
					digitalWrite(L8, Array_6[z1][7]);
					break;
				case 6:
					digitalWrite(L1, Array_7[z1][0]);
					digitalWrite(L2, Array_7[z1][1]);
					digitalWrite(L3, Array_7[z1][2]);
					digitalWrite(L4, Array_7[z1][3]);
					digitalWrite(L5, Array_7[z1][4]);
					digitalWrite(L6, Array_7[z1][5]);
					digitalWrite(L7, Array_7[z1][6]);
					digitalWrite(L8, Array_7[z1][7]);
					break;
				case 7:
					digitalWrite(L1, Array_8[z1][0]);
					digitalWrite(L2, Array_8[z1][1]);
					digitalWrite(L3, Array_8[z1][2]);
					digitalWrite(L4, Array_8[z1][3]);
					digitalWrite(L5, Array_8[z1][4]);
					digitalWrite(L6, Array_8[z1][5]);
					digitalWrite(L7, Array_8[z1][6]);
					digitalWrite(L8, Array_8[z1][7]);
					break;
			}

			switch (z1)			//Bestimmung Clk durchschaltung
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
		switch (gndz)			//Gnd Schaltung
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
//Funktion 2 rain
////////////////////////////////////////////////////

void rain(void)			//Darstellung von Regen auf LED CUBE
{
	ausschalten();
	for (int z4 = 0; z4 < 60; z4++)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int z3 = 0; z3 < 2; z3++)
		{
			int x;
			int y;

			x = random(0, 8);
			y = random(0, 8);

			rech_Array_8[x][y] = HIGH;
		}

		uebernehmen = 1;
		delay(100);
		
		memcpy(rech_Array_1, LOW_Array, sizeof(LOW_Array));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
	}

}

////////////////////////////////////////////////////
//Funktion 3 Schichten z Achse
////////////////////////////////////////////////////

void Schicht_z_Achse(void)
{
	ausschalten();

	memcpy(rech_Array_8, HIGH_Array, sizeof(HIGH_Array));
	uebernehmen = 1;
	delay(50);

	for (int z = 0; z <= 6; z++)
	{
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));
		uebernehmen = 1;
		delay(200);
	}

	for (int z2 = 0; z2 <= 6; z2++)
	{
		memcpy(rech_Array_8, rech_Array_7, sizeof(rech_Array_2));
		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_3));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_4));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_5));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_6));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_7));
		memcpy(rech_Array_2, rech_Array_1, sizeof(rech_Array_8));
		memcpy(rech_Array_1, LOW_Array, sizeof(LOW_Array));
		uebernehmen = 1;
		delay(200);
	}
		
	
	
}

////////////////////////////////////////////////////
//Funktion 4 Schichten x Achse
////////////////////////////////////////////////////

void Schicht_x_Achse(void)
{
	ausschalten();

	for (int x1 = 0; x1 <= 7; x1++)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int x2 = 0; x2 <= 7; x2++)
		{
			rech_Array_8[x2][x1] = HIGH;
		}

		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		uebernehmen = 1;
		delay(200);
	}
	
	for (int x3 = 6; x3 >= 0; x3--)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int x4 = 7; x4 >= 0; x4--)
		{
			rech_Array_8[x4][x3] = HIGH;
		}
		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		uebernehmen = 1;
		delay(200);
	}
}

////////////////////////////////////////////////////
//Funktion 5 Schichten y Achse
////////////////////////////////////////////////////

void Schicht_y_Achse(void)
{
	ausschalten();

	for (int x1 = 0; x1 <= 7; x1++)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int x2 = 7; x2 >= 0; x2--)
		{
			rech_Array_8[x1][x2] = HIGH;
		}

		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		uebernehmen = 1;
		delay(200);
	}

	for (int x3 = 6; x3 >= 0; x3--)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int x4 = 0; x4 <= 7; x4++)
		{
			rech_Array_8[x3][x4] = HIGH;
		}
		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		uebernehmen = 1;
		delay(200);
	}
}

////////////////////////////////////////////////////
//Funktion 6 Schnelles einschalten durch Zufall
////////////////////////////////////////////////////

void Zufall(void)
{
	ausschalten();

	int x1,x2,x3,x4,x5,x6,x7,x8;
	int y1,y2,y3,y4,y5,y6,y7,y8;

	for (int z = 0; z < 150; z++)
	{
		x1 = random(0, 8);
		y1 = random(0, 8);
		rech_Array_1[x1][y1] = HIGH;

		x2 = random(0, 8);
		y2 = random(0, 8);
		rech_Array_2[x2][y2] = HIGH;

		x3 = random(0, 8);
		y3 = random(0, 8);
		rech_Array_3[x3][y3] = HIGH;

		x4 = random(0, 8);
		y4 = random(0, 8);
		rech_Array_4[x4][y4] = HIGH;

		x5 = random(0, 8);
		y5 = random(0, 8);
		rech_Array_5[x5][y5] = HIGH;

		x6 = random(0, 8);
		y6 = random(0, 8);
		rech_Array_6[x6][y6] = HIGH;

		x7 = random(0, 8);
		y7 = random(0, 8);
		rech_Array_7[x7][y7] = HIGH;

		x8 = random(0, 8);
		y8 = random(0, 8);
		rech_Array_8[x8][y8] = HIGH;

		uebernehmen = 1;
		delay(30);
	}

	einschalten();
	
	for (int z = 0; z < 150; z++)
	{
		x1 = random(0, 8);
		y1 = random(0, 8);
		rech_Array_1[x1][y1] = LOW;

		x2 = random(0, 8);
		y2 = random(0, 8);
		rech_Array_2[x2][y2] = LOW;

		x3 = random(0, 8);
		y3 = random(0, 8);
		rech_Array_3[x3][y3] = LOW;

		x4 = random(0, 8);
		y4 = random(0, 8);
		rech_Array_4[x4][y4] = LOW;

		x5 = random(0, 8);
		y5 = random(0, 8);
		rech_Array_5[x5][y5] = LOW;

		x6 = random(0, 8);
		y6 = random(0, 8);
		rech_Array_6[x6][y6] = LOW;

		x7 = random(0, 8);
		y7 = random(0, 8);
		rech_Array_7[x7][y7] = LOW;

		x8 = random(0, 8);
		y8 = random(0, 8);
		rech_Array_8[x8][y8] = LOW;

		uebernehmen = 1;
		delay(30);
	}
	ausschalten();
}

////////////////////////////////////////////////////
//Funktion 7 x und y Achse gleichzeitig
////////////////////////////////////////////////////

void x_y_Schichten(void)
{
	ausschalten();

	for (int x1 = 7; x1 >= 0; x1--)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int x2 = 7; x2 >= 0; x2--)
		{
			rech_Array_8[x1][x2] = HIGH;
			rech_Array_8[x2][x1] = HIGH;
		}

		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		uebernehmen = 1;
		delay(200);
	}
	for (int x3 = 1; x3 <= 7; x3++)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int x4 = 0; x4 <= 7; x4++)
		{
			rech_Array_8[x3][x4] = HIGH;
			rech_Array_8[x4][x3] = HIGH;
		}
		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		uebernehmen = 1;
		delay(200);
	}
}

////////////////////////////////////////////////////
//Funktion 8 x und y und z Achse gleichzeitig
////////////////////////////////////////////////////

void x_y_z_Schichten(void)
{

	for (int x1 = 7; x1 >= 0; x1--)
	{
		ausschalten();

		for (int x2 = 7; x2 >= 0; x2--)
		{
			rech_Array_8[x1][x2] = HIGH;
			rech_Array_8[x2][x1] = HIGH;
		}

		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));

		switch (x1)
		{
		case 0:
			memcpy(rech_Array_1, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 1:
			memcpy(rech_Array_2, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 2:
			memcpy(rech_Array_3, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 3:
			memcpy(rech_Array_4, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 4:
			memcpy(rech_Array_5, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 5:
			memcpy(rech_Array_6, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 6:
			memcpy(rech_Array_7, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 7:
			memcpy(rech_Array_8, HIGH_Array, sizeof(HIGH_Array));
			break;
		}

		uebernehmen = 1;
		delay(400);
	}
	for (int x3 = 1; x3 <= 7; x3++)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));

		for (int x4 = 0; x4 <= 7; x4++)
		{
			rech_Array_8[x3][x4] = HIGH;
			rech_Array_8[x4][x3] = HIGH;
		}
		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));

		switch (x3)
		{
		case 0:
			memcpy(rech_Array_1, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 1:
			memcpy(rech_Array_2, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 2:
			memcpy(rech_Array_3, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 3:
			memcpy(rech_Array_4, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 4:
			memcpy(rech_Array_5, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 5:
			memcpy(rech_Array_6, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 6:
			memcpy(rech_Array_7, HIGH_Array, sizeof(HIGH_Array));
			break;
		case 7:
			memcpy(rech_Array_8, HIGH_Array, sizeof(HIGH_Array));
			break;
		}

		uebernehmen = 1;
		delay(400);
	}
}

////////////////////////////////////////////////////
//Funktion 9 Ein und Ausschalten von LEDS
////////////////////////////////////////////////////

void ein_aus_Leds(void)
{
	ausschalten();

	int x1, x2, x3, x4, x5, x6, x7, x8;
	int y1, y2, y3, y4, y5, y6, y7, y8;

	for (int z = 0; z < 400; z++)
	{
		x1 = random(0, 8);
		y1 = random(0, 8);

		if (rech_Array_1[x1][y1] == LOW)
		{
			rech_Array_1[x1][y1] = HIGH;
		}
		else
		{
			rech_Array_1[x1][y1] = LOW;
		}
		

		x2 = random(0, 8);
		y2 = random(0, 8);
		
		if (rech_Array_2[x2][y2] == LOW)
		{
			rech_Array_2[x2][y2] = HIGH;
		}
		else
		{
			rech_Array_2[x2][y2] = LOW;
		}

		x3 = random(0, 8);
		y3 = random(0, 8);
		
		if (rech_Array_3[x3][y3] == LOW)
		{
			rech_Array_3[x3][y3] = HIGH;
		}
		else
		{
			rech_Array_3[x3][y3] = LOW;
		}

		x4 = random(0, 8);
		y4 = random(0, 8);
		
		if (rech_Array_4[x4][y4] == LOW)
		{
			rech_Array_4[x4][y4] = HIGH;
		}
		else
		{
			rech_Array_4[x4][y4] = LOW;
		}

		x5 = random(0, 8);
		y5 = random(0, 8);
		
		if (rech_Array_5[x5][y5] == LOW)
		{
			rech_Array_5[x5][y5] = HIGH;
		}
		else
		{
			rech_Array_5[x5][y5] = LOW;
		}

		x6 = random(0, 8);
		y6 = random(0, 8);
		
		if (rech_Array_6[x6][y6] == LOW)
		{
			rech_Array_6[x6][y6] = HIGH;
		}
		else
		{
			rech_Array_6[x6][y6] = LOW;
		}

		x7 = random(0, 8);
		y7 = random(0, 8);
		
		if (rech_Array_7[x7][y7] == LOW)
		{
			rech_Array_7[x7][y7] = HIGH;
		}
		else
		{
			rech_Array_7[x7][y7] = LOW;
		}

		x8 = random(0, 8);
		y8 = random(0, 8);
		
		if (rech_Array_8[x8][y8] == LOW)
		{
			rech_Array_8[x8][y8] = HIGH;
		}
		else
		{
			rech_Array_8[x8][y8] = LOW;
		}

		uebernehmen = 1;
		delay(20);
	}
}

////////////////////////////////////////////////////
//Funktion 9 Ein und Ausschalten von LEDS
////////////////////////////////////////////////////

void Schlange(void)
{
	ausschalten();

	int x,y,richtung;
	x = 3;
	y = 3;
	richtung = 0;

	for (int z = 0; z < 150; z++)
	{
		memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));
		
		rech_Array_8[x][y] = HIGH;

		richtung = random(1, 5);

		if (richtung == 1)
		{
			if (y < 7)
			{
				y++;
			}
			else
			{
				y--;
			}
		}

		if (richtung == 2)
		{
			if (x > 0)
			{
				x--;
			}
			else
			{
				x++;
			}
		}

		if (richtung == 3)
		{
			if (y > 0)
			{
				y--;
			}
			else
			{
				y++;
			}
		}


		if (richtung == 4)
		{
			if (x < 7)
			{
				x++;
			}
			else
			{
				x--;
			}
		}
		
		memcpy(rech_Array_1, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_7, rech_Array_8, sizeof(rech_Array_8));
		uebernehmen = 1;
		delay(150);
	}
}

////////////////////////////////////////////////////
//Funktion 10 Einzelne Leds wechseln Seite
////////////////////////////////////////////////////

void wechseln(void)
{
	ausschalten();

	int x,y;

	for (int x1 = 0; x1 < 30; x1++)
	{
		x = random(0, 8);
		y = random(0, 8);

		int einlesen;

		einlesen = rech_Array_8[x][y];

		if (einlesen == LOW)
		{
			rech_Array_8[x][y] = HIGH;
		}
		else
		{
			x1--;
		}
	}
	
	for (int x2 = 0; x2 < 30; x2++)
	{
		x = random(0, 8);
		y = random(0, 8);

		int einlesen;
		int sicherung_obere_Ebene;

		einlesen = rech_Array_1[x][y];

		if (einlesen == LOW)
		{
			sicherung_obere_Ebene = rech_Array_8[x][y];
			
			if (sicherung_obere_Ebene == LOW)
			{
				rech_Array_1[x][y] = HIGH;
			}
			else
			{
				x2--;
			}
		}
		else
		{
			x2--;
		}
	}

	uebernehmen = 1;
	delay(1000);
	for (int x3 = 0; x3 < 50; x3++)
	{
		int ein_aus;
		x = 0;
		y = 0;

		for (int x4 = 0; x4 < 1; x4++)
		{
			x = random(0, 8);
			y = random(0, 8);

			ein_aus = rech_Array_8[x][y];

			if (ein_aus == HIGH)
			{
				rech_Array_8[x][y] = LOW;
				rech_Array_7[x][y] = HIGH;

				uebernehmen = 1;
				delay(30);
			}
			else
			{
				x4--;
			}
		}
		
		
		for (int x5 = 0; x5 < 6; x5++)
		{
			memcpy(rech_Array_2, rech_Array_3, sizeof(rech_Array_3));
			memcpy(rech_Array_3, rech_Array_4, sizeof(rech_Array_4));
			memcpy(rech_Array_4, rech_Array_5, sizeof(rech_Array_5));
			memcpy(rech_Array_5, rech_Array_6, sizeof(rech_Array_6));
			memcpy(rech_Array_6, rech_Array_7, sizeof(rech_Array_7));
			rech_Array_7[x][y] = LOW;
			
			uebernehmen = 1;
			delay(30);
		}

		rech_Array_1[x][y] = HIGH;
		uebernehmen = 1;
		delay(30);

		x = 0;
		y = 0;

		for (int x4 = 0; x4 < 1; x4++)
		{

			x = random(0, 8);
			y = random(0, 8);

			ein_aus = rech_Array_1[x][y];

			if (ein_aus == HIGH)
			{
				rech_Array_1[x][y] = LOW;
				rech_Array_2[x][y] = HIGH;

				uebernehmen = 1;
				delay(30);
			}
			else
			{
				x4--;
			}
		}


		for (int x5 = 0; x5 < 6; x5++)
		{
			memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
			memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
			memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
			memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
			memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
			rech_Array_2[x][y] = LOW;

			uebernehmen = 1;
			delay(30);
		}
		rech_Array_8[x][y] = HIGH;
		uebernehmen = 1;
		delay(30);
	}
}

////////////////////////////////////////////////////
//Funktion 11 Pyramiden Funktion 1
////////////////////////////////////////////////////

void pyramide(void)
{
	for (int x = 0; x < 8; x++)
	{
		ausschalten();

		memcpy(rech_Array_1, HIGH_Array, sizeof(HIGH_Array));
		uebernehmen = 1;
		delay(70);

		for (int x1 = 0; x1 < 8; x1++)
		{
			rech_Array_2[0][x1] = HIGH;
			rech_Array_2[7][x1] = HIGH;
			rech_Array_2[x1][0] = HIGH;
			rech_Array_2[x1][7] = HIGH;
		}
		rech_Array_1[0][0] = LOW;
		rech_Array_1[0][7] = LOW;
		rech_Array_1[7][0] = LOW;
		rech_Array_1[7][7] = LOW;
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, LOW_Array, sizeof(LOW_Array));
		for (int x2 = 1; x2 < 7; x2++)
		{
			rech_Array_2[0][x2] = HIGH;
			rech_Array_2[7][x2] = HIGH;
			rech_Array_2[x2][0] = HIGH;
			rech_Array_2[x2][7] = HIGH;
		}
		for (int x3 = 0; x3 < 8; x3++)
		{
			rech_Array_1[0][x3] = LOW;
			rech_Array_1[7][x3] = LOW;
			rech_Array_1[x3][0] = LOW;
			rech_Array_1[x3][7] = LOW;
		}
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, LOW_Array, sizeof(LOW_Array));
		for (int x4 = 1; x4 < 7; x4++)
		{
			rech_Array_2[1][x4] = HIGH;
			rech_Array_2[6][x4] = HIGH;
			rech_Array_2[x4][1] = HIGH;
			rech_Array_2[x4][6] = HIGH;
		}
		rech_Array_1[1][1] = LOW;
		rech_Array_1[1][6] = LOW;
		rech_Array_1[6][1] = LOW;
		rech_Array_1[6][6] = LOW;
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, LOW_Array, sizeof(LOW_Array));
		for (int x5 = 2; x5 < 7; x5++)
		{
			rech_Array_2[1][x5] = HIGH;
			rech_Array_2[6][x5] = HIGH;
			rech_Array_2[x5][1] = HIGH;
			rech_Array_2[x5][6] = HIGH;
		}
		for (int x6 = 1; x6 < 7; x6++)
		{
			rech_Array_1[1][x6] = LOW;
			rech_Array_1[6][x6] = LOW;
			rech_Array_1[x6][1] = LOW;
			rech_Array_1[x6][6] = LOW;
		}
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, LOW_Array, sizeof(LOW_Array));
		for (int x7 = 2; x7 < 6; x7++)
		{
			rech_Array_2[2][x7] = HIGH;
			rech_Array_2[5][x7] = HIGH;
			rech_Array_2[x7][2] = HIGH;
			rech_Array_2[x7][5] = HIGH;
		}
		rech_Array_1[2][2] = LOW;
		rech_Array_1[2][5] = LOW;
		rech_Array_1[5][2] = LOW;
		rech_Array_1[5][5] = LOW;
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, LOW_Array, sizeof(LOW_Array));
		for (int x8 = 3; x8 < 5; x8++)
		{
			rech_Array_2[2][x8] = HIGH;
			rech_Array_2[5][x8] = HIGH;
			rech_Array_2[x8][2] = HIGH;
			rech_Array_2[x8][5] = HIGH;
		}
		for (int x9 = 2; x9 < 6; x9++)
		{
			rech_Array_1[2][x9] = LOW;
			rech_Array_1[5][x9] = LOW;
			rech_Array_1[x9][2] = LOW;
			rech_Array_1[x9][5] = LOW;
		}
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_8, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, rech_Array_1, sizeof(rech_Array_1));
		uebernehmen = 1;
		delay(70);

		//Pyramide wird ab hier kleiner
		memcpy(rech_Array_8, rech_Array_7, sizeof(rech_Array_7));
		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, rech_Array_1, sizeof(rech_Array_1));
		memcpy(rech_Array_1, LOW_Array, sizeof(LOW_Array));
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, rech_Array_2, sizeof(rech_Array_2));
		memcpy(rech_Array_2, LOW_Array, sizeof(LOW_Array));
		for (int x10 = 1; x10 < 7; x10++)
		{
			rech_Array_8[1][x10] = HIGH;
			rech_Array_8[6][x10] = HIGH;
			rech_Array_8[x10][6] = HIGH;
			rech_Array_8[x10][1] = HIGH;
		}
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, rech_Array_3, sizeof(rech_Array_3));
		memcpy(rech_Array_3, LOW_Array, sizeof(LOW_Array));
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, rech_Array_4, sizeof(rech_Array_4));
		memcpy(rech_Array_4, LOW_Array, sizeof(LOW_Array));
		for (int x11 = 2; x11 < 6; x11++)
		{
			rech_Array_8[2][x11] = HIGH;
			rech_Array_8[5][x11] = HIGH;
			rech_Array_8[x11][5] = HIGH;
			rech_Array_8[x11][2] = HIGH;
		}
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, rech_Array_5, sizeof(rech_Array_5));
		memcpy(rech_Array_5, LOW_Array, sizeof(LOW_Array));
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_7, rech_Array_6, sizeof(rech_Array_6));
		memcpy(rech_Array_6, LOW_Array, sizeof(LOW_Array));
		uebernehmen = 1;
		delay(70);

		memcpy(rech_Array_7, LOW_Array, sizeof(LOW_Array));
		rech_Array_8[3][3] = HIGH;
		rech_Array_8[3][4] = HIGH;
		rech_Array_8[4][3] = HIGH;
		rech_Array_8[4][4] = HIGH;

		uebernehmen = 1;
		delay(70);
	}
	
}

////////////////////////////////////////////////////
//Funktion 12 Pyramiden Funktion 2
////////////////////////////////////////////////////

////////////////////////////////////////////////////
//Funktion 13 Quadrat
////////////////////////////////////////////////////

void Quadrat(void)
{
	ausschalten();

	int x1 = 0, x2 = 0, x3 = 0;
	

	rech_Array_1[0][0] = HIGH;
	uebernehmen = 1;
	delay(100);

	for (int z1 = 0; z1 < 7; z1++)
	{
		
		x1++;
		rech_Array_1[0][x1] = HIGH;
		rech_Array_1[x1][0] = HIGH;
		
		switch (x1)
		{
		case 1:
			rech_Array_2[0][0] = HIGH;
			break;
		case 2:
			rech_Array_3[0][0] = HIGH;
			break;
		case 3:
			rech_Array_4[0][0] = HIGH;
			break;
		case 4:
			rech_Array_5[0][0] = HIGH;
			break;
		case 5:
			rech_Array_6[0][0] = HIGH;
			break;
		case 6:
			rech_Array_7[0][0] = HIGH;
			break;
		case 7:
			rech_Array_8[0][0] = HIGH;
			break;
		}
		uebernehmen = 1;
		delay(100);
	}
	for (int z2 = 0; z2 < 7; z2++)
	{
		x2++;
		rech_Array_8[0][x2] = HIGH;
		rech_Array_8[x2][0] = HIGH;
		rech_Array_1[7][x2] = HIGH;
		rech_Array_1[x2][7] = HIGH;

		switch (x2)
		{
		case 1:
			rech_Array_2[7][0] = HIGH;
			rech_Array_2[0][7] = HIGH;
			break;
		case 2:
			rech_Array_3[7][0] = HIGH;
			rech_Array_3[0][7] = HIGH;
			break;
		case 3:
			rech_Array_4[7][0] = HIGH;
			rech_Array_4[0][7] = HIGH;
			break;
		case 4:
			rech_Array_5[7][0] = HIGH;
			rech_Array_5[0][7] = HIGH;
			break;
		case 5:
			rech_Array_6[7][0] = HIGH;
			rech_Array_6[0][7] = HIGH;
			break;
		case 6:
			rech_Array_7[7][0] = HIGH;
			rech_Array_7[0][7] = HIGH;
			break;
		case 7:
			rech_Array_8[7][0] = HIGH;
			rech_Array_8[0][7] = HIGH;
			break;
		}

		uebernehmen = 1;
		delay(100);
	}

	for (int z3 = 0; z3 < 7; z3++)
	{
		x3++;
		rech_Array_8[7][x3] = HIGH;
		rech_Array_8[x3][7] = HIGH;

		switch (x3)
		{
		case 1:
			rech_Array_2[7][7] = HIGH;
			break;
		case 2:
			rech_Array_3[7][7] = HIGH;
			break;
		case 3:
			rech_Array_4[7][7] = HIGH;
			break;
		case 4:
			rech_Array_5[7][7] = HIGH;
			break;
		case 5:
			rech_Array_6[7][7] = HIGH;
			break;
		case 6:
			rech_Array_7[7][7] = HIGH;
			break;
		case 7:
			rech_Array_8[7][7] = HIGH;
			break;
		}

		uebernehmen = 1;
		delay(100);
	}
	delay(1000);
}

////////////////////////////////////////////////////
//Buchstabe B
////////////////////////////////////////////////////

void Buchstabe_B(void)
{
	ausschalten();
	uebernehmen = 1;

	rech_Array_2[0][2] = HIGH;
	rech_Array_2[0][3] = HIGH;
	rech_Array_2[0][4] = HIGH;

	rech_Array_3[0][2] = HIGH;
	rech_Array_3[0][5] = HIGH;

	rech_Array_4[0][2] = HIGH;
	rech_Array_4[0][5] = HIGH;

	rech_Array_5[0][2] = HIGH;
	rech_Array_5[0][4] = HIGH;

	rech_Array_6[0][2] = HIGH;
	rech_Array_6[0][5] = HIGH;

	rech_Array_7[0][2] = HIGH;
	rech_Array_7[0][5] = HIGH;

	rech_Array_8[0][2] = HIGH;
	rech_Array_8[0][3] = HIGH;
	rech_Array_8[0][4] = HIGH;

	uebernehmen = 1;
	delay(1000);
	for (int z1 = 0; z1 < 6; z1++)
	{
		schieben_x_Achse();
		uebernehmen = 1;
		delay(1000);
	}

}

////////////////////////////////////////////////////
//Verschieben X - Achse
////////////////////////////////////////////////////

void schieben_x_Achse(void)
{
	int x1 = 6, y1 = 0;
	int x1plus1 = 7;

	for (int z1 = 0; z1 < 7; z1++)
	{
		rech_Array_1[7][z1] = LOW;
		rech_Array_2[7][z1] = LOW;
		rech_Array_3[7][z1] = LOW;
		rech_Array_4[7][z1] = LOW;
		rech_Array_5[7][z1] = LOW;
		rech_Array_6[7][z1] = LOW;
		rech_Array_7[7][z1] = LOW;
	}

	for (int z2 = 0; z2 < 6; z2++)
	{
		for (int z3 = 0; z3 < 7; z3++)
		{
			if (rech_Array_1[x1][y1] = LOW)
			{
				rech_Array_1[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_1[x1plus1][y1] = HIGH;
			}
			if (rech_Array_2[x1][y1] = LOW)
			{
				rech_Array_2[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_2[x1plus1][y1] = HIGH;
			}
			if (rech_Array_3[x1][y1] = LOW)
			{
				rech_Array_3[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_3[x1plus1][y1] = HIGH;
			}
			if (rech_Array_4[x1][y1] = LOW)
			{
				rech_Array_4[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_4[x1plus1][y1] = HIGH;
			}
			if (rech_Array_5[x1][y1] = LOW)
			{
				rech_Array_5[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_5[x1plus1][y1] = HIGH;
			}
			if (rech_Array_6[x1][y1] = LOW)
			{
				rech_Array_6[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_6[x1plus1][y1] = HIGH;
			}
			if (rech_Array_7[x1][y1] = LOW)
			{
				rech_Array_7[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_7[x1plus1][y1] = HIGH;
			}
			if (rech_Array_8[x1][y1] = LOW)
			{
				rech_Array_8[x1plus1][y1] = LOW;
			}
			else
			{
				rech_Array_8[x1plus1][y1] = HIGH;
			}
			y1++;
		}
		x1--;
		x1plus1--;
		y1 = 0;
	}
}

////////////////////////////////////////////////////
//Funktion alle LEDs ausschalten
////////////////////////////////////////////////////

void ausschalten(void)
{
	memcpy(rech_Array_8, LOW_Array, sizeof(LOW_Array));
	memcpy(rech_Array_7, LOW_Array, sizeof(LOW_Array));
	memcpy(rech_Array_6, LOW_Array, sizeof(LOW_Array));
	memcpy(rech_Array_5, LOW_Array, sizeof(LOW_Array));
	memcpy(rech_Array_4, LOW_Array, sizeof(LOW_Array));
	memcpy(rech_Array_3, LOW_Array, sizeof(LOW_Array));
	memcpy(rech_Array_2, LOW_Array, sizeof(LOW_Array));
	memcpy(rech_Array_1, LOW_Array, sizeof(LOW_Array));

	uebernehmen = 1;
	delay(20);
}

////////////////////////////////////////////////////
//Funktion alle LEDs ausschalten
////////////////////////////////////////////////////

void einschalten(void)
{
	memcpy(rech_Array_8, HIGH_Array, sizeof(HIGH_Array));
	memcpy(rech_Array_7, HIGH_Array, sizeof(HIGH_Array));
	memcpy(rech_Array_6, HIGH_Array, sizeof(HIGH_Array));
	memcpy(rech_Array_5, HIGH_Array, sizeof(HIGH_Array));
	memcpy(rech_Array_4, HIGH_Array, sizeof(HIGH_Array));
	memcpy(rech_Array_3, HIGH_Array, sizeof(HIGH_Array));
	memcpy(rech_Array_2, HIGH_Array, sizeof(HIGH_Array));
	memcpy(rech_Array_1, HIGH_Array, sizeof(HIGH_Array));

	uebernehmen = 1;
	delay(20);
}




