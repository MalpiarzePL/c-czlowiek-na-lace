#pragma once
#include "Organizm.h"

#include "Punkt.h"
#include "Swiat.h"
#include <string>
#include <random>

using namespace std;

class Organizm;
class Swiat;

class Zwierze : public Organizm {

private:
	int zasiegRuchu;
	Punkt prevPoz;
	void kolizja() override;
	void ruchLos(int zasieg);
	void reakcjaOrg(Organizm* org) override;
	void rozmnazanie(Zwierze* zwierz);
	void cofnij();
	bool ucieczka() override;
	bool czyOdbilAtak(Organizm* atakujacy);
	void walka(Organizm* org);

protected:
	virtual void akcja();
	void rusz(Punkt wektor);
public:
	int getZasieg();
	Punkt getPrevPoz();
	Zwierze(Punkt pozycja, int sila, int inicjatywa, int zasieg, string name);
	Zwierze(Punkt pozycja, int sila, int inicjatywa, int zasieg, string name, int wiek);


};