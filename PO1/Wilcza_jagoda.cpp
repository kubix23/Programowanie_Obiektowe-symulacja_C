#include "Wilcza_jagoda.h"
Wilcza_jagoda::Wilcza_jagoda(int posY, int posX, Swiat* swiat) :
	Roslina("Wilcza_jagoda", 99, 0, posX, posY,'j',0,swiat) {}

void Wilcza_jagoda::kolizja(Organizm* attacker) {
	Roslina::kolizja(attacker);
	if (attacker->getSila() < this->sila) {
		swiat->usunOrganizm(this);
	}
}

Wilcza_jagoda* Wilcza_jagoda::scion() {
	return new Wilcza_jagoda(0,0,swiat);
}

size_t Wilcza_jagoda::size() const {
	return sizeof(*this);
}