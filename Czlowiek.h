#pragma once

#include "Zwierze.h"
#include "Punkt.h"

#define SILA_CZLOWIEKA 3
#define INICJATYWA_CZLOWIEKA 5
#define ZASIEG_RUCHU_CZLOWIEKA 1
#define CZLOWIEK_NAME "CZLOWIEK"

class Organizm;
class Zwierze;

class Czlowiek : public Zwierze {
private:
	int ult;
	void akcja() override;
	void ruchCzlowieka();
	Organizm* copy(Punkt pkt) override;
	void rysowanie() override;
	string getName() override;
	Organizm* zwrocKopie() override;
public:
	int getUlt() override;
	Czlowiek(int sila, int wiek, Punkt pozycja, int ult);
	Czlowiek(Punkt pozycja);

};