#pragma once
#include "obiektNieruchomy.h"

class Dom : public ObiektNieruchomy
{
	int iloscMiejscMieszkalnych;

public:
	Dom(int = 0, int = 0, string = "Dom", int = 10, int = 0, int = 0, int = 0, int = 5, int = 240, int = 0, int = 15);
	void pogorszenieStanu();
	void generujMiejscaMieszkalne(int&);

	friend class Plansza;
};

