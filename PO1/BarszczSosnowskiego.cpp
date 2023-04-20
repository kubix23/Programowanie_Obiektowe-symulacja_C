#include "BarszczSosnowskiego.h"
#include "Zwierze.h"
#include "Settings.h"

BarszczSosnowskiego::BarszczSosnowskiego(int posY, int posX, Swiat* swiat):
	Roslina("Barszcz",10,0,posX,posY,'s',0,swiat) {}

void BarszczSosnowskiego::akcja() {
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			if (posX + j < swiat->getX() && posX + j >= 0 &&
				posY + i < swiat->getY() && posY + i >= 0 ) {
				Organizm* temp = swiat->getCell(posY + i, posX + j);
				if (temp != NULL) {
					if (Zwierze* v = dynamic_cast<Zwierze*>(temp)) {
						v->kolizja(this);
					}
				}
			}
		}
	}
	if (rand() % (PLANT_CHANCE*2) == 0) {
		this->proliferation(this);
	}
}

BarszczSosnowskiego* BarszczSosnowskiego::scion() {
	return new BarszczSosnowskiego(0,0,swiat);
}

size_t BarszczSosnowskiego::size() const {
	return sizeof(*this);
}