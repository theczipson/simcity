#include "grafika.h"

Grafika::Grafika()
{
	Texture obraz;
	obraz.loadFromFile("./obrazki/trawa.jpg");
	tlo.setPosition(0, 0);

	Texture obiekty[6];
	obiekty[0].loadFromFile("./obrazki/dom.jpg");
	obiektyNieruchome[0].setTexture(obiekty[0]);
	obiekty[1].loadFromFile("./obrazki/tartak.jpg");
	obiektyNieruchome[1].setTexture(obiekty[1]);
	obiekty[2].loadFromFile("./obrazki/kopalnia.jpg");
	obiektyNieruchome[2].setTexture(obiekty[2]);
	obiekty[3].loadFromFile("./obrazki/biuro.jpg");
	obiektyNieruchome[3].setTexture(obiekty[3]);
	obiekty[4].loadFromFile("./obrazki/droga.jpg");
	obiektyNieruchome[4].setTexture(obiekty[4]);
	obiekty[5].loadFromFile("./obrazki/pasy.jpg");
	obiektyNieruchome[5].setTexture(obiekty[5]);

	Texture ufo;
	ufo.loadFromFile("./obrazki/ufo.png");
	obiektyRuchome[0].setTexture(ufo);
	Texture samochodzik;
	samochodzik.loadFromFile("./obrazki/samochod.png");
	obiektyRuchome[1].setTexture(samochodzik);

	Vector2f rozmiarPrzycisku(150, 30);
	for (int i = 0; i < 5; i++)
	{
		prostokatWyboruBudowy[i].setSize(rozmiarPrzycisku);
		prostokatWyboruBudowy[i].setFillColor(Color::Black);
	}
	for (int i = 0; i < 2; i++)
	{
		prostokatAkcjiObiektu[i].setSize(rozmiarPrzycisku);
		prostokatAkcjiObiektu[i].setFillColor(Color::Black);
	}

	czcionka.loadFromFile("./czcionka/ALGER.TTF");

	string napisy[5] = { "Dom", "Tartak", "Kopalnia", "Biuro", "Droga" };
	string napisyAkcji[2] = { "Napraw", "Usun" };

	for (int i = 0; i < 5; i++)
	{
		napisyWyboruBudowy[i].setFont(czcionka);
		napisyWyboruBudowy[i].setString(napisy[i]);
		napisyWyboruBudowy[i].setCharacterSize(15);
		napisyWyboruBudowy[i].setFillColor(Color::White);
	}

	for (int i = 0; i < 2; i++)
	{
		napisyAkcjiObiektu[i].setFont(czcionka);
		napisyAkcjiObiektu[i].setString(napisyAkcji[i]);
		napisyAkcjiObiektu[i].setCharacterSize(15);
		napisyAkcjiObiektu[i].setFillColor(Color::White);
	}

	string aktualneZasoby[6] = { "Ilosc zlota: ", "Ilosc drewna: ", "Ilosc zelaza: ", "Ilosc miejsc mieszkalnych: ", "Ilosc mieszkancow: ", "Zadowolenie: " };
	for (int i = 0; i < 5; i++)
	{
		napisyAktualneZasoby[i].setFont(czcionka);
		napisyAktualneZasoby[i].setCharacterSize(20);
		napisyAktualneZasoby[i].setFillColor(Color::White);
		napisyAktualneZasoby[i].setPosition(1005, 20 + i * 20);
	}

	string daneObiektu[2] = { "Nazwa: ", "Stan: " };
	for (int i = 0; i < 2; i++)
	{
		napisyDaneObiektu[i].setFont(czcionka);
		napisyDaneObiektu[i].setCharacterSize(20);
		napisyDaneObiektu[i].setFillColor(Color::White);
		napisyDaneObiektu[i].setPosition(1005, 140 + i * 20);
	}
}

void Grafika::wyswietlTlo(RenderWindow& w)
{
	w.clear(Color(128, 128, 128));
	w.draw(tlo);
}

void Grafika::wyswietlObiektyNieruchome(RenderWindow& w)
{

}