#pragma once
#include <iostream>

using namespace std;

class ObiektNieruchomy
{
	string rodzajObiektu;
	int polozenie_x;
	int polozenie_y;
	int stan;
	int iloscPienidzyDoBudowy;
	int iloscDrewnaDoBudowy;
	int iloscZelazaDoBudowy;
	int czasDoPogorszeniaStanu;
	int czasDoProdukcji;
	int trwalosc;
	int czasProdukcji;
	int kosztNaprawyOJedenStan;

public:
	ObiektNieruchomy(int = 0, int = 0, string = " ", int = 0, int = 0, int = 0, int = 0, int = 0, int = 0, int = 0);
	void pogorszenieStanu();
	void napraw(int&);


	friend class Plansza;
	friend class SilnikGry;
	friend class Biuro;
	friend class Dom;
	friend class Kopalnia;
	friend class Tartak;
};

