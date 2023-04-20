#pragma once
class Swiat;
#include "swiat.h"

class Organizm
{
protected:
	std::string name;
	int sila;
	int iniciatywa;
	size_t posX;
	size_t posY;
	char symbol;
	size_t wiek;
	Swiat* swiat;
public:
	Organizm(std::string name, int sila, int iniciatywa, size_t posX, size_t posY, char symbol, size_t wiek, Swiat* swiat);
	int getSila();
	int getIniciatywa();
	int getWiek();
	size_t getX();
	size_t getY();
	std::string getName();
	void setSila(int sila);
	void setSwiat(Swiat* swiat);
	void setX(size_t x);
	void setY(size_t y);
	void getNewYX(size_t* newY, size_t* newX, short range);
	void yearOlder(short years);
	void rysowanie();
	bool proliferation(Organizm* attacker);
	virtual void assign(Organizm* old);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm* attacker) = 0;
	virtual void move(size_t& newY, size_t& newX) = 0;
	virtual Organizm* scion() = 0;
	virtual size_t size() const = 0;
};

