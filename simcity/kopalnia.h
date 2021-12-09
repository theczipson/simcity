#pragma once
#include "obiektNieruchomy.h"

class Kopalnia : public ObiektNieruchomy
{
	int iloscProdukowanegoZelaza;

public:
	Kopalnia(int = 0, int = 0, string = "Kopalnia", int = 10, int = 0, int = 0, int = 0, int = 2, int = 120, int = 50, int = 5);
	void pogorszenieStanu();
	void generujZelazo(int&);
};

