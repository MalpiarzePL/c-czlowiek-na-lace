#pragma once
#include "Zwierze.h"
#include "Punkt.h"

#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define ZASIEG_RUCHU_ZOLWIA 1
#define ZOLW_NAME "ZOLW"
#define BLOK_ZOLWIA 5

class Zolw : public Zwierze {
private:
	string getName() override;
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy) override;
public:
	Zolw(Punkt pozycja);
	Zolw(int sila, int wiek, Punkt pozycja);

};