#include "Guarana.h"
Guarana::Guarana(int posY, int posX, Swiat* swiat):
	Roslina("Guarana",0,0,posX,posY,'g',0,swiat) {}

void Guarana::kolizja(Organizm* attacker) {
	attacker->setSila(attacker->getSila() + 3);
	Roslina::kolizja(attacker);
}

Guarana* Guarana::scion() {
	return new Guarana(0,0,swiat);
}

size_t Guarana::size() const {
	return sizeof(*this);
}