#include "Zolw.h"

Zolw::Zolw(Punkt pozycja) : Zwierze(pozycja, SILA_ZOLWIA, INICJATYWA_ZOLWIA, ZASIEG_RUCHU_ZOLWIA, ZOLW_NAME) {}

Zolw::Zolw(int sila, int wiek, Punkt pozycja) : Zwierze(pozycja, sila, INICJATYWA_ZOLWIA, ZASIEG_RUCHU_ZOLWIA, ZOLW_NAME, wiek) {}

void Zolw::rysowanie() {
	cout << "\033[32mZ\033[0m";
}

string Zolw::getName() {
	return ZOLW_NAME;
}

Organizm* Zolw::copy(Punkt pkt) {
	return new Zolw(pkt);
}

bool Zolw::czyOdbilAtak(Organizm* atakujacy) {
	if (atakujacy->getSila() >= BLOK_ZOLWIA)
		return false;
	return true;
}

void Zolw::akcja() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 4);
	int random_num = dis(gen);
	if (random_num == 1)
		Zwierze::akcja();
}

Organizm* Zolw::zwrocKopie() {
	return new Zolw(*this);
}