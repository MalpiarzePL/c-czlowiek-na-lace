#include "Lis.h"
#include <algorithm>


Lis::Lis(Punkt pozycja) : Zwierze(pozycja, SILA_LISA, INICJATYWA_LISA, ZASIEG_RUCHU_LISA, LIS_NAME) {}

Lis::Lis(int sila, int wiek, Punkt pozycja) : Zwierze(pozycja, sila, INICJATYWA_LISA, ZASIEG_RUCHU_LISA, LIS_NAME, wiek) {}

void Lis::rysowanie() {
	cout << "\033[38;5;208mL\033[0m";
}

string Lis::getName() {
	return LIS_NAME;
}

Organizm* Lis::copy(Punkt pkt) {
	return new Lis(pkt);
}

void Lis::akcja() {
	vector<Punkt> punkty = this->getSwiat()->findZajetePola(getPolozenie());
	vector<Punkt> punkty2 = this->getSwiat()->findWolnePola(getPolozenie());
	random_device rd;
	mt19937 gen(rd());
	for (int i = (int)punkty.size() - 1; i >= 0; i--) {
		if (getSwiat()->getOrgNaPoz(punkty[i])->getSila() > this->getSila()) {
			punkty.erase(punkty.begin() + i);
		}
	}
	punkty.insert(punkty.end(), punkty2.begin(), punkty2.end());
	shuffle(punkty.begin(), punkty.end(), gen);
	if (!punkty.empty())
		rusz(punkty[0] - this->getPolozenie());
}

Organizm* Lis::zwrocKopie() {
	return new Lis(*this);
}