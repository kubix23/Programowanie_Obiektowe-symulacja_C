#include "Organizm.h"
#include "Settings.h"
#include "Game.h"

#include <iostream>

using namespace std;

Organizm::Organizm(std::string name, int sila, int iniciatywa, size_t posX, size_t posY, char symbol, size_t wiek, Swiat* swiat) {
	this->name = name;
	this->sila = sila;
	this->iniciatywa = iniciatywa;
	this->posX = posX;
	this->posY = posY;
	this->symbol = symbol;
	this->wiek = wiek;
	this->swiat = swiat;
}

int Organizm::getSila() {
	return sila;
}

int Organizm::getIniciatywa() {
	return iniciatywa;
}

int Organizm::getWiek() {
	return wiek;
}

size_t Organizm::getX() {
	return posX;
}

size_t Organizm::getY() {
	return posY;
}

string Organizm::getName() {
	return name;
}

void Organizm::setSila(int sila) {
	this->sila = sila;
}

void Organizm::setSwiat(Swiat* swiat) {
	this->swiat = swiat;
}

void Organizm::setX(size_t x) {
	this->posX = x;
}

void Organizm::setY(size_t y) {
	this->posY = y;
}

void Organizm::getNewYX(size_t* newY, size_t* newX, short range) {
	do {
		*newX = posX + ((rand() % ((range * 2) + 1)) - range);
		*newY = posY + ((rand() % ((range * 2) + 1)) - range);
	} while (*newX >= swiat->getX() || *newX < 0 ||
		*newY >= swiat->getY() || *newY < 0 ||
		(*newX == posX && *newY == posY));
}

void Organizm::yearOlder(short years) {
	wiek += years;
}

void Organizm::rysowanie() {
	cout << symbol;
}

bool Organizm::proliferation(Organizm* attacker) {
	if (typeid(*this) == typeid(*attacker) && this->wiek >= MATURITY && attacker->wiek >= MATURITY && rand()%(wiek) < sqrt(wiek)) {
		size_t newX, newY, i = 0;
		do {
			getNewYX(&newY, &newX, 1);
			i++;
		} while (swiat->getCell(newY, newX) != NULL && i < TIMEOUT_NUMBER);
		if (i < TIMEOUT_NUMBER) {
			Organizm* temp = this->scion();
			temp->setX(newX);
			temp->setY(newY);
			swiat->wstawOrganizm(temp);
			Game::addLogs(this->name + '(' + std::to_string(this->getX()) + ',' + std::to_string(this->getY()) + ')' + " rozmnozyl sie z " +
				attacker->name + '(' + std::to_string(attacker->getX()) + ',' + std::to_string(attacker->getY()) + ')' + " rodzac " +
				temp->name + '(' + std::to_string(temp->getX()) + ',' + std::to_string(temp->getY()) + ')' + '\n');
		}
	}
	if(!(typeid(*this) == typeid(*attacker)))return false;
	return true;
}

void Organizm::assign(Organizm* old) {
	this->sila = old->sila;
	this->iniciatywa = old->iniciatywa;
	this->posX = old->posX;
	this->posY = old->posY;
	this->symbol = old->symbol;
	this->wiek = old->wiek;
}