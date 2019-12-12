/*!
 *	\file			Cube.cpp
 *	\date			erstellt: 04.10.2019
 *	\author			Michael Guntli
 *	\version		1.1
 *	\date			berarbeitet: 15.11.2019
 *	\brief			Sourcefile mit den Funktionen fuer die Steuerung des LED-Cube
 */


#include "cube.h"
#include <Arduino_FreeRTOS.h>

/*!
 * \fn	void Cube::initIO(void);
 * \brief	Initialisierung der IOs 
 */

void Cube::initIO(void)
{
	//Ausgabewerte fuer jeweils 8 Leds.
	pinMode(L1, OUTPUT);
	pinMode(L2, OUTPUT);
	pinMode(L3, OUTPUT);
	pinMode(L4, OUTPUT);
	pinMode(L5, OUTPUT);
	pinMode(L6, OUTPUT);
	pinMode(L7, OUTPUT);
	pinMode(L8, OUTPUT);

	//Auswahl der Reihen einer Ebene.
	pinMode(CLK1, OUTPUT);
	pinMode(CLK2, OUTPUT);
	pinMode(CLK3, OUTPUT);
	pinMode(CLK4, OUTPUT);
	pinMode(CLK5, OUTPUT);
	pinMode(CLK6, OUTPUT);
	pinMode(CLK7, OUTPUT);
	pinMode(CLK8, OUTPUT);

	//Auswahl der aktiven Ebene.
	pinMode(Ebene1, OUTPUT);
	pinMode(Ebene2, OUTPUT);
	pinMode(Ebene3, OUTPUT);
	pinMode(Ebene4, OUTPUT);
	pinMode(Ebene5, OUTPUT);
	pinMode(Ebene6, OUTPUT);
	pinMode(Ebene7, OUTPUT);
	pinMode(Ebene8, OUTPUT);

	//Schaltet die Latches frei fuer Ausgabe.
	pinMode(ENABLE, OUTPUT);

	//Analogeingaenge fuer die Bandpassfilter.
	pinMode(analogPin_0, INPUT);
	pinMode(analogPin_1, INPUT);
	pinMode(analogPin_2, INPUT);
	pinMode(analogPin_3, INPUT);
	pinMode(analogPin_4, INPUT);
	pinMode(analogPin_5, INPUT);
	pinMode(analogPin_6, INPUT);
	pinMode(analogPin_7, INPUT);

	//Schalter zur Funktionsauswahl.
	pinMode(Schalter1, INPUT);
	pinMode(Schalter2, INPUT);
	pinMode(Schalter3, INPUT);
	pinMode(Schalter4, INPUT);

	//Status Leds zur Anzeige welcher Modus gewaehlt ist.
	pinMode(Status1, OUTPUT);
	pinMode(Status2, OUTPUT);
	pinMode(Status3, OUTPUT);

	digitalWrite(ENABLE, LOW);
};


/*!
 * \fn	void Cube::ausgabe(void);
 * \brief	fortlaufende Ausgabe auf den Cube
 */

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


/*!
 * \fn	void Cube::werteUebernehmen(struct ledarray* struct_ptr);
 * \brief	Werte werden in das Ausgabe Array kopiert und somit 
 * 			bei der naechsten Ausgabe auf dem Cube dargestellt.
 * \param [in,out]	struct_ptr Pointer auf zu bearbeitendes Array
 */

void Cube::werteUebernehmen(struct ledarray* struct_ptr)
{
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
};


/*!
 * \fn	void Cube::einschalten(void);
 * \brief	Einschalten des gesamten Wuerfels
 */

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
}


/*!
 * \fn	void Cube::ausschalten(void);
 * \brief	Ausschalten des gesamten Wuerfels
 */

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
}


/*!
 * \fn	void Cube::ebeneOn(struct ledarray* struct_ptr, int i);
 * \brief	Einzelne Ebene kann eingestellt werden, mit der int 
 * 			Variable wird die Ebene gewaehlt 0 bis 7 
 * 			0 bedeutet unterster Layer 7 oberster
 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
 * \param 		  	ebene		  	Auswahl der Ebene
 */

void Cube::ebeneOn(ledarray* struct_ptr, int ebene)
{
	if ((ebene >= 0) & (ebene <= 7))
	{
		for (int x = 0; x <= 7; x++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[x][y][ebene] = { 1 };
			}
		}
	}
}


/*!
 * \fn	void Cube::ebeneOff(struct ledarray* struct_ptr, int i);
 * \brief	Einzelne Ebene kann ausgeschaltet werden, mit der int 
 * 			Variable wird die Ebene gewaehlt 0 bis 7 
 * 			0 bedeutet unterster Layer 7 oberster	
 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
 * \param 		  	ebene		  	Auswahl der Ebene
 */

