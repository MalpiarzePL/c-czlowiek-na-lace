#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Antylopa.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Czlowiek.h"
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;


int Swiat::getWys() {
	return wysokosc;
}

int Swiat::getSzer() {
	return szerokosc;
}

vector<Organizm*> Swiat::getOrganizmy() {
	return organizmy;
}

Komentator& Swiat::getKomentator() {
	return komentator;
}

void Swiat::setWysokosc(int wys) {
	this->wysokosc = wys;
}

void Swiat::setSzerokosc(int szer) {
	this->szerokosc = szer;
}

void Swiat::setOrganizmy(vector<Organizm*> org) {
	this->organizmy = org;
}

Swiat::Swiat(int wys, int szer, vector<Organizm*> organizmy) : wysokosc(wys), szerokosc(szer), organizmy(move(organizmy)) {
	for (auto* organizm : this->organizmy)
		organizm->setSwiat(this);
}

Swiat::Swiat(int wys, int szer) {
	vector<Organizm*> organizmy;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 27);
	for (int i = 0; i < wys; i++) {
		for (int j = 0; j < szer; j++) {
			int random = dis(gen);
			switch (random) {
			case 0:
				organizmy.push_back(new  Antylopa({ j,i }));
				break;
			case 1:
				organizmy.push_back(new  BarszczSosnowskiego({ j,i }));
				break;
			case 2:
				organizmy.push_back(new  Guarana({ j,i }));
				break;
			case 3:
				organizmy.push_back(new  Lis({ j,i }));
				break;
			case 4:
				organizmy.push_back(new  Mlecz({ j,i }));
				break;
			case 5:
				organizmy.push_back(new  Owca({ j,i }));
				break;
			case 6:
				organizmy.push_back(new  Trawa({ j,i }));
				break;
			case 7:
				organizmy.push_back(new  WilczeJagody({ j,i }));
				break;
			case 8:
				organizmy.push_back(new  Wilk({ j,i }));
				break;
			case 9:
				organizmy.push_back(new  Zolw({ j,i }));
				break;
			default:
				break;
			}
		}
	}
	uniform_int_distribution<> szerok(0, szer - 1);
	uniform_int_distribution<> wysok(0, wys - 1);
	int randX = szerok(gen);
	int randY = wysok(gen);
	int i = 0;
	for (auto* org : organizmy) {
		if (org->getPolozenie() == Punkt{ randX,randY }) {
			organizmy.erase(organizmy.begin() + i);
			break;
		}

		i++;
	}
	organizmy.push_back(new Czlowiek({ randX,randY }));
	this->organizmy = organizmy;
	for (auto* organizm : this->organizmy)
		organizm->setSwiat(this);
	this->wysokosc = wys;
	this->szerokosc = szer;
}

Organizm* Swiat::getOrgNaPoz(Punkt pkt) {
	Organizm* szukaj = nullptr;
	for (auto* org : organizmy) {
		if (pkt == org->getPolozenie()) {
			szukaj = org;
			break;
		}
	}
	return szukaj;
}

void Swiat::czyscTrupy() {
	int i = 0;
	for (auto* org : organizmy) {
		if (!org->czyZyje()) {
			organizmy.erase(organizmy.begin() + i);
			czyscTrupy();
			break;
		}
		i++;
	}
}

