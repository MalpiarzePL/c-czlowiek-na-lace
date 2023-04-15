#include "Organizm.h"
#include "Roslina.h"
#include <random>
using namespace std;

Roslina::Roslina(Punkt pozycja, int sila, string name) : Organizm(pozycja, sila, INICJATYWA_ROSLINY, name) {

}

Organizm* Roslina::copy(Punkt pkt) {
	return nullptr;
}

void Roslina::akcja() {
	sianie();
}

void Roslina::sianie() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 10);
	int random_num = dis(gen);
	if (random_num != 1)
		return;
	else {
		zasiej();
	}
}

void Roslina::reakcjaOrg(Organizm* org) {

}

void Roslina::zasiej() {
	if (!czyRozmnozony()) {
		Punkt pkt = getSwiat()->wolnePole(this->getPolozenie());
		if (pkt == getPolozenie())
			return;
		auto* org = this->copy(pkt);
		getSwiat()->dodajOrg(org);
		rozmnoz();
		string kom = this->getName() + " rozprzestrzenia sie";
		this->getSwiat()->getKomentator().dodajKom(kom);
	}
}

