#include "Lis.h"
#include "Settings.h"


Lis::Lis(int posY, int posX, Swiat* swiat):
	Zwierze("Lis",3,7,posX,posY,'L',0,swiat) {}

void Lis::akcja() {
	size_t newX, newY, i = 0;
	do {
		this->getNewYX(&newY, &newX, 1);
		i++;
	} while (swiat->getCell(newY, newX) != NULL &&
			 swiat->getCell(newY, newX)->getSila() > sila &&
			 i < TIMEOUT_NUMBER);
	if (i >= TIMEOUT_NUMBER)return;
	this->move(newY,newX);
}

Lis* Lis::scion() {
	return new Lis(0,0,swiat);
}

size_t Lis::size() const {
	return sizeof(*this);
}