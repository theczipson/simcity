#pragma once
#include <SFML\Graphics.hpp>
#include "plansza.h"
#include <iostream>
#include <list>

using namespace std;

class SilnikGry
{
	int czasRozpoczecia;
	Plansza* planszaDoGry;

public:
	SilnikGry();
	void graj();
};

