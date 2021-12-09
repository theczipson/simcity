#include "kopalnia.h"

Kopalnia::Kopalnia(int px, int py, string rO, int s, int iPDB, int iDDB, int iZDB, int iPZ, int trw, int cP, int kNOJS)
	:ObiektNieruchomy::ObiektNieruchomy(px, py, rO, s, iPDB, iDDB, iZDB, trw, cP, kNOJS)
{
	iloscProdukowanegoZelaza = iPZ;
}

void Kopalnia::generujZelazo(int& aIZ)
{
	if (time(0) - czasDoProdukcji >= czasProdukcji)
	{
		int iloscWyprodukowanegoZelaza = stan * iloscProdukowanegoZelaza;
		czasDoProdukcji = time(0);
		aIZ += iloscWyprodukowanegoZelaza;
	}
}

