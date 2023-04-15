#include "Trawa.h"

Trawa::Trawa(Punkt pozycja) : Roslina(pozycja, SILA_TRAWY, TRAWA_NAME) {

}

void Trawa::rysowanie() {
	cout << "\x1b[42mT\x1b[0m";
}

Organizm* Trawa::copy(Punkt pkt) {
	return new Trawa(pkt);
}

string Trawa::getName() {
	return "TRAWA";
}

Organizm* Trawa::zwrocKopie() {
	return new Trawa(*this);
}