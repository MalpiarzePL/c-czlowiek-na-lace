#include "Komentator.h"

void Komentator::wypisz() {
	cout << "\033[0;41m";
	cout << setw(15) << " ";
	cout << "\033[0m\n";
	for (string komentarz : komentarze)
		cout << komentarz << '\n';
	cout << "\033[0;41m";
	cout << setw(15) << " ";
	cout << "\033[0m\n";
	czyscVector();
}

void Komentator::czyscVector() {
	komentarze.clear();
}

void Komentator::dodajKom(string str) {
	komentarze.push_back(str);
}