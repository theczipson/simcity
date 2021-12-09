#include "obiektNieruchomy.h"
#include <iostream>
#include <time.h>

ObiektNieruchomy::ObiektNieruchomy(int px, int py, string rO, int s, int iPDB, int iDDB, int iZDB, int trw, int cP, int kNOJS)
{
	rodzajObiektu = rO;
	polozenie_x = px;
	polozenie_y = py;
	stan = s;
	iloscPienidzyDoBudowy = iPDB;
	iloscDrewnaDoBudowy = iDDB;
	iloscZelazaDoBudowy = iZDB;
	trwalosc = trw;
	czasProdukcji = cP;
	kosztNaprawyOJedenStan = kNOJS;

	czasDoPogorszeniaStanu = time(0);
	czasDoProdukcji = time(0);
}

void ObiektNieruchomy::pogorszenieStanu()
{
	if ((time(0) - czasDoPogorszeniaStanu) >= trwalosc)
	{
		stan--;
		czasDoPogorszeniaStanu = time(0);
	}
}

void ObiektNieruchomy::napraw(int& Pieniadze)
{
	int iloscPieniedzyDoNaprawy = (10 - stan) * kosztNaprawyOJedenStan;
	if (Pieniadze >= iloscPieniedzyDoNaprawy)
	{
		Pieniadze -= iloscPieniedzyDoNaprawy;
		stan = 10;
	}
}
