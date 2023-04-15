#pragma once
#include "Zwierze.h"
#include "Punkt.h"

#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
#define ZASIEG_RUCHU_ANTYLOPY 2
#define ANTYLOPA_NAME "ANTYLOPA"

class Antylopa : public Zwierze {
private:
	string getName() override;
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	bool czyUcieka() override;
public:
	Antylopa(Punkt pozycja);
	Antylopa(int sila, int wiek, Punkt pozycja);
};