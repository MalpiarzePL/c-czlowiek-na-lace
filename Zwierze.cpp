


#include "Zwierze.h"
#include <random>
using namespace std;

class Czlowiek {};
class WilczeJagody {};

Zwierze::Zwierze(Punkt pozycja, int sila, int inicjatywa, int zasieg, string name) : Organizm(pozycja, sila, inicjatywa, name), zasiegRuchu(zasieg), prevPoz(pozycja) {}
Zwierze::Zwierze(Punkt pozycja, int sila, int inicjatywa, int zasieg, string name, int wiek) : Organizm(pozycja, sila, inicjatywa, name, wiek), zasiegRuchu(zasieg), prevPoz(pozycja) {}

void Zwierze::akcja() {
	ruchLos(this->zasiegRuchu);
}

bool Zwierze::czyOdbilAtak(Organizm* atakujacy) {
	return false;
}

void Zwierze::kolizja() {
	Organizm* org = getSwiat()->kolidOrg(this);
	if (org == nullptr)
		return;
	if (org->getName() == this->getName()) {
		//this->getPolozenie() = prevPoz;
		this->cofnij();
		if (!org->czyRozmnozony() && !this->czyRozmnozony()) {
			rozmnazanie((Zwierze*)org);
		}
	}
	else
		walka(org);

}

void Zwierze::walka(Organizm* org) {
	if (this->ucieczka() || org->ucieczka())
		return;
	if (this->getSila() < org->getSila()) {
		if (this->czyOdbilAtak(org)) {
			cofnij();
			return;
		}
		Zwierze* zwierz = dynamic_cast<Zwierze*>(this);
		string kom;
		if (zwierz != nullptr)
			kom = org->getName() + " zabija " + this->getName();
		else
			kom = org->getName() + " zjada " + this->getName();
		this->zabij();
		this->reakcjaOrg(org);
		getSwiat()->getKomentator().dodajKom(kom);
		Czlowiek* hum = dynamic_cast<Czlowiek*>(this);
		Czlowiek* hum2 = dynamic_cast<Czlowiek*>(org);
		if (hum != nullptr && !this->czyZyje()) {
			system("cls");
			cout << "CZLOWIEK ZGINAL" << '\n';
			getSwiat()->czyscTrupy();
			this->getSwiat()->rysujSwiat();
			system("pause");
			exit(0);
		}
		if (hum2 != nullptr && !org->czyZyje()) {
			system("cls");
			cout << "CZLOWIEK ZGINAL" << '\n';
			getSwiat()->czyscTrupy();
			this->getSwiat()->rysujSwiat();
			system("pause");
			exit(0);
		}
	}
	else {
		if (org->czyOdbilAtak(this)) {
			cofnij();
			return;
		}
		Zwierze* zwierz = dynamic_cast<Zwierze*>(org);
		string kom;
		if (zwierz != nullptr)
			kom = this->getName() + " zabija " + org->getName();
		else
			kom = this->getName() + " zjada " + org->getName();
		org->zabij();
		org->reakcjaOrg(this);
		Czlowiek* hum = dynamic_cast<Czlowiek*>(org);
		Czlowiek* hum2 = dynamic_cast<Czlowiek*>(this);
		getSwiat()->getKomentator().dodajKom(kom);
		WilczeJagody* jag = dynamic_cast<WilczeJagody*>(org);
		if (hum != nullptr && !org->czyZyje()) {
			system("cls");
			cout << "CZLOWIEK ZGINAL" << '\n';
			getSwiat()->czyscTrupy();
			this->getSwiat()->rysujSwiat();
			system("pause");
			exit(0);
		}
		if (hum2 != nullptr && !this->czyZyje()) {
			system("cls");
			cout << "CZLOWIEK ZGINAL" << '\n';
			getSwiat()->czyscTrupy();
			this->getSwiat()->rysujSwiat();
			system("pause");
			exit(0);
		}
	}
}


void Zwierze::cofnij() {
	this->setPolozenie(prevPoz);
}

bool Zwierze::ucieczka() {
	if (czyUcieka()) {
		vector<Punkt> pole = getSwiat()->findWolnePola(this->getPolozenie());
		if (pole.size() == 0)
			return false;
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(0, (int)pole.size() - 1);
		int i = dis(gen);
		this->setPolozenie(pole[i]);
		return true;
	}
	return false;
}

int Zwierze::getZasieg() {
	return zasiegRuchu;
}

Punkt Zwierze::getPrevPoz() {
	return prevPoz;
}

void Zwierze::ruchLos(int zasieg) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 4);
	Punkt move = { 0,0 };

	int kierunek = dis(gen);
	if (kierunek == 1)
		move = { zasieg,0 };
	else if (kierunek == 2)
		move = { -zasieg,0 };
	else if (kierunek == 3)
		move = { 0,zasieg };
	else if (kierunek == 4)
		move = { 0,-zasieg };

	rusz(move);
}

void Zwierze::rozmnazanie(Zwierze* zwierz) {
	Punkt pkt = getSwiat()->wolnePole(this->getPolozenie());
	if (pkt == zwierz->getPolozenie() || pkt == getPolozenie())
		pkt = getSwiat()->wolnePole(zwierz->getPolozenie());
	if (pkt == this->getPolozenie() || pkt == zwierz->getPolozenie())
		return;
	auto* org = this->copy(pkt);
	getSwiat()->dodajOrg(org);
	this->rozmnoz();
	zwierz->rozmnoz();
	string kom = this->getName() + " rozmnaza sie";
	this->getSwiat()->getKomentator().dodajKom(kom);
}


void Zwierze::rusz(Punkt wektor) {
	if ((this->getPolozenie() + wektor).pozaPolem(getSwiat()->getWys(), getSwiat()->getSzer())) {
		prevPoz = getPolozenie();
		setPolozenie(getPolozenie() + wektor);
	}
}
