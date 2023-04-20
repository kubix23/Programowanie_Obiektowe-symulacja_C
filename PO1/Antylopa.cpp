#include "Antylopa.h"
#include "Settings.h"


Antylopa::Antylopa(int posY, int posX, Swiat* swiat):
	Zwierze("Antylopa",4,4,posX,posY,'A',0,swiat) {}

void Antylopa::akcja() {
	size_t newX, newY;
	this->getNewYX(&newY, &newX, 2);
	this->move(newY, newX);
};

void Antylopa::kolizja(Organizm* attacker) {
	if (!this->proliferation(attacker)) {
		if (rand()%ANTYLOPE_DODGE_CHANCE == 0) {
			size_t newX, newY, i = 0;
			do {
				this->getNewYX(&newY, &newX, 1);
				i++;
			} while (swiat->getCell(newY, newX) != NULL &&
					 i < TIMEOUT_NUMBER);
			if (i >= TIMEOUT_NUMBER)return;
			this->move(newY, newX);
		}	
		else {
			Zwierze::kolizja(attacker);
		}
	}
};

Antylopa* Antylopa::scion() {
	return new Antylopa(0,0,swiat);
}

size_t Antylopa::size() const {
	return sizeof(*this);
}