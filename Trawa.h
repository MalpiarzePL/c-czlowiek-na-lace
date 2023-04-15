#pragma once
#include "Roslina.h"
#include "Punkt.h"

#define SILA_TRAWY 0
#define TRAWA_NAME "TRAWA"

class Trawa : public Roslina {
private:
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	string getName() override;
public:
	Trawa(Punkt pozycja);
};