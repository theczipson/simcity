#include "mieszkaniec.h"


Mieszkaniec::Mieszkaniec(int zad)
{
	czasPrzybycia = time(0);
	zadowolenie = zad;
	czyMaGdzieMieszkac = false;
}

void Mieszkaniec::zmianaZamieszkania(int iloscMieszkancow, int iloscMiejscMieszkalnych)
{
	if (iloscMiejscMieszkalnych >= iloscMieszkancow)
	{
		czyMaGdzieMieszkac = true;
	}
	else
	{
		czyMaGdzieMieszkac = false;
	}
}

void Mieszkaniec::zmienZadowolenie()
{
	if ((czasPrzybycia - time(0)) % 10 == 0)
	{
		if (zadowolenie < 100 && czyMaGdzieMieszkac == true)
		{
			zadowolenie += 3;
			if (zadowolenie > 100)
			{
				zadowolenie = 100;
			}
		}
		else if (zadowolenie > 0 && czyMaGdzieMieszkac == false)
		{
			zadowolenie -3;
			if (zadowolenie < 0)
			{
				zadowolenie = 0;
			}
		}
	}
}