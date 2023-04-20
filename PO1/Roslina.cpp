#include "Roslina.h"
#include <iostream>
#include "Settings.h"
#include "Game.h"
#include <string> 

using namespace std;

void Roslina::move(size_t& newY, size_t& newX) {};

void Roslina::akcja() {
	if (rand()%PLANT_CHANCE == 0) {
		this->proliferation(this);
	}
}

void Roslina::kolizja(Organizm* attacker) {
	Game::addLogs(attacker->getName() + '(' + std::to_string(attacker->getX()) + ',' + std::to_string(attacker->getY()) + ')' + " zblizyl sie do " +
		this->name + '(' + std::to_string(this->getX()) + ',' + std::to_string(this->getY()) + ')');

	if (attacker->getSila() >= this->sila) {
		Swiat* temp = swiat;
		size_t newX = posX;
		size_t newY = posY;
		swiat->usunOrganizm(this);
		attacker->move(newY, newX);
		Game::addLogs(" i go zjadl\n");
	}
	else {
		swiat->usunOrganizm(attacker);
		Game::addLogs(" i przegral z roslina\n");
	}
}