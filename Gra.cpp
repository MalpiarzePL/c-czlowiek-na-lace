#include "Gra.h"
#include "Swiat.h"
#include "Organizm.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Guarana.h"
#include "BarszczSosnowskiego.h"
#include "Mlecz.h"
#include "Zolw.h"
#include "Wilk.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Wilk.h"
#include "Czlowiek.h"
#include <fstream>
#include <conio.h>

void Gra::graj() {
	tworzSwiat2();
	while (true) {
		rysujInterfejs();
		swiat->rysujSwiat();
		swiat->wykonajTure();
		cout << '\n';
	}
}

void Gra::tworzSwiat2() {
	cout << "Podaj wymiary planszy (X Y) (dla 0 0 wczytuje zapisany stan gry)" << '\n';
	int x, y;
	cin >> x >> y;
	if (x == 0 && y == 0)
		wczytajZapis();
	else
		swiat = new Swiat(y, x);
}

void Gra::wczytajZapis() {
	ifstream file("zapis.txt");
	string str;
	int x, y;
	file >> x >> y;
	vector<Organizm*> orgs;
	while (file >> str) {
		Organizm* org;
		string name = str;
		int sila;
		int wiek;
		int polX;
		int polY;
		file >> sila >> wiek >> polX >> polY;
		if (str == "CZLOWIEK") {
			int ult;
			file >> ult;
			org = new Czlowiek(sila, wiek, { polX,polY }, ult);
		}
		else if (str == "ANTYLOPA")
			org = new Antylopa(sila, wiek, { polX,polY });
		else if (str == "LIS")
			org = new Wilk(sila, wiek, { polX,polY });
		else if (str == "OWCA")
			org = new Owca(sila, wiek, { polX,polY });
		else if (str == "WILK")
			org = new Wilk(sila, wiek, { polX,polY });
		else if (str == "ZOLW")
			org = new Zolw(sila, wiek, { polX,polY });

		orgs.push_back(org);
	}
	swiat = new Swiat(y, x, orgs);
	file.close();
}

void Gra::tworzSwiat() {
	swiat = new Swiat(5, 5, {
	//new Wilk({2,0}),
	//new Wilk({1,0}),
	new Wilk({1,1}),
	new Wilk({1,2}),
	new Wilk({1,3}),
	//new Wilk({1,4}),
	//new Wilk({3,0}),
	new Wilk({3,1}),
	new Wilk({3,2}),
	new Wilk({3,3}),
	//new Wilk({3,4}),

	new Czlowiek({0,0})
		});
	for (Organizm* org : swiat->getOrganizmy())
		org->setSwiat(swiat);
}

void Gra::rysujInterfejs() {
	system("cls");
	swiat->getKomentator().wypisz();
	cout << "Adam Białek 193677\n";
	cout << "Poruszanie: strzalki\n";
	cout << "Moc: r\n";
	cout << "Zapisz gre: s\n";
	cout << "Gracz: \033[0;41mC\033[0m\n";
	cout << "Wilk: \033[38; 5; 8mW\033[0m\n";
	cout << "Owca: O\n";
	cout << "Zolw: \033[32mZ\033[0m\n";
	cout << "Antylopa: \033[38;2;139;69;19mA\033[0m\n";
	cout << "Wilk: \033[38;5;208mL\033[0m\n";
	cout << "Trawa: \x1b[42mT\x1b[0m\n";
	cout << "Mlecz: \033[33mM\033[0m\n";
	cout << "Guarana: \033[38;5;53mG\033[0m\n";
	cout << "Wilcze Jagody: \033[48;5;129mJ\033[0m\n";
	cout << "Barszcz sosnowskiego: \033[31;2mB\033[0m\n";
	swiat->getKomentator().czyscVector();
}
