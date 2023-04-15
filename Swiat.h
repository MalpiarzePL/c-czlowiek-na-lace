#pragma once
#include <vector>
#include "Zwierze.h"
#include "Komentator.h"
using namespace std;

class Organizm;


class Swiat {
private:
	vector<Organizm*> organizmy;
	int wysokosc;
	int szerokosc;
	Komentator komentator;
	void ruchOrg();
	void nowaTura();
public:
	class Stan {
	public:
		vector<Organizm*> organizmy;
		int wysokosc;
		int szerokosc;
		Komentator komentator;
		Stan(Swiat& outerSwiat) : organizmy(outerSwiat.organizmy.size())
		{
			for (int i = 0; i < outerSwiat.organizmy.size(); i++) {
				Organizm* o = outerSwiat.organizmy[i];
				Organizm* o_copy = o->zwrocKopie();
				o_copy->setSwiat((Swiat*)this);
				organizmy[i] = o_copy;
			}
			wysokosc = outerSwiat.wysokosc;
			szerokosc = outerSwiat.szerokosc;
			komentator = outerSwiat.komentator;
		}
	};
	Stan ostatniStan{ *this };
	Komentator& getKomentator();
	int getWys();
	int getSzer();
	vector<Organizm*> getOrganizmy();
	Organizm* getOrgNaPoz(Punkt pkt);
	void setWysokosc(int wys);
	void setSzerokosc(int szer);
	void setOrganizmy(vector<Organizm*> org);
	vector<Punkt> findZajetePola(Punkt pkt);
	vector<Punkt> findWolnePola(Punkt pkt);
	Organizm* kolidOrg(Organizm* org);
	Punkt wolnePole(Punkt pkt);
	void wykonajTure();
	void rysujSwiat();
	void czyscTrupy();
	void zapiszSwiat();
	void dodajOrg(Organizm* org);
	Swiat(int wys, int szer, vector<Organizm*> organizmy);
	Swiat(int wys, int szer);
};