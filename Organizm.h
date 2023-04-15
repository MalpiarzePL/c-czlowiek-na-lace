#pragma once
#include "Punkt.h"
#include <iostream>
#include <string>
using namespace std;

class Swiat;
class Punkt;


class Organizm {
private:
	int sila;
	int inicjatywa;
	int wiek;
	Punkt polozenie;
	string name;
	Swiat* swiat;
	bool zywy;
	bool rozmnozony;


protected:


	virtual Organizm* copy(Punkt pkt) = 0;

	virtual bool czyUcieka();

	void rozmnoz();

public:
	virtual int getUlt();
	Swiat* getSwiat();
	virtual void reakcjaOrg(Organizm* org);
	virtual void akcja() = 0;
	virtual void kolizja();
	virtual void rysowanie() = 0;
	virtual Organizm* zwrocKopie() = 0;
	virtual string getName() = 0;
	void poczTury();
	bool czyZyje();
	bool czyRozmnozony();
	virtual bool ucieczka();
	void starzenie();
	int getSila();
	void setSila(int sila);
	int getInicjatywa();
	int getWiek();
	void setWiek(int wiek);
	Punkt getPolozenie();
	void setPolozenie(Punkt pkt);
	void zabij();
	virtual bool czyOdbilAtak(Organizm* atakujacy);
	Organizm(Punkt pozycja, int sila, int inicjatywa, string name);
	Organizm(Punkt pozycja, int sila, int inicjatywa, string name, int wiek);
	void setSwiat(Swiat* swiat);



};