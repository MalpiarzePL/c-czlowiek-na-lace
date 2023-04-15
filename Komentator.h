#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Komentator {
private:
	vector<string> komentarze;
public:
	void wypisz();
	void dodajKom(string str);
	void czyscVector();
};