Punkt Swiat::wolnePole(Punkt pkt) {
	vector<Punkt> punkty;
	if (getOrgNaPoz(pkt + Punkt{ 1,0 }) == nullptr && (pkt + Punkt{ 1,0 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 1,0 });
	if (getOrgNaPoz(pkt + Punkt{ -1,0 }) == nullptr && (pkt + Punkt{ -1,0 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ -1,0 });
	if (getOrgNaPoz(pkt + Punkt{ 0,1 }) == nullptr && (pkt + Punkt{ 0,1 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 0,1 });
	if (getOrgNaPoz(pkt + Punkt{ 0,-1 }) == nullptr && (pkt + Punkt{ 0,-1 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 0,-1 });
	if (punkty.size() == 0)
		return pkt;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, ((int)punkty.size() - 1));
	int rand_num = dis(gen);
	return punkty[rand_num];
}

vector<Punkt> Swiat::findZajetePola(Punkt pkt) {
	vector<Punkt> punkty;
	if (getOrgNaPoz(pkt + Punkt{ 1,0 }) != nullptr && (pkt + Punkt{ 1,0 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 1,0 });
	if (getOrgNaPoz(pkt + Punkt{ -1,0 }) != nullptr && (pkt + Punkt{ -1,0 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ -1,0 });
	if (getOrgNaPoz(pkt + Punkt{ 0,1 }) != nullptr && (pkt + Punkt{ 0,1 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 0,1 });
	if (getOrgNaPoz(pkt + Punkt{ 0,-1 }) != nullptr && (pkt + Punkt{ 0,-1 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 0,-1 });
	return punkty;
}

vector<Punkt> Swiat::findWolnePola(Punkt pkt) {
	vector<Punkt> punkty;
	if (getOrgNaPoz(pkt + Punkt{ 1,0 }) == nullptr && (pkt + Punkt{ 1,0 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 1,0 });
	if (getOrgNaPoz(pkt + Punkt{ -1,0 }) == nullptr && (pkt + Punkt{ -1,0 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ -1,0 });
	if (getOrgNaPoz(pkt + Punkt{ 0,1 }) == nullptr && (pkt + Punkt{ 0,1 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 0,1 });
	if (getOrgNaPoz(pkt + Punkt{ 0,-1 }) == nullptr && (pkt + Punkt{ 0,-1 }).pozaPolem(wysokosc, szerokosc))
		punkty.push_back(pkt + Punkt{ 0,-1 });
	return punkty;
}

void Swiat::dodajOrg(Organizm* org) {
	org->setSwiat(this);
	organizmy.push_back(org);
}

Organizm* Swiat::kolidOrg(Organizm* org) {
	for (auto* org2 : organizmy) {
		if (org->getPolozenie() == org2->getPolozenie() && org != org2)
			return org2;
	}
	return nullptr;
}

void Swiat::wykonajTure() {
	ostatniStan = Stan(*this);
	nowaTura();
	ruchOrg();
	czyscTrupy();
}

void Swiat::nowaTura() {
	for (auto* org : organizmy)
		org->poczTury();
}

void Swiat::ruchOrg() {
	sort(organizmy.begin(), organizmy.end(), [](Organizm* org1, Organizm* org2) {
		if (org1->getInicjatywa() == org2->getInicjatywa()) {
			return org1->getWiek() > org2->getWiek();
		}
	return org1->getInicjatywa() > org2->getInicjatywa();
		});
	for (int i = 0; i < organizmy.size(); i++) {
		auto* org = organizmy[i];
		if (org->czyZyje() && org->getWiek() != 0) {
			org->akcja();
			org->kolizja();
		}
		org->starzenie();
	}
	cout << '\n';
}

void Swiat::rysujSwiat() {
	for (int i = 0; i < wysokosc; i++) {
		for (int j = 0; j < szerokosc; j++) {
			auto* org = getOrgNaPoz({ j,i });
			cout << '|';
			if (org == nullptr)
				cout << ' ';
			else
				org->rysowanie();
			cout << '|';
		}
		cout << '\n';
	}
}

void Swiat::zapiszSwiat() {
	ofstream file;
	file.open("zapis.txt", ofstream::out, ofstream::trunc);
	file.close();
	file.open("zapis.txt");
	file << getWys() << ' ' << getSzer() << " \n";
	for (auto* organizm : ostatniStan.organizmy) {
		Czlowiek* hum = dynamic_cast<Czlowiek*>(organizm);
		if (hum == nullptr)
			file << organizm->getName() << ' ' << organizm->getSila() << ' ' << organizm->getWiek() << ' ' << organizm->getPolozenie().getX() << ' ' << organizm->getPolozenie().getY() << '\n';
		else
			file << organizm->getName() << ' ' << organizm->getSila() << ' ' << organizm->getWiek() << ' ' << organizm->getPolozenie().getX() << ' ' << organizm->getPolozenie().getY() << ' ' << organizm->getUlt() << '\n';
	}
	file.close();
}
