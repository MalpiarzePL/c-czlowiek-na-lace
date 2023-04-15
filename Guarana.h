#pragma once
#include "Roslina.h"
#include "Punkt.h"

#define SILA_GUARANY 0
#define GUARANA_NAME "GUARANA"

class Guarana : public Roslina {
private:
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	string getName() override;
	void rysowanie() override;
	void reakcjaOrg(Organizm* org) override;
public:
	Guarana(Punkt pozycja);
};