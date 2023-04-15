#include "Owca.h"

Owca::Owca(Punkt pozycja) : Zwierze(pozycja, SILA_OWCY, INICJATYWA_OWCY, ZASIEG_RUCHU_OWCY, OWCA_NAME) {}

Owca::Owca(int sila, int wiek, Punkt pozycja) : Zwierze(pozycja, sila, INICJATYWA_OWCY, ZASIEG_RUCHU_OWCY, OWCA_NAME, wiek) {}

void Owca::rysowanie() {
	cout << 'O';
}

string Owca::getName() {
	return OWCA_NAME;
}

Organizm* Owca::copy(Punkt pkt) {
	return new Owca(pkt);
}

Organizm* Owca::zwrocKopie() {
	return new Owca(*this);
}