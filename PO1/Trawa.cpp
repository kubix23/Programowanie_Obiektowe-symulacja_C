#include "Trawa.h"
Trawa::Trawa(int posY, int posX, Swiat* swiat):
	Roslina("Trawa",0,0,posX,posY,'t',0,swiat) {}

Trawa* Trawa::scion() {
	return new Trawa(0,0,swiat);
}

size_t Trawa::size() const {
	return sizeof(*this);
}