#include "Owca.h"

Owca::Owca(int posY, int posX, Swiat* swiat):
	Zwierze("Owca",4,4,posX,posY,'O',0,swiat) {}

Owca* Owca::scion() {
	return new Owca(0,0,swiat);
}

size_t Owca::size() const {
	return sizeof(*this);
}
