#include "Zwierze.h"
#include <iostream>
#include "Game.h"

using namespace std;

void Zwierze::move(size_t& newY, size_t& newX) {
	if (swiat->getCell(newY, newX) != NULL) {
		swiat->getCell(newY, newX)->kolizja(this);
	}
	else {
		swiat->setCell(posY, posX, NULL);
		swiat->setCell(newY, newX, this);
		this->posX = newX;
		this->posY = newY;
	}
}

void Zwierze::akcja() {
	size_t newX, newY;
	this->getNewYX(&newY,&newX,1);
	this->move(newY, newX);
}

void Zwierze::kolizja(Organizm* attacker) {
	if (!this->proliferation(attacker)) {
		Game::addLogs(attacker->getName() + '(' + std::to_string(attacker->getX()) + ',' + std::to_string(attacker->getY()) + ')' + " zaatakowal " +
			this->name + '(' + std::to_string(this->getX()) + ',' + std::to_string(this->getY()) + ')');

		if (attacker->getSila() >= this->sila) {
			Swiat* temp = swiat;
			size_t newX = posX;
			size_t newY = posY;
			swiat->usunOrganizm(this);
			attacker->move(newY, newX);
			Game::addLogs(" wygrywajac\n");
		}
		else {
			swiat->usunOrganizm(attacker);
			Game::addLogs(" przegrywajac\n");
		}

	}
}