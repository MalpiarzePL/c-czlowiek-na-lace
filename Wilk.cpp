#include "Zwierze.h"

#include "Wilk.h"

using namespace std;

Wilk::Wilk(Punkt pozycja) : Zwierze(pozycja, SILA_WILKA, INICJATYWA_WILKA, ZASIEG_RUCHU_WILKA, WILK_NAME) {}

Wilk::Wilk(int sila, int wiek, Punkt pozycja) : Zwierze(pozycja, sila, INICJATYWA_WILKA, ZASIEG_RUCHU_WILKA, WILK_NAME, wiek) {}

void Wilk::rysowanie() {
	cout << "\033[38;5;8mW\033[0m";
}

string Wilk::getName() {
	return WILK_NAME;
}

Organizm* Wilk::copy(Punkt pkt) {
	return new Wilk(pkt);
}

Organizm* Wilk::zwrocKopie() {
	return new Wilk(*this);
}