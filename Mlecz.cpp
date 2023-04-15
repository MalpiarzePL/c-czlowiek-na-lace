#include "Mlecz.h"

Mlecz::Mlecz(Punkt pozycja) : Roslina(pozycja, SILA_MLECZA, MLECZ_NAME) {

}

void Mlecz::rysowanie() {
	cout << "\033[33mM\033[0m";
}

Organizm* Mlecz::copy(Punkt pkt) {
	return new Mlecz(pkt);
}

string Mlecz::getName() {
	return "MLECZ";
}

void Mlecz::akcja() {
	for (int i = 0; i < 3; i++)
		sianie();
}

Organizm* Mlecz::zwrocKopie() {
	return new Mlecz(*this);
}