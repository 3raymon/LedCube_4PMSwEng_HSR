/*!
 *	\file			Cube.h
 *	\date			erstellt: 04.10.2019
 *	\author			Michael Guntli
 *	\version		1.1
 *	\date			berarbeitet: 15.11.2019
 *	\brief			Headerfile mit saemtlichen Funktionen fuer die Steuerung des LED-Cube
 */

#ifndef _CUBE_h
#define _CUBE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

/*!
 * \class	Cube
 * \brief	Saemtliche Funktionen fuer die Steuerung des LED-Cube
 */

class Cube
{
public:

	/*!
	 * \struct	ledarray
	 * \brief	Grundarray um Werte fuer die Ausgabe zu bestimmen
	 */

	struct ledarray	
	{
		char a[8][8][8] = { {{ 0 }} };
	};


	/*!
	 * \fn	void Cube::initIO(void);
	 * \brief	Initialisierung der IOs 
	 */

	void initIO(void);	


	/*!
	 * \fn	void Cube::ausgabe(void);
	 * \brief	fortlaufende Ausgabe auf den Cube
	 */

	void ausgabe(void);		


	/*!
	 * \fn	void Cube::werteUebernehmen(struct ledarray* struct_ptr);
	 * \brief	Werte werden in das Ausgabe Array kopiert und somit 
	 * 			bei der naechsten Ausgabe auf dem Cube dargestellt.
	 * \param [in,out]	struct_ptr Pointer auf zu bearbeitendes Array
	 */

	void werteUebernehmen(struct ledarray* struct_ptr);


	/*!
	 * \fn	void Cube::einschalten(void);
	 * \brief	Einschalten des gesamten Wuerfels
	 */

	void einschalten(void);


	/*!
	 * \fn	void Cube::ausschalten(void);
	 * \brief	Ausschalten des gesamten Wuerfels
	 */

	void ausschalten(void);


	/*!
	 * \fn	void Cube::ebeneOn(struct ledarray* struct_ptr, int i);
	 * \brief	Einzelne Ebene kann eingestellt werden, mit der int 
	 * 			Variable wird die Ebene gewaehlt 0 bis 7 
	 * 			0 bedeutet unterster Layer 7 oberster
	 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
	 * \param 		  	ebene		  	Auswahl der Ebene
	 */

	void ebeneOn(struct ledarray* struct_ptr, int ebene);


	/*!
	 * \fn	void Cube::ebeneOff(struct ledarray* struct_ptr, int i);
	 * \brief	Einzelne Ebene kann ausgeschaltet werden, mit der int 
	 * 			Variable wird die Ebene gewaehlt 0 bis 7 
	 * 			0 bedeutet unterster Layer 7 oberster	
	 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
	 * \param 		  	ebene		  	Auswahl der Ebene
	 */

	void ebeneOff(struct ledarray* struct_ptr, int ebene);


	/*!
	 * \fn	void Cube::ebeneNachUnten(struct ledarray* struct_ptr);
	 * \brief	Schiebt gesamten Cube um eine Ebene nach unten
	 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
	 */

	void ebeneNachUnten(struct ledarray* struct_ptr);


	/*!
	 * \fn	void Cube::ebeneNachOben(struct ledarray* struct_ptr);
	 * \brief	Schiebt gesamten Cube um eine Ebene nach oben.
	 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
	 */

	void ebeneNachOben(struct ledarray* struct_ptr);


	/*!
	 * \fn	void Cube::ebeneNachHinten(struct ledarray* struct_ptr);
	 * \brief	Schiebt gesamten Cube um eine Ebene nach hinten.
	 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
	 */

	void ebeneNachHinten(struct ledarray* struct_ptr);	//Noch nicht getestet


	/*!
	 * \fn	void Cube::ebeneNachVorne(struct ledarray* struct_ptr);
	 * \brief	Schiebt gesamten Cube um eine Ebene nach vorne.
	 * \param [in,out]	structptr	Pointer auf zu bearbeitendes Array
	 */

	void ebeneNachVorne(struct ledarray* struct_ptr);	//Noch nicht getestet


	/*!
	 * \fn	void Cube::ebeneNachLinks(struct ledarray* struct_ptr);
	 * \brief	Schiebt gesamten Cube um eine Ebene nach links.
	 * \param [in,out]	structptr	Pointer auf zu bearbeitendes Array
	 */

	void ebeneNachLinks(struct ledarray* struct_ptr);	//Noch nicht getestet


	/*!
	 * \fn	void Cube::ebeneNachRechts(struct ledarray* struct_ptr);
	 * \brief	Schiebt gesamten Cube um eine Ebene nach rechts.
	 * \param [in,out]	structptr	Pointer auf zu bearbeitendes Array
	 */

	void ebeneNachRechts(struct ledarray* struct_ptr);	//Noch nicht getestet


	/*!
	 * \fn	void Cube::seitlicheFlaecheOn(struct ledarray* struct_ptr, int i);
	 * \brief	Einzelne Flaeche(von vorne nach hinten) kann eingeschaltet werden, 
	 * 			mit der int	Variable wird die Flaeche gewaehlt 0 bis 7 
	 * 			0 bedeutet ganz linke Flaeche, 7 ganz rechts
	 * \param [in,out]	struct_ptr	Pointer auf zu berarbeitendes Array
	 * \param 		  	flaeche		  	Auswahl der Flaeche
	 */

