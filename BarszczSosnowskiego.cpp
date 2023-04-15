#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(Punkt pozycja) : Roslina(pozycja, SILA_BARSZCZU_SOSNOWSKIEGO, BARSZCZ_SOSNOWSKIEGO_NAME) {

}

Organizm* BarszczSosnowskiego::zwrocKopie() {
	return new BarszczSosnowskiego(*this);
}

void BarszczSosnowskiego::rysowanie() {
	cout << "\033[31;2mB\033[0m";
}

Organizm* BarszczSosnowskiego::copy(Punkt pkt) {
	return new BarszczSosnowskiego(pkt);
}
string BarszczSosnowskiego::getName() {
	return "BARSZCZ_SOSNOWSKIEGO";
}

void BarszczSosnowskiego::reakcjaOrg(Organizm* org) {
	org->zabij();
}

void BarszczSosnowskiego::akcja() {
	vector<Punkt> punkty = getSwiat()->findZajetePola(this->getPolozenie());
	if (punkty.size() != 0)
	{
		for (int i = 0; i < punkty.size(); i++) {
			Organizm* org = getSwiat()->getOrgNaPoz(punkty[i]);
			Zwierze* zwierz = dynamic_cast<Zwierze*>(org);
			if (zwierz != nullptr) {
				org->zabij();
				Czlowiek* hum = dynamic_cast<Czlowiek*>(org);
				if (hum != nullptr) {
					cout << "CZLOWIEK ZGINAL" << '\n';
					getSwiat()->czyscTrupy();
					this->getSwiat()->rysujSwiat();
					system("pause");
					exit(0);
				}
			}
		}
	}
	Roslina::akcja();
}