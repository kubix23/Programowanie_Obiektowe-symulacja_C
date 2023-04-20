#include "Czlowiek.h"
#include "Settings.h"
#include "Game.h"

Czlowiek::Czlowiek(int posY, int posX, Swiat* swiat) :
	Zwierze("Czlowiek", 5, 4, posX, posY, '@', 0, swiat) {}

void Czlowiek::moveSpeedYX(short dy, short dx) {
	if(dx)this->dx = dx;
	if(dy)this->dy = dy;
}

void Czlowiek::skill() {
	if (skillCooldown == 0) {
		Game::addLogs("Czlowiek uzyl umiejetnosci Calopalenie niszczac:\n");
		skillCooldown = SKILL_COOLDOWN_AGE;
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				if (posX + j < swiat->getX() && posX + j >= 0 &&
					posY + i < swiat->getY() && posY + i >= 0) {
					Organizm* temp = swiat->getCell(posY + i, posX + j);
					if (temp != NULL && temp != this) {
						Game::addLogs("\t--" + temp->getName() + '(' + std::to_string(temp->getX()) + ',' + std::to_string(temp->getY()) + ')' + '\n');
						swiat->usunOrganizm(temp);
					}
				}
			}
		}
	}
	else {
		Game::addLogs("Zostalo " + std::to_string(skillCooldown) + " lat do uzycia Calopalenia\n");
	}
}

void Czlowiek::akcja() {
	if (dx || dy) {
		size_t newX, newY;
		newY = posY + dy;
		newX = posX + dx;
		if (newY >= 0 && 
			newY < swiat->getY() &&
			newX >= 0 &&
			newX < swiat->getX()) {
			this->move(newY, newX);
		}
		dx = 0;
		dy = 0;
	}
	if (skillCooldown) {
		skillCooldown -= TURN_OLD_AGE;
		Game::addLogs("Zostalo " + std::to_string(skillCooldown) + " lat do uzycia Calopalenia\n");
	}
}

void Czlowiek::assign(Organizm* old) {
	Organizm::assign(old);
	Czlowiek* old_c = (Czlowiek*)old;
	this->skillCooldown = old_c->skillCooldown;
	this->dx = old_c->dx;
	this->dy = old_c->dy;
}

size_t Czlowiek::size() const {
	return sizeof(*this);
}

Czlowiek* Czlowiek::scion() {
	return new Czlowiek(0, 0, swiat);
}
