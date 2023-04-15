#pragma once
#include "Roslina.h"
#include "Punkt.h"

#define SILA_WILCZYCH_JAGOD 99
#define WILCZE_JAGODY_NAME "WILCZE_JAGODY"

class WilczeJagody : public Roslina {
private:
	Organizm* copy(Punkt pkt) override;
	Organizm* zwrocKopie() override;
	string getName() override;
	void rysowanie() override;
	void reakcjaOrg(Organizm* org) override;
public:
	WilczeJagody(Punkt pozycja);

};