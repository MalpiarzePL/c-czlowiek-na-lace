#include "Czlowiek.h"
#include "Zwierze.h"
#include "Punkt.h"
#include <conio.h>

void Czlowiek::akcja() {
	ruchCzlowieka();
}

void Czlowiek::ruchCzlowieka() {
	Punkt wektor = { 0, 0 };
	int zasieg;
	char ch;
	ch = _getch();
	if (ch == 's') {
		getSwiat()->zapiszSwiat();
		ruchCzlowieka();
		return;
	}
	else if (ch == 'r') {
		if (ult == 0)
			ult = 10;
		else
			cout << "UMIEJETNOSC NIEGOTOWA\n";
		ruchCzlowieka();
		return;
	}
	ch = _getch();
	if (ult == 0)
		zasieg = 1;
	else if (ult >= 8) {
		zasieg = 2;
		ult--;
	}
	else if (ult >= 6) {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(1, 2);
		zasieg = dis(gen);
		ult--;
	}
	else {
		zasieg = 1;
		ult--;
	}
	switch (ch) {
	case 72:
		wektor = { 0, -zasieg };
		break;
	case 80:
		wektor = { 0, zasieg };
		break;
	case 75:
		wektor = { -zasieg, 0 };
		break;
	case 77:
		wektor = { zasieg, 0 };
		break;
	}
	rusz(wektor);
}

Organizm* Czlowiek::zwrocKopie() {
	return new Czlowiek(*this);
}

Organizm* Czlowiek::copy(Punkt pkt) {
	return new Czlowiek(pkt);
}

Czlowiek::Czlowiek(int sila, int wiek, Punkt pozycja, int ult) : Zwierze(pozycja, sila, INICJATYWA_CZLOWIEKA, ZASIEG_RUCHU_CZLOWIEKA, CZLOWIEK_NAME, wiek) {
	this->ult = ult;
}

Czlowiek::Czlowiek(Punkt pozycja) : Zwierze(pozycja, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA, ZASIEG_RUCHU_CZLOWIEKA, CZLOWIEK_NAME) {
	ult = 0;
}

int Czlowiek::getUlt() {
	return ult;
}

void Czlowiek::rysowanie() {
	cout << "\033[0;41mC\033[0m";
}

string Czlowiek::getName() {
	return "CZLOWIEK";
}