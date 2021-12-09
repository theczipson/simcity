#pragma once
#include <iostream>

using namespace std;

class Droga
{
	string rodzajObiektu;
	int polozenie_x;
	int polozenie_y;
	bool czyMaPasy;

public:
	Droga(int = 0, int = 0, string = "Droga");

	friend class Plansza;
	friend class SilnikGry;
	friend class Samochod;
};

