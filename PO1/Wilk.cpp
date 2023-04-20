#include "Wilk.h"

Wilk::Wilk(int posY, int posX, Swiat* swiat):
	Zwierze("Wilk",9,5,posX,posY,'W',0,swiat) {}

Wilk* Wilk::scion() {
	return new Wilk(0,0,swiat);
}

size_t Wilk::size() const {
	return sizeof(*this);
}