void Cube::ebeneOff(ledarray* struct_ptr, int ebene)
{
	if ((ebene >= 0) & (ebene <= 7))
	{
		digitalWrite(Status2, 1);
		for (int x = 0; x <= 7; x++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[x][y][ebene] = { 0 };
			}
		}
	}
	else digitalWrite(Status3, 1);

}


/*!
 * \fn	void Cube::ebeneNachUnten(struct ledarray* struct_ptr);
 * \brief	Schiebt gesamten Cube um eine Ebene nach unten
 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
 */

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


/*!
 * \fn	void Cube::ebeneNachOben(struct ledarray* struct_ptr);
 * \brief	Schiebt gesamten Cube um eine Ebene nach oben.
 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
 */

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


/*!
 * \fn	void Cube::ebeneNachHinten(struct ledarray* struct_ptr);
 * \brief	Schiebt gesamten Cube um eine Ebene nach hinten.
 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
 */

void Cube::ebeneNachHinten(struct ledarray* struct_ptr)
{
	for (int z = 7; z >= 0; z--)
	{
		for (int y = 1; y <= 7; y++)
		{
			for (int x = 0; x <= 7; x++)
			{
				struct_ptr->a[x][y-1][z] = struct_ptr->a[x][y][z];

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


/*!
 * \fn	void Cube::ebeneNachVorne(struct ledarray* struct_ptr);
 * \brief	Schiebt gesamten Cube um eine Ebene nach vorne.
 * \param [in,out]	structptr	Pointer auf zu bearbeitendes Array
 */

void Cube::ebeneNachVorne(struct ledarray* struct_ptr)
{
	for (int z = 7; z >= 0; z--)
	{
		for (int y = 6; y >= 0; y--)
		{
			for (int x = 0; x <= 7; x++)
			{
				struct_ptr->a[x][y + 1][z] = struct_ptr->a[x][y][z];

			}
		}
	}
	for (int z = 0; z <= 7; z++)
	{
		for (int x = 0; x <= 7; x++)
		{
			struct_ptr->a[x][0][z] = { 0 };
		}
	}
}


/*!
 * \fn	void Cube::ebeneNachLinks(struct ledarray* struct_ptr);
 * \brief	Schiebt gesamten Cube um eine Ebene nach links.
 * \param [in,out]	structptr	Pointer auf zu bearbeitendes Array
 */

void Cube::ebeneNachLinks(struct ledarray* struct_ptr)
{
	for (int z = 7; z >= 0; z--)
	{
		for (int x = 1; x <= 7; x++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[x - 1][y][z] = struct_ptr->a[x][y][z];

			}
		}
	}
	for (int z = 0; z <= 7; z++)
	{
		for (int y = 0; y <= 7; y++)
		{
			struct_ptr->a[7][y][z] = { 0 };
		}
	}
}


/*!
 * \fn	void Cube::ebeneNachRechts(struct ledarray* struct_ptr);
 * \brief	Schiebt gesamten Cube um eine Ebene nach rechts.
 * \param [in,out]	structptr	Pointer auf zu bearbeitendes Array
 */

void Cube::ebeneNachRechts(struct ledarray* struct_ptr)	
{
	for (int z = 7; z >= 0; z--)
	{
		for (int x = 6; x >= 0; x--)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[x + 1][y][z] = struct_ptr->a[x][y][z];

			}
		}
	}
	for (int z = 0; z <= 7; z++)
	{
		for (int y = 0; y <= 7; y++)
		{
			struct_ptr->a[0][y][z] = { 0 };
		}
	}
}


/*!
 * \fn	void Cube::seitlicheFlaecheOn(struct ledarray* struct_ptr, int i);
 * \brief	Einzelne Flaeche(von vorne nach hinten) kann eingeschaltet werden,
 * 			mit der int	Variable wird die Flaeche gewaehlt 0 bis 7
 * 			0 bedeutet ganz linke Flaeche, 7 ganz rechts
 * \param [in,out]	struct_ptr	Pointer auf zu berarbeitendes Array
 * \param 		  	flaeche		  	Auswahl der Flaeche
 */

void Cube::seitlicheFlaecheOn(struct ledarray* struct_ptr, int flaeche)
{
	if ((flaeche >= 0) & (flaeche <= 7))
	{
		for (int z = 0; z <= 7; z++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[flaeche][y][z] = { 1 };
			}
		}
	}
}


/*!
 * \fn	void Cube::seitlicheFlaecheOff(struct ledarray* struct_ptr, int i);
 * \brief	Einzelne Flaeche(von vorne nach hinten) kann ausgeschaltet werden,
 * 			mit der int	Variable wird die Flaeche gewaehlt 0 bis 7
 * 			0 bedeutet ganz linke Flaeche, 7 ganz rechts
 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
 * \param 		  	flaeche		  	Auswahl der Flaeche
 */

