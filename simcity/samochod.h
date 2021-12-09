#pragma once
#include <iostream>
#include "obiektRuchomy.h"
#include "obiektNieruchomy.h"
#include <list>
#include "silnikGry.h"
#include "droga.h"

using namespace std;

class Samochod : public ObiektRuchomy
{
	list <Droga*> gdzieMoznaPoruszyc;
public:
	Samochod(list <Droga*>, int = 0, int = 0, string = "Samochod");
	void porusz();
	void updateDrog(list <Droga*>);

	friend class SilnikGry;
	friend class Plansza;
	friend class ObiektRuchomy;
};

