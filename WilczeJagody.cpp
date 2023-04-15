#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Punkt pozycja) : Roslina(pozycja, SILA_WILCZYCH_JAGOD, WILCZE_JAGODY_NAME) {}

void WilczeJagody::rysowanie() {
	cout << "\033[48;5;129mJ\033[0m";
}

Organizm* WilczeJagody::copy(Punkt pkt) {
	return new WilczeJagody(pkt);
}

string WilczeJagody::getName() {
	return "WILCZE_JAGODY";
}

void WilczeJagody::reakcjaOrg(Organizm* org) {
	org->zabij();
}

Organizm* WilczeJagody::zwrocKopie() {
	return new WilczeJagody(*this);
}