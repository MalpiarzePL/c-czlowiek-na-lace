#pragma once
#include "Roslina.h"
#include "Punkt.h"
#include "Czlowiek.h"

#define SILA_BARSZCZU_SOSNOWSKIEGO 10
#define BARSZCZ_SOSNOWSKIEGO_NAME "BARSZCZ_SOSNOWSKIEGO"

class BarszczSosnowskiego : public Roslina {
private:
	void rysowanie() override;
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	string getName() override;
	void reakcjaOrg(Organizm* org) override;
	void akcja() override;
public:
	BarszczSosnowskiego(Punkt pozycja);
};