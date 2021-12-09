#pragma once
#include "obiektNieruchomy.h"

class Biuro : public ObiektNieruchomy
{
	int iloscProdukowanychPieniedzy;

public:
	Biuro(int = 0, int = 0, string = "Biuro", int = 10, int = 0, int = 0, int = 0, int = 5, int = 90, int = 30, int = 10);
	void pogorszenieStanu();
	void generujZloto(int&);
};
