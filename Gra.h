#pragma once
#include "Swiat.h"



class Gra {
private:
	void tworzSwiat();
	void rysujInterfejs();
	void tworzSwiat2();
	void wczytajZapis();
	Swiat* swiat;
public:
	void graj();
};