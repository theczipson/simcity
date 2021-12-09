#pragma once
#include <iostream>
#include "droga.h"
#include <list>

using namespace std;

class ObiektRuchomy
{
	string rodzajObiektu;
	int polozenie_x;
	int polozenie_y;
	int porusz_x;
	int porusz_y;

public:
	ObiektRuchomy(string = "", int = 0, int = 0);
	virtual void porusz();


	friend class UFO;
	friend class SilnikGry;
	friend class Samochod;
	friend class Plansza;
};

