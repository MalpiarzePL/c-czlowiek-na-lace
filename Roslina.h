#pragma once
#include "Organizm.h"
#include "Swiat.h"
#include "Punkt.h"
#include <iostream>
#include <string>
using namespace std;

class Organizm;

#define INICJATYWA_ROSLINY 0

class Roslina :public Organizm {
private:
	Organizm* copy(Punkt pkt) override;
	void reakcjaOrg(Organizm* org) override;
	void zasiej();
protected:
	void sianie();
	void akcja() override;
public:
	Roslina(Punkt pozycja, int sila, string name);
};