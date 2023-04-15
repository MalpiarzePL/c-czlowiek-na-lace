#include "Organizm.h"
#include "Swiat.h"


Organizm::Organizm(Punkt pozycja, int sila, int inicjatywa, string name) : sila(sila), inicjatywa(inicjatywa), wiek(0), zywy(true), polozenie(pozycja), name(name), rozmnozony(true) {}
Organizm::Organizm(Punkt pozycja, int sila, int inicjatywa, string name, int wiek) : sila(sila), inicjatywa(inicjatywa), wiek(wiek), zywy(true), polozenie(pozycja), name(name), rozmnozony(true) {}

void Organizm::setSwiat(Swiat* swiat) {
	this->swiat = swiat;
}

int Organizm::getInicjatywa() {
	return inicjatywa;
}

void Organizm::poczTury() {
	this->rozmnozony = false;
}

int Organizm::getUlt() {
	return 0;
}

string Organizm::getName() {
	return name;
}

bool Organizm::czyOdbilAtak(Organizm* atakujacy) {
	return false;
}

void Organizm::reakcjaOrg(Organizm* org) {

}

Punkt Organizm::getPolozenie() {
	return polozenie;
}

Organizm* Organizm::zwrocKopie() {
	return nullptr;
}

int Organizm::getSila() {
	return sila;
}

int Organizm::getWiek() {
	return wiek;
}

void Organizm::starzenie() {
	++wiek;
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}

void Organizm::setWiek(int wiek) {
	this->wiek = wiek;
}

void Organizm::setPolozenie(Punkt pkt) {
	this->polozenie = pkt;
}

void Organizm::zabij() {
	string kom = this->getName() + " umiera";
	swiat->getKomentator().dodajKom(kom);
	this->zywy = false;
}

bool Organizm::czyUcieka() {
	return false;
}

Swiat* Organizm::getSwiat() {
	return swiat;
}

bool Organizm::ucieczka() {
	return false;
}

bool Organizm::czyZyje() {
	return zywy;
}

bool Organizm::czyRozmnozony() {
	return rozmnozony;
}

void Organizm::rozmnoz() {
	rozmnozony = true;
}

void Organizm::kolizja() {

}

