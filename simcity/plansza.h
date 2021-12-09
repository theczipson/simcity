#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <list>
#include "obiektNieruchomy.h"
#include "obiektRuchomy.h"
#include "droga.h"
#include "dom.h"
#include "biuro.h"
#include "tartak.h"
#include "kopalnia.h"
#include "UFO.h"
#include "samochod.h"
#include "mieszkaniec.h"

using namespace std;

class Plansza
{
	list <Mieszkaniec*> listaMieszkancow;
	list <ObiektRuchomy*> listaObiektowRuchomych;
	list <ObiektNieruchomy*> listaObiektow;
	list <Droga*> listaDrog;
	int calkowitaIloscMiejscMieszkalnych;
	int aktualnaIloscPieniedzy;
	int aktualnaIloscZelaza;
	int aktualnaIloscDrewna;
	int czas;
	int czas2;

public:
	Plansza(int = 0, int = 0, int = 0, int = 0);
	void generujObiekt(string, int, int);
	void usunObiekt(int, int);
	void naprawObiekt(int, int, int&);
	void pogorszenieStanuObiektow();
	void generujZasoby();
	void obslugujObiektRuchomy();
	void obslugujMieszkanca();

	friend class SilnikGry;
};