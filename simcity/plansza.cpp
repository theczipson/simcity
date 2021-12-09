#include "plansza.h"


Plansza::Plansza(int cIMM, int aIP, int aIZ, int aID)
{
	calkowitaIloscMiejscMieszkalnych = cIMM;
	aktualnaIloscPieniedzy = aIP;
	aktualnaIloscZelaza = aIZ;
	aktualnaIloscDrewna = aID;
	czas = time(0);
	czas2 = time(0);
	
}

void Plansza::obslugujObiektRuchomy()
{
	list <ObiektRuchomy*> nowaListaObiektowRuchomych;
	ObiektRuchomy* wsk = new ObiektRuchomy;
	for (list<ObiektRuchomy*>::iterator it = listaObiektowRuchomych.begin(); it != listaObiektowRuchomych.end(); ++it)
	{
		if (!((*it)->polozenie_x == 0 || (*it)->polozenie_y == 0))
		{
			nowaListaObiektowRuchomych.push_back(*it);
		}
		else if ((*it)->rodzajObiektu == "UFO" && ((*it)->polozenie_x == 0 || (*it)->polozenie_y == 0))
		{
			delete wsk;
			wsk = *it;
		}
	}
	delete wsk;
	listaObiektowRuchomych = nowaListaObiektowRuchomych;

	if (time(0) - czas == 10 && listaObiektowRuchomych.size() < 4)
	{
		UFO* ufo = new UFO;
		listaObiektowRuchomych.push_back(ufo);
		if (listaDrog.size() != 0)
		{
			Samochod* samochod = new Samochod(listaDrog);
			listaObiektowRuchomych.push_back(samochod);
		}
		czas = time(0);
	}	
}

void Plansza::generujObiekt(string w, int pozycja_x, int pozycja_y)
{
	bool czyCosJestNaTejPozycji = false;

	for (list<ObiektNieruchomy*>::iterator it = listaObiektow.begin(); it != listaObiektow.end(); ++it)
	{
		if ((*it)->polozenie_x == pozycja_x && (*it)->polozenie_y == pozycja_y)
		{
			czyCosJestNaTejPozycji = true;
		}
	}

	for (list<Droga*>::iterator it = listaDrog.begin(); it != listaDrog.end(); ++it)
	{
		if ((*it)->polozenie_x == pozycja_x && (*it)->polozenie_y == pozycja_y)
		{
			czyCosJestNaTejPozycji = true;
		}
	}

	if (czyCosJestNaTejPozycji == false)
	{
		if (w == "Dom")
		{
			Dom* dom = new Dom(pozycja_x, pozycja_y);

			if (dom->iloscDrewnaDoBudowy <= aktualnaIloscDrewna && dom->iloscPienidzyDoBudowy <= aktualnaIloscPieniedzy
				&& dom->iloscZelazaDoBudowy <= aktualnaIloscZelaza)
			{
				listaObiektow.push_back(dom);
				aktualnaIloscDrewna -= dom->iloscDrewnaDoBudowy;
				aktualnaIloscPieniedzy -= dom->iloscPienidzyDoBudowy;
				aktualnaIloscZelaza -= dom->iloscZelazaDoBudowy;
			}
			else
			{
				delete dom;
			}
		}
		else if (w == "Biuro")
		{
			Biuro* biuro = new Biuro(pozycja_x, pozycja_y);

			if (biuro->iloscDrewnaDoBudowy <= aktualnaIloscDrewna && biuro->iloscPienidzyDoBudowy <= aktualnaIloscPieniedzy
				&& biuro->iloscZelazaDoBudowy <= aktualnaIloscZelaza)
			{
				listaObiektow.push_back(biuro);
				aktualnaIloscDrewna -= biuro->iloscDrewnaDoBudowy;
				aktualnaIloscPieniedzy -= biuro->iloscPienidzyDoBudowy;
				aktualnaIloscZelaza -= biuro->iloscZelazaDoBudowy;
			}
			else
			{
				delete biuro;
			}
		}
		else if (w == "Tartak")
		{
			Tartak* tartak = new Tartak(pozycja_x, pozycja_y);


			if (tartak->iloscDrewnaDoBudowy <= aktualnaIloscDrewna && tartak->iloscPienidzyDoBudowy <= aktualnaIloscPieniedzy
				&& tartak->iloscZelazaDoBudowy <= aktualnaIloscZelaza)
			{
				listaObiektow.push_back(tartak);
				aktualnaIloscDrewna -= tartak->iloscDrewnaDoBudowy;
				aktualnaIloscPieniedzy -= tartak->iloscPienidzyDoBudowy;
				aktualnaIloscZelaza -= tartak->iloscZelazaDoBudowy;
			}
			else
			{
				delete tartak;
			}

		}
		else if (w == "Kopalnia")
		{
			Kopalnia* kopalnia = new Kopalnia(pozycja_x, pozycja_y);

			if (kopalnia->iloscDrewnaDoBudowy <= aktualnaIloscDrewna && kopalnia->iloscPienidzyDoBudowy <= aktualnaIloscPieniedzy
				&& kopalnia->iloscZelazaDoBudowy <= aktualnaIloscZelaza)
			{
				listaObiektow.push_back(kopalnia);
				aktualnaIloscDrewna -= kopalnia->iloscDrewnaDoBudowy;
				aktualnaIloscPieniedzy -= kopalnia->iloscPienidzyDoBudowy;
				aktualnaIloscZelaza -= kopalnia->iloscZelazaDoBudowy;
			}
			else
			{
				delete kopalnia;
			}
		}
		else if (w == "Droga")
		{
			Droga* droga = new Droga(pozycja_x, pozycja_y);
			listaDrog.push_back(droga);
			for (list<ObiektRuchomy*>::iterator it = listaObiektowRuchomych.begin(); it != listaObiektowRuchomych.end(); ++it)
			{
				Samochod* s;
				if ((*it)->rodzajObiektu == "Samochod")
				{
					s = dynamic_cast<Samochod*>(*it);
					s->updateDrog(listaDrog);
				}
			}
		}
	}
}

