#pragma once
#include <iostream>
#include <vector>
class Organizm;
#include "Organizm.h"


class Swiat
{
private:
	size_t sizeX;
	size_t sizeY;
	size_t turn;
	std::vector<Organizm*> organizmy;
	Organizm** mapa;

public:
	Swiat(size_t sizeY, size_t sizeX);
	Swiat(size_t sizeY, size_t sizeX, size_t age);
	size_t getX();
	size_t getY();
	size_t getTurn();
	Organizm* getCell(size_t sizeY, size_t sizeX);
	size_t getOrganizmySize();
	Organizm* getOrganizm(size_t i);
	void setCell(size_t sizeY, size_t sizeX, Organizm* organizm);
	void wykonajTure();
	void wstawOrganizm(Organizm* organizm);
	void usunOrganizm(Organizm* organizm);
	void rysujSwiat();
	~Swiat();
};

