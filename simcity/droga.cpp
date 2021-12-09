#include "droga.h"
#include <cstdlib>
#include <ctime>

Droga::Droga(int px, int py, string rO)
{
	rodzajObiektu = rO;
	polozenie_x = px;
	polozenie_y = py;

	srand(time(NULL));
	float los = (rand() % 11);

	if (los <= 2)
	{
		czyMaPasy = true;
	}
	else
	{
		czyMaPasy = false;
	}
}