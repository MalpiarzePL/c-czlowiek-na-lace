#include "Punkt.h"

Punkt::Punkt(int x, int y) : x(x), y(y) {}

bool Punkt::operator==(Punkt pkt) const {
	if (this->x == pkt.x && this->y == pkt.y)
		return true;
	else
		return false;
}

bool Punkt::pozaPolem(int wys, int szer) {
	if (y < 0 || x < 0 || y >= wys || x >= szer)
		return false;
	else
		return true;
}

Punkt Punkt::operator+(Punkt pkt)  {
	return { x + pkt.x, y + pkt.y };
}

Punkt Punkt::operator-(Punkt pkt)  {
	return { x - pkt.x, y - pkt.y };
}

int Punkt::getX() {
	return x;
}

int Punkt::getY() {
	return y;
}
