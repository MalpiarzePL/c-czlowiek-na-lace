#include "Guarana.h"

Guarana::Guarana(Punkt pozycja) : Roslina(pozycja, SILA_GUARANY, GUARANA_NAME) {}

void Guarana::rysowanie() {
	cout << "\033[38;5;53mG\033[0m";
}

Organizm* Guarana::copy(Punkt pkt) {
	return new Guarana(pkt);
}

string Guarana::getName() {
	return "GUARANA";
}

void Guarana::reakcjaOrg(Organizm* org) {
	org->setSila(org->getSila() + 3);
}

Organizm* Guarana::zwrocKopie() {
	return new Guarana(*this);
}