void Plansza::pogorszenieStanuObiektow()
{
	for (list<ObiektNieruchomy*>::iterator it = listaObiektow.begin(); it != listaObiektow.end(); ++it)
	{
		(*it)->pogorszenieStanu();
	}
}

void Plansza::naprawObiekt(int pozycja_x, int pozycja_y, int& aktualnaIloscPieniedzy)
{
	for (list<ObiektNieruchomy*>::iterator it = listaObiektow.begin(); it != listaObiektow.end(); ++it)
	{
		if ((*it)->polozenie_x == pozycja_x && (*it)->polozenie_y == pozycja_y)
		{
			(*it)->napraw(aktualnaIloscPieniedzy);
		}
	}
}

void Plansza::usunObiekt(int pozycja_x, int pozycja_y)
{
	list <ObiektNieruchomy*> nowaListaObiektow;
	ObiektNieruchomy* doUsuniecia = new ObiektNieruchomy;
	for (list<ObiektNieruchomy*>::iterator it = listaObiektow.begin(); it != listaObiektow.end(); ++it)
	{
		if (!((*it)->polozenie_x == pozycja_x && (*it)->polozenie_y == pozycja_y))
		{
			nowaListaObiektow.push_back(*it);
		}
		else if ((*it)->polozenie_x == pozycja_x && (*it)->polozenie_y == pozycja_y && (*it)->rodzajObiektu == "Dom")
		{
			Dom* dom = new Dom;
			delete doUsuniecia;
			doUsuniecia = *it;
			calkowitaIloscMiejscMieszkalnych -= dom->iloscMiejscMieszkalnych;
			delete dom;
		}
		else if ((*it)->polozenie_x == pozycja_x && (*it)->polozenie_y == pozycja_y)
		{
			delete doUsuniecia;
			doUsuniecia = *it;
		}
	}
	delete doUsuniecia;
	listaObiektow = nowaListaObiektow;

	Droga* drogaDoUsuniecia = new Droga;
	list <Droga*> nowaListaDrog;
	for (list<Droga*>::iterator it = listaDrog.begin(); it != listaDrog.end(); ++it)
	{
		if (!((*it)->polozenie_x == pozycja_x && (*it)->polozenie_y == pozycja_y))
		{
			nowaListaDrog.push_back(*it);
		}
		else
		{
			delete drogaDoUsuniecia;
			drogaDoUsuniecia = *it;
		}
	}
	listaDrog = nowaListaDrog;
	delete drogaDoUsuniecia;
}

void Plansza::generujZasoby()
{
	for (list<ObiektNieruchomy*>::iterator it = listaObiektow.begin(); it != listaObiektow.end(); ++it)
	{
		Dom* d;
		Kopalnia* k;
		Tartak* t;
		Biuro* b;
		if ((*it)->rodzajObiektu == "Dom")
		{
			d = static_cast<Dom*>(*it);
			d->generujMiejscaMieszkalne(calkowitaIloscMiejscMieszkalnych);
		}
		else if ((*it)->rodzajObiektu == "Kopalnia")
		{
			k = static_cast<Kopalnia*>(*it);
			k->generujZelazo(aktualnaIloscZelaza);
		}
		else if ((*it)->rodzajObiektu == "Tartak")
		{
			t = static_cast<Tartak*>(*it);
			t->generujDrewno(aktualnaIloscDrewna);
		}
		else if ((*it)->rodzajObiektu == "Biuro")
		{
			b = static_cast<Biuro*>(*it);
			b->generujZloto(aktualnaIloscPieniedzy);
		}
	}
}

void Plansza::obslugujMieszkanca()
{
	int ilosc = listaMieszkancow.size();
	if (ilosc > 0)
	{
		if (time(0) - czas2 == 15 && ilosc < calkowitaIloscMiejscMieszkalnych)
		{
			Mieszkaniec* mieszkaniec = new Mieszkaniec;
			listaMieszkancow.push_back(mieszkaniec);
			czas2 = time(0);
		}
	}
	else if (ilosc == 0 && calkowitaIloscMiejscMieszkalnych > 0)
	{
		Mieszkaniec* mieszkaniec = new Mieszkaniec;
		listaMieszkancow.push_back(mieszkaniec);
		czas2 = time(0);
	}

	int i = 1;
	for (list<Mieszkaniec*>::iterator it = listaMieszkancow.begin(); it != listaMieszkancow.end(); ++it)
	{
		(*it)->zmianaZamieszkania(i, calkowitaIloscMiejscMieszkalnych);
		i++;
		(*it)->zmienZadowolenie();
	}
}
