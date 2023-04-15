#include "Antylopa.h"


Antylopa::Antylopa(Punkt pozycja) : Zwierze(pozycja, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, ZASIEG_RUCHU_ANTYLOPY, ANTYLOPA_NAME) {}

Antylopa::Antylopa(int sila, int wiek, Punkt pozycja) : Zwierze(pozycja, sila, INICJATYWA_ANTYLOPY, ZASIEG_RUCHU_ANTYLOPY, ANTYLOPA_NAME, wiek) {}

Organizm* Antylopa::zwrocKopie() {
	return new Antylopa(*this);
}

void Antylopa::rysowanie() {
	cout << "\033[38;2;139;69;19mA\033[0m";
}

string Antylopa::getName() {
	return ANTYLOPA_NAME;
}

Organizm* Antylopa::copy(Punkt pkt) {
	return new Antylopa(pkt);
}

bool Antylopa::czyUcieka() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 4);

	int rand_num = dis(gen);
	if (rand_num == 1)
		return false;
	return true;
}