void Cube::seitlicheFlaecheOff(struct ledarray* struct_ptr, int flaeche)
{
	if ((flaeche >= 0) & (flaeche <= 7))
	{
		for (int z = 0; z <= 7; z++)
		{
			for (int y = 0; y <= 7; y++)
			{
				struct_ptr->a[flaeche][y][z] = { 0 };
			}
		}
	}
}


/*!
 * \fn	void Cube::rain(void);
 * \brief	Regen Funktion
 */

void Cube::rain(void)			//Darstellung von Regen auf LED-Cube
{
	ledarray rainarray;
	pinMode(13, OUTPUT); //loeschen
	for (int z1 = 0; z1 < 1000; z1++)
	{
		for (int z2 = 0; z2 < 2; z2++)
		{
			int x;
			int y;
			x = random(0, 8);		//Zufallswerte fuer Regen generieren
			y = random(0, 8);
			rainarray.a[x][y][7] = { 1 };
		}
		digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
		werteUebernehmen(&rainarray);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
		ebeneNachUnten(&rainarray);
	}
}


/*!
 * \fn	void Cube::zufall(void);
 * \brief	Zufaelliges ein und ausschalten von Leds
 */

void Cube::zufall(void)
{
	ledarray zufallsarray;
	for (int z2 = 0; z2 < 1000; z2++)
	{
		int x;
		int y;
		int z;
		x = random(0, 8);		//Zufallswerte generieren
		y = random(0, 8);
		z = random(0, 8);
		zufallsarray.a[x][y][z] = { 1 };
		werteUebernehmen(&zufallsarray);
		vTaskDelay(8 / portTICK_PERIOD_MS);
	}
	einschalten();
	vTaskDelay(500 / portTICK_PERIOD_MS);
}


/*!
 * \fn	void Cube::pyramide(void);
 * \brief	Pyramide die sich von unten nach oben aufbaut
 * 			und dann wieder abbaut.
 */

void Cube::pyramide(void)
{
	ledarray pyramidenarray;
}


/*!
 * \fn	void Cube::strobo(void);
 * \brief	Strobo mit saemtlichen Leds
 */

void Cube::strobo(void)
{
	for (int x = 0; x < 40; x++)
	{
		einschalten();
		vTaskDelay(20 / portTICK_PERIOD_MS);
		ausschalten();
		vTaskDelay(20 / portTICK_PERIOD_MS);
	}
}


/*!
 * \fn	void Cube::aufab(void);
 * \brief	Ebene wird erstellt und dann auf und ab geschoben.
 */

void Cube::aufab(void)
{
	ledarray aufabarray;

	ebeneOn(&aufabarray, 0);
	werteUebernehmen(&aufabarray);
	vTaskDelay(200 / portTICK_PERIOD_MS);
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
			vTaskDelay(pause / portTICK_PERIOD_MS);
		}
		pause = pause - 30;
		for (int z3 = 6; z3 >= 0; z3--)
		{
			ebeneOn(&aufabarray, z3);
			z3++;
			ebeneOff(&aufabarray, z3);
			z3--;
			werteUebernehmen(&aufabarray);
			vTaskDelay(pause / portTICK_PERIOD_MS);
		}
	}
}


/*!
 * \fn	void Cube::linksrechts(void);
 * \brief	Flaeche wird erstellt und dann von links nach rechts 
 * 			geschoben.
 */

void Cube::linksrechts(void)
{
	ledarray linksrechtsarray;

	seitlicheFlaecheOn(&linksrechtsarray, 0);
	werteUebernehmen(&linksrechtsarray);
	vTaskDelay(200 / portTICK_PERIOD_MS);
	int pause = 380;

	for (int z1 = 0; z1 <= 5; z1++)
	{
		pause = pause - 30;
		for (int z2 = 1; z2 <= 7; z2++)
		{
			seitlicheFlaecheOn(&linksrechtsarray, z2);
			z2--;
			seitlicheFlaecheOff(&linksrechtsarray, z2);
			z2++;
			werteUebernehmen(&linksrechtsarray);
			vTaskDelay(pause / portTICK_PERIOD_MS);
		}
		pause = pause - 30;
		for (int z3 = 6; z3 >= 0; z3--)
		{
			seitlicheFlaecheOn(&linksrechtsarray, z3);
			z3++;
			seitlicheFlaecheOff(&linksrechtsarray, z3);
			z3--;
			werteUebernehmen(&linksrechtsarray);
			vTaskDelay(pause / portTICK_PERIOD_MS);
		}
	}
}


