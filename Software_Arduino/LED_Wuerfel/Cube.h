// Cube.h

#ifndef _CUBE_h
#define _CUBE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
	
class Cube
{
public:
	struct ledarray		//Grundarray um Werte für die Ausgabe zu bestimmen
	{
		char a[8][8][8] = { {{ 0 }} };
	};
	//constructor

	//methods
	void initIO(void);		//Initialisierung der IOs
	void ausgabe(void);		//fortlaufende Ausgabe auf den Cube
	void werteUebernehmen(struct ledarray* struct_ptr);
	void einschalten(void);
	void ausschalten(void);
	void ebeneOn(struct ledarray* struct_ptr, int i);
	void ebeneOff(struct ledarray* struct_ptr, int i);
	void ebeneNachUnten(struct ledarray* struct_ptr);
	void ebeneNachOben(struct ledarray* struct_ptr);
	void ebeneNachHinten(struct ledarray* struct_ptr); //Noch nicht getestet
	void rain(void);
	void zufall(void);
	void strobo(void);
	void aufab(void);
	void pingpong(void);		//Noch nicht getestet
	void snake(void);			//Noch nicht getestet
	void gegenpyramide(void);	//Noch nicht implementiert
	void audioanalyse(void);		//Noch nicht getestet
	int analogUmrechnung(int value);	//Noch nicht getestet
	//void audioAusgabe(void);	//Noch nicht getestet

private:
	int L1 = 22;//Ausgabewerte für jeweils 8 Leds
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

	int ENABLE = 46;		//Schaltet die Latches frei für Ausgabe

	int Schalter1 = 47;		//Schalter zur Funktionsauswahl
	int Schalter2 = 48;
	int Schalter3 = 49;
	//int Schalter4 = 50;

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

	char ledaktvalue[8][8][8] = { {{0}} };
};

void cube_initTimerEvent(Cube* obj);

#endif

