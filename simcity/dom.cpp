#include "dom.h"

Dom::Dom(int px, int py, string rO, int s, int iPDB, int iDDB, int iZDB, int iMM, int trw, int cP, int kNOJS)
	:ObiektNieruchomy::ObiektNieruchomy(px, py, rO, s, iPDB, iDDB, iZDB, trw, cP, kNOJS)
{
	iloscMiejscMieszkalnych = iMM;
}

void Dom::generujMiejscaMieszkalne(int& cIMM)
{
	if (time(0) - czasDoProdukcji == czasProdukcji)
	{
		czasDoProdukcji -= 1;
		cIMM += iloscMiejscMieszkalnych;
	}
}