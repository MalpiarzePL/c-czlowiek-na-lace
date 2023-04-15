#pragma once
#include "Roslina.h"
#include "Punkt.h"

#define SILA_MLECZA 0
#define MLECZ_NAME "MLECZ"

class Mlecz : public Roslina {
private:
	void akcja() override;
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	string getName() override;
public:
	Mlecz(Punkt pozycja);

};