#pragma once
#include "Zwierze.h"
#include "Punkt.h"

#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define ZASIEG_RUCHU_LISA 1
#define LIS_NAME "LIS"

class Lis : public Zwierze {
private:
	string getName() override;
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	void akcja() override;
public:
	Lis(Punkt pozycja);
	Lis(int sila, int wiek, Punkt pozycja);
};