	void seitlicheFlaecheOn(struct ledarray* struct_ptr, int flaeche);	//Noch nicht getestet


	/*!
	 * \fn	void Cube::seitlicheFlaecheOff(struct ledarray* struct_ptr, int i);
	 * \brief	Einzelne Flaeche(von vorne nach hinten) kann ausgeschaltet werden, 
	 * 			mit der int	Variable wird die Flaeche gewaehlt 0 bis 7 
	 * 			0 bedeutet ganz linke Flaeche, 7 ganz rechts
	 * \param [in,out]	struct_ptr	Pointer auf zu bearbeitendes Array
	 * \param 		  	flaeche		  	Auswahl der Flaeche
	 */

	void seitlicheFlaecheOff(struct ledarray* struct_ptr, int flaeche);	//Noch nicht getestet


	/*!
	 * \fn	void Cube::rain(void);
	 * \brief	Regen Funktion
	 */

	void rain(void);


	/*!
	 * \fn	void Cube::zufall(void);
	 * \brief	Zufaelliges ein und ausschalten von Leds
	 */

	void zufall(void);


	/*!
	 * \fn	void Cube::pyramide(void);
	 * \brief	Pyramide die sich von unten nach oben aufbaut
	 * 			und dann wieder abbaut.
	 */

	void pyramide(void);	//Noch nicht implementiert


	/*!
	 * \fn	void Cube::strobo(void);
	 * \brief	Strobo mit saemtlichen Leds
	 */

	void strobo(void);


	/*!
	 * \fn	void Cube::aufab(void);
	 * \brief	Ebene wird erstellt und dann auf und ab geschoben.
	 */

	void aufab(void);


	/*!
	 * \fn	void Cube::linksrechts(void);
	 * \brief	Flaeche wird erstellt und dann von links nach rechts 
	 * 			geschoben.
	 */

	void linksrechts(void);		//Noch nicht getestet


	/*!
	 * \fn	void Cube::pingpong(void);
	 * \brief	Auf oberster und unterster Flaeche werden zufaellig 
	 * 			Leds eingeschaltet  bis auf beiden Flaechen 32 Leds 
	 * 			leuchten. Dann wird jeweils ein Led von der unteren 
	 * 			Ebene auf die obere Ebene geschoben und umgekehrt.
	 */

	void pingpong(void);	


	/*!
	 * \fn	void Cube::snake(void);
	 * \brief	Schlange die sich von oben nach unten bewegt
	 * 			mit zufaelligen Richtungswechseln
	 */

	void snake(void);			//Noch nicht getestet


	/*!
	 * \fn	void Cube::audioanalyse(void);
	 * \brief	Analysiert die 8 Audiokanaele und gibt diese dann 
	 * 			auf den Wuerfel aus
	 */

	void audioanalyse(void);	


	/*!
	 * \fn	int Cube::analogUmrechnung(int value);
	 * \brief	Analogwerte werden umgerechnet und die Intensitaet
	 * 			wird zurueck gegeben. Intensitaet zwischen 1 und 8
	 * \param	value	Analogwert des Eingangs
	 * \returns	An int.	Intensitaetsstufe des Signals
	 */

	int analogUmrechnung(int value);

private:
	/*! \brief	Ausgabewerte fuer jeweils 8 Leds. */
	int L1 = 22;
	int L2 = 23;
	int L3 = 24;
	int L4 = 25;
	int L5 = 26;
	int L6 = 27;
	int L7 = 28;
	int L8 = 29;

	/*! \summary	Auswahl der Reihen einer Ebene. */
	int CLK1 = 30;
	int CLK2 = 31;
	int CLK3 = 32;
	int CLK4 = 33;
	int CLK5 = 34;
	int CLK6 = 35;
	int CLK7 = 36;
	int CLK8 = 37;

	/*! \summary	Auswahl der aktiven Ebene. */
	int Ebene1 = 38;
	int Ebene2 = 39;
	int Ebene3 = 40;
	int Ebene4 = 41;
	int Ebene5 = 42;
	int Ebene6 = 43;
	int Ebene7 = 44;
	int Ebene8 = 45;

	/*! \summary	Schaltet die Latches frei fuer Ausgabe. */
	int ENABLE = 46;

	/*! \summary	Schalter zur Funktionsauswahl. */
	int Schalter1 = 47;
	int Schalter2 = 48;
	int Schalter3 = 49;
	int Schalter4 = 50;

	/*! \summary	Status Leds zur Anzeige welcher Modus gewaehlt ist. */
	int Status1 = 51;
	int Status2 = 52;
	int Status3 = 53;

	/*! \summary	Analogeingaenge fuer die Bandpassfilter. */
	int analogPin_0 = A0;
	int analogPin_1 = A1;
	int analogPin_2 = A2;
	int analogPin_3 = A3;
	int analogPin_4 = A4;
	int analogPin_5 = A5;
	int analogPin_6 = A6;
	int analogPin_7 = A7;

	/*! \summary	Array das zur staendigen Ausgabe verwendet wird */
	char ledaktvalue[8][8][8] = { {{0}} };
};

#endif

