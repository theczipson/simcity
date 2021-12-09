#include "silnikGry.h"
#include <iostream>

using namespace sf;
using namespace std;

SilnikGry::SilnikGry()
{
	czasRozpoczecia = time(0);
	planszaDoGry = new Plansza;
}

void SilnikGry::graj()
{
	RenderWindow okno(VideoMode(1350, 1000), "Symulator Miasta");
	okno.setFramerateLimit(60);

	Event zdarzenie;

	int gdzieKliknietoPPM_x = 0, gdzieKliknietoPPM_y = 0;
	bool czyCosJestNaTejPozycji = false;
	bool czyDrogaJestNaTejPozycji = false;
	int ileProstokatowBudowyNieZawieraMyszki, ileProstokatowAkcjiNieZawieraMyszki;


	while (okno.isOpen())
	{
		planszaDoGry -> obslugujObiektRuchomy();
		planszaDoGry -> obslugujMieszkanca();
		planszaDoGry -> generujZasoby();
		planszaDoGry -> pogorszenieStanuObiektow();

		for (list<ObiektNieruchomy*>::iterator it = planszaDoGry -> listaObiektow.begin(); it != planszaDoGry -> listaObiektow.end(); ++it)
		{
			for (int i = 0; i < 5; i++)
			{
				if ((*it)->rodzajObiektu == napisy[i])
				{
					tekstury[i].setPosition((*it)->polozenie_x, (*it)->polozenie_y);
					okno.draw(tekstury[i]);
				}
			}
		}

		iloscMieszkancow.setString(to_string(planszaDoGry->listaMieszkancow.size()));
		okno.draw(iloscMieszkancow);

		for (list<Droga*>::iterator it = planszaDoGry -> listaDrog.begin(); it != planszaDoGry -> listaDrog.end(); ++it)
		{
			if ((*it)->czyMaPasy == false)
			{
				tekstury[4].setPosition((*it)->polozenie_x, (*it)->polozenie_y);
				okno.draw(tekstury[4]);
			}
			else if ((*it)->czyMaPasy == true)
			{
				tekstury[5].setPosition((*it)->polozenie_x, (*it)->polozenie_y);
				okno.draw(tekstury[5]);
			}
		}


		napisyAktualneZasoby[0].setString(aktualneZasoby[0] + to_string(planszaDoGry -> aktualnaIloscPieniedzy));
		napisyAktualneZasoby[1].setString(aktualneZasoby[1] + to_string(planszaDoGry -> aktualnaIloscDrewna));
		napisyAktualneZasoby[2].setString(aktualneZasoby[2] + to_string(planszaDoGry -> aktualnaIloscZelaza));
		napisyAktualneZasoby[3].setString(aktualneZasoby[3] + to_string(planszaDoGry -> calkowitaIloscMiejscMieszkalnych));
		for (int i = 0; i < 4; i++)
		{
			okno.draw(napisyAktualneZasoby[i]);
		}

		while (okno.pollEvent(zdarzenie))
		{
			//zamykanie okna
			if (zdarzenie.type == Event::Closed)
			{
				okno.close();
				break;
			}
		}

		if (Mouse::getPosition(okno).x >= 0 && Mouse::getPosition(okno).x <= 1000
			&& Mouse::getPosition(okno).y >= 0 && Mouse::getPosition(okno).x <= 1000)
		{
			if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Right)
			{
				gdzieKliknietoPPM_x = Mouse::getPosition(okno).x;
				gdzieKliknietoPPM_y = Mouse::getPosition(okno).y;

				for (list<ObiektNieruchomy*>::iterator it = planszaDoGry -> listaObiektow.begin(); it != planszaDoGry -> listaObiektow.end(); ++it)
				{
					if ((*it)->polozenie_x == gdzieKliknietoPPM_x - (gdzieKliknietoPPM_x % 100)
						&& (*it)->polozenie_y == gdzieKliknietoPPM_y - (gdzieKliknietoPPM_y % 100))
					{
						czyCosJestNaTejPozycji = true;
					}
				}
				for (list<Droga*>::iterator it = planszaDoGry -> listaDrog.begin(); it != planszaDoGry -> listaDrog.end(); ++it)
				{
					if ((*it)->polozenie_x == gdzieKliknietoPPM_x - (gdzieKliknietoPPM_x % 100)
						&& (*it)->polozenie_y == gdzieKliknietoPPM_y - (gdzieKliknietoPPM_y % 100))
					{
						czyDrogaJestNaTejPozycji = true;
					}
				}
				if (czyCosJestNaTejPozycji == false && czyDrogaJestNaTejPozycji == false)
				{
					for (int i = 0; i < 5; i++)
					{
						prostokatWyboruBudowy[i].setPosition(gdzieKliknietoPPM_x - 10, i * 30 + gdzieKliknietoPPM_y - 10);
						napisyWyboruBudowy[i].setPosition(gdzieKliknietoPPM_x + 20, i * 30 + gdzieKliknietoPPM_y);
					}
				}
				else if (czyCosJestNaTejPozycji == true && czyDrogaJestNaTejPozycji == false)
				{
					for (int i = 0; i < 2; i++)
					{
						prostokatAkcjiObiektu[i].setPosition(gdzieKliknietoPPM_x - 10, i * 30 + gdzieKliknietoPPM_y - 10);
						napisyAkcjiObiektu[i].setPosition(gdzieKliknietoPPM_x + 20, i * 30 + gdzieKliknietoPPM_y);
					}
				}
				else if (czyCosJestNaTejPozycji == false && czyDrogaJestNaTejPozycji == true)
				{
					prostokatAkcjiObiektu[1].setPosition(gdzieKliknietoPPM_x - 10, gdzieKliknietoPPM_y - 10);
					napisyAkcjiObiektu[1].setPosition(gdzieKliknietoPPM_x + 20, gdzieKliknietoPPM_y);
				}
			}
		}

		if (Mouse::getPosition(okno).x >= 0 && Mouse::getPosition(okno).x <= 1000
			&& Mouse::getPosition(okno).y >= 0 && Mouse::getPosition(okno).x <= 1000)
		{
			for (list<ObiektNieruchomy*>::iterator it = planszaDoGry -> listaObiektow.begin(); it != planszaDoGry -> listaObiektow.end(); ++it)
			{
				if ((*it)->polozenie_x == Mouse::getPosition(okno).x - (Mouse::getPosition(okno).x % 100)
					&& (*it)->polozenie_y == Mouse::getPosition(okno).y - (Mouse::getPosition(okno).y % 100))
				{
					napisyDaneObiektu[0].setString(daneObiektu[0] + (*it)->rodzajObiektu);
					napisyDaneObiektu[1].setString(daneObiektu[1] + to_string((*it)->stan));
					for (int j = 0; j < 2; j++)
					{
						okno.draw(napisyDaneObiektu[j]);
					}
				}
			}
		}

		ileProstokatowBudowyNieZawieraMyszki = 0;
		for (int i = 0; i < 5; i++)
		{
			if (prostokatWyboruBudowy[i].getGlobalBounds().contains(Mouse::getPosition(okno).x, Mouse::getPosition(okno).y))
			{
				prostokatWyboruBudowy[i].setFillColor(Color::Red);
				for (int j = 0; j < 5; j++)
				{
					okno.draw(prostokatWyboruBudowy[j]);
					okno.draw(napisyWyboruBudowy[j]);
				}

				if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left)
				{
					prostokatWyboruBudowy[i].setPosition(-300, -300);
					napisyWyboruBudowy[i].setPosition(-300, -300);
					planszaDoGry -> generujObiekt(napisy[i],
						gdzieKliknietoPPM_x - (gdzieKliknietoPPM_x % 100), gdzieKliknietoPPM_y - (gdzieKliknietoPPM_y % 100));
				}
			}
			else
			{
				prostokatWyboruBudowy[i].setFillColor(Color::Black);
				ileProstokatowBudowyNieZawieraMyszki++;
			}
		}
		if (ileProstokatowBudowyNieZawieraMyszki == 5)
		{
			for (int i = 0; i < 5; i++)
			{
				prostokatWyboruBudowy[i].setPosition(-300, -300);
				napisyWyboruBudowy[i].setPosition(-300, -300);
			}
			czyCosJestNaTejPozycji = false;
			czyDrogaJestNaTejPozycji = false;
		}

		ileProstokatowAkcjiNieZawieraMyszki = 0;
		for (int i = 0; i < 2; i++)
		{
			if (prostokatAkcjiObiektu[i].getGlobalBounds().contains(Mouse::getPosition(okno).x, Mouse::getPosition(okno).y))
			{
				prostokatAkcjiObiektu[i].setFillColor(Color::Red);
				for (int j = 0; j < 2; j++)
				{
					okno.draw(prostokatAkcjiObiektu[j]);
					okno.draw(napisyAkcjiObiektu[j]);
				}

				if (zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Left)
				{
					if (i == 1)
					{
						planszaDoGry -> usunObiekt(gdzieKliknietoPPM_x - (gdzieKliknietoPPM_x % 100), gdzieKliknietoPPM_y - (gdzieKliknietoPPM_y % 100));
					}
					else if (i == 0)
					{
						planszaDoGry -> naprawObiekt(gdzieKliknietoPPM_x - (gdzieKliknietoPPM_x % 100), gdzieKliknietoPPM_y - (gdzieKliknietoPPM_y % 100),
							planszaDoGry -> aktualnaIloscPieniedzy);
					}

					prostokatAkcjiObiektu[i].setPosition(-300, -300);
					napisyAkcjiObiektu[i].setPosition(-300, -300);
				}
			}
			else
			{
				prostokatAkcjiObiektu[i].setFillColor(Color::Black);
				ileProstokatowAkcjiNieZawieraMyszki++;
			}
		}
		if (ileProstokatowAkcjiNieZawieraMyszki == 2)
		{
			for (int i = 0; i < 2; i++)
			{
				prostokatAkcjiObiektu[i].setPosition(-300, -300);
				napisyAkcjiObiektu[i].setPosition(-300, -300);
			}
			czyCosJestNaTejPozycji = false;
			czyDrogaJestNaTejPozycji = false;
		}
		for (list<ObiektRuchomy*>::iterator it = planszaDoGry -> listaObiektowRuchomych.begin(); it != planszaDoGry -> listaObiektowRuchomych.end(); ++it)
		{
			(*it)->porusz();
			if ((*it)->rodzajObiektu == "UFO")
			{
				ufoTekstura.setPosition((*it)->polozenie_x, (*it)->polozenie_y);
				okno.draw(ufoTekstura);
			}
			else if ((*it)->rodzajObiektu == "Samochod")
			{
				samochodzikTekstura.setPosition((*it)->polozenie_x, (*it)->polozenie_y);
				okno.draw(samochodzikTekstura);
			}
		}

		okno.display();
	}
}