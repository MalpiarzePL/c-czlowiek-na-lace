#pragma once
#include "Organizm.h"
#include "Zwierze.h"
#include "Punkt.h"
#include "Swiat.h"

#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
#define ZASIEG_RUCHU_WILKA 1
#define WILK_NAME "WILK"

class Organizm;

class Wilk : public Zwierze {
private:
	string getName() override;
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
public:
	Wilk(Punkt pozycja);
	Wilk(int sila, int wiek, Punkt pozycja);

};