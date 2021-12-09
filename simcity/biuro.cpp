#include "biuro.h"
#include "obiektNieruchomy.h"

Biuro::Biuro(int px, int py, string rO, int s, int iPDB, int iDDB, int iZDB, int iPP, int trw, int cP, int kNOJS)
	:ObiektNieruchomy::ObiektNieruchomy(px, py, rO, s, iPDB, iDDB, iZDB, trw, cP, kNOJS)
{
	iloscProdukowanychPieniedzy = iPP;
}


void Biuro::generujZloto(int& aIP)
{
	if (time(0) - czasDoProdukcji >= czasProdukcji)
	{
		int iloscWyprodukowanegoZlota = stan * iloscProdukowanychPieniedzy;
		czasDoProdukcji = time(0);
		aIP += iloscWyprodukowanegoZlota;
	}
}

