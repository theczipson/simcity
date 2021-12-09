#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Mieszkaniec
{
	int zadowolenie;
	bool czyMaGdzieMieszkac;
	int czasPrzybycia;
public:
	Mieszkaniec(int = 50);
	void zmienZadowolenie();
	void zmianaZamieszkania(int, int);

	friend class Plansza;
};

