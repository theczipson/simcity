#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;

class Grafika
{
	Sprite tlo;
	Sprite obiektyNieruchome[6];
	Sprite obiektyRuchome[2];
	RectangleShape prostokatWyboruBudowy[5];
	RectangleShape prostokatAkcjiObiektu[2];
	Font czcionka;
	Text napisyWyboruBudowy[5];
	Text napisyAkcjiObiektu[2];
	Text napisyAktualneZasoby[6];
	Text napisyDaneObiektu[2];

public:
	Grafika();
	void wyswietlTlo(RenderWindow&);
	void wyswietlObiektyNieruchome(RenderWindow&)
};

