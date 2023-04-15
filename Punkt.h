#pragma once


class Punkt {
private:
	int x;
	int y;
public:
	Punkt(int x, int y);
	int getX();
	int getY();
	bool pozaPolem(int wys, int szer);
	bool operator==(Punkt pkt) const;
	Punkt operator+(Punkt pkt) const;
	Punkt operator-(Punkt pkt) const;
};