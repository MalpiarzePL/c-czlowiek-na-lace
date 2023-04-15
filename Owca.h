#pragma once
#include "Zwierze.h"
#include "Punkt.h"

#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
#define ZASIEG_RUCHU_OWCY 1
#define OWCA_NAME "OWCA"

class Owca :public Zwierze {
private:

	string getName() override;
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
public:
	Owca(Punkt pozycja);
	Owca(int sila, int wiek, Punkt pozycja);
};