/*!
 * \fn	void Cube::pingpong(void);
 * \brief	Auf oberster und unterster Flaeche werden zufaellig 
 * 			Leds eingeschaltet  bis auf beiden Flaechen 32 Leds 
 * 			leuchten. Dann wird jeweils ein Led von der unteren 
 * 			Ebene auf die obere Ebene geschoben und umgekehrt.
 */

void Cube::pingpong(void)
{
	ledarray pingpongarray;
	int x = 0;
	int y = 0;

	for (int z1 = 40; z1 >= 0; z1--)
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
	for (int z4 = 0; z4 < 300; z4++)
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
			vTaskDelay(50 / portTICK_PERIOD_MS);
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
			vTaskDelay(50 / portTICK_PERIOD_MS);
		}
	}
}


/*!
 * \fn	void Cube::snake(void);
 * \brief	Schlange die sich von oben nach unten bewegt
 * 			mit zufaelligen Richtungswechseln
 */

void Cube::snake(void)
{
	ledarray snakearray;
	int x = 3;
	int y = 3;
	int richtungxy = 0;

	snakearray.a[x][y][7] = 1;
	werteUebernehmen(&snakearray);

	for (int z1 = 0; z1 < 100; z1++)
	{
		richtungxy = random(0, 4);
		switch (richtungxy)
		{
		case 0 :	//positive x Richtung Topansicht von links nach rechts
			if (snakearray.a[7][y][6] != 1)
			{
				x++;
			} else x--;
			break;
		case 1 :	//negative x Richtung Topansicht von rechts nach links
			if (snakearray.a[0][y][6] != 1)
			{
				x--;
			} else x++;
			break;
		case 2 :	//positive y Richtung Topansicht von hinten nach vorne
			if (snakearray.a[x][7][6] != 1)
			{
				y++;
			} else y--;
			break;
		case 3 :	//negative y Richtung Topansicht von vorne nach hinten
			if (snakearray.a[x][0][6] != 1)
			{
				y--;
			} else y++;
			break;
		}
		vTaskDelay(250 / portTICK_PERIOD_MS);
		snakearray.a[x][y][7] = 1;
		werteUebernehmen(&snakearray);
		ebeneNachUnten(&snakearray);
	}


}


/*!
 * \fn	void Cube::audioanalyse(void);
 * \brief	Analysiert die 8 Audiokanaele und gibt diese dann 
 * 			auf den Wuerfel aus
 */

void Cube::audioanalyse(void)
{
	ledarray audioarray;
	int analogValues[8] = { 0 };


	for (int z = 0; z < 500; z++)
	{
		analogValues[0] = analogRead(analogPin_0);		//WErte einlesen von Analogeingaengen
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
				digitalWrite(Status2, HIGH);
				break;
			case 2:
				audioarray.a[x][7][0] = 1;
				audioarray.a[x][7][1] = 1;
				digitalWrite(Status2, HIGH);
				break;
			case 3:
				audioarray.a[x][7][0] = 1;
				audioarray.a[x][7][1] = 1;
				audioarray.a[x][7][2] = 1;
				digitalWrite(Status2, HIGH);
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
					audioarray.a[x][7][z] = 1;
				}
				break;
			default: digitalWrite(Status3, HIGH);
			}
		}
		
		werteUebernehmen(&audioarray);
		vTaskDelay(100 / portTICK_PERIOD_MS);
		ebeneNachHinten(&audioarray);
	}
}


/*!
 * \fn	int Cube::analogUmrechnung(int value);
	 * \brief	Analogwerte werden umgerechnet und die Intensitaet
	 * 			wird zurueck gegeben. Intensitaet zwischen 1 und 8
	 * \param	value	Analogwert des Eingangs
	 * \returns	An int.	Intensitaetsstufe des Signals
 */

int Cube::analogUmrechnung(int analogvalue)
{
	int signalstaerke;
	if ((analogvalue > 500)& (analogvalue < 550))
	{
		signalstaerke = 1;
	}
	if ((analogvalue >= 550) & (analogvalue < 600))
	{
		signalstaerke = 2;
	}
	if ((analogvalue >= 600) & (analogvalue < 650))
	{
		signalstaerke = 3;
	}
	if ((analogvalue >= 650) & (analogvalue < 700))
	{
		signalstaerke = 4;
	}
	if ((analogvalue >= 700) & (analogvalue < 750))
	{
		signalstaerke = 5;
	}
	if ((analogvalue >= 750) & (analogvalue < 800))
	{
		signalstaerke = 6;
	}
	if ((analogvalue >= 800) & (analogvalue < 850))
	{
		signalstaerke = 7;
	}
	if (analogvalue >= 850)
	{
		signalstaerke = 8;
	}

	return signalstaerke;
}

