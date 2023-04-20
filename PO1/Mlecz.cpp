#include "Mlecz.h"
#include "Settings.h"
Mlecz::Mlecz(int posY, int posX, Swiat* swiat):
	Roslina("Mlecz",0,0,posX,posY,'m',0,swiat) {}

void Mlecz::akcja() {
	for (int i = 0; i < NUMBER_DANDELIONS_TRIALS; i++) {
		Roslina::akcja();
	}
}

Mlecz* Mlecz::scion() {
	return new Mlecz(0,0,swiat);
}

size_t Mlecz::size() const {
	return sizeof(*this);
}