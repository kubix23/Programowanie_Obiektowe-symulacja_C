#include "Zolw.h"
#include "Settings.h"

Zolw::Zolw(int posY, int posX, Swiat* swiat):
	Zwierze("Zolw",2,1,posX,posY,'Z',0,swiat) {}

void Zolw::akcja() {
	size_t newX, newY;
	if (rand()%4 != 3)return;
	this->getNewYX(&newY, &newX, 1);
	this->move(newY, newX);
}

void Zolw::kolizja(Organizm* attacker) {
	if (!this->proliferation(attacker)){
		if (attacker->getSila() >= TURTLE_DEFENCE_STRENGHT && attacker->getSila() >= this->sila) {
			Swiat* temp = swiat;
			size_t newX = posX;
			size_t newY = posY;
			swiat->usunOrganizm(this);
			attacker->move(newY, newX);
		}
	}
}

Zolw* Zolw::scion() {
	return new Zolw(0,0,swiat);
}

size_t Zolw::size() const {
	return sizeof(*this);
}