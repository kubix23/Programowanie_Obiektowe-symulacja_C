#include "swiat.h"
#include "Settings.h"
#include "Game.h"

using namespace std;

Swiat::Swiat(size_t sizeY, size_t sizeX) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->mapa = new Organizm*[sizeY * sizeX];
	for (size_t i = 0; i < sizeY; i++) {
		for (size_t j = 0; j < sizeX; j++) {
			setCell(i, j, NULL);
		}
	}
}

Swiat::Swiat(size_t sizeY, size_t sizeX, size_t age):
	Swiat(sizeY,sizeX){
	this->turn = age;
}

size_t Swiat::getX() {
	return sizeX;
}

size_t Swiat::getY() {
	return sizeY;
}

size_t Swiat::getTurn() {
	return turn;
}

Organizm* Swiat::getCell(size_t sizeY, size_t sizeX) {
	return mapa[sizeY * this->sizeX + sizeX];
}

size_t Swiat::getOrganizmySize() {
	return organizmy.size();
}

Organizm* Swiat::getOrganizm(size_t i) {
	return organizmy[i];
}

void Swiat::setCell(size_t sizeY, size_t sizeX, Organizm* organizm) {
	mapa[sizeY * this->sizeX + sizeX] = organizm;
}

void Swiat::wstawOrganizm(Organizm* organizm) {
	size_t i = 0;
	for (; i < organizmy.size(); i++) {
		if (organizm->getIniciatywa() > organizmy[i]->getIniciatywa())break;
		if (organizm->getIniciatywa() == organizmy[i]->getIniciatywa() && organizm->getWiek() > organizmy[i]->getWiek())break;
	}
	organizmy.insert(organizmy.begin() + i,organizm);
	setCell(organizm->getY(), organizm->getX(), organizm);
	organizm->setSwiat(this);
}

void Swiat::usunOrganizm(Organizm* organizm) {
	organizmy.erase(find(organizmy.begin(), organizmy.end(), organizm));
	setCell(organizm->getY(), organizm->getX(), NULL);
	delete organizm;
}

void Swiat::wykonajTure() {
	srand(static_cast<unsigned int>(time(NULL)));
	for (size_t i = 0; i < organizmy.size(); i++) {
		Organizm* temp = organizmy[i];
		temp->akcja();
		temp->yearOlder(TURN_OLD_AGE);	
	}
	this->turn++;
}

void Swiat::rysujSwiat() {
	for (size_t i = 0; i < sizeY; i++) {
		for (size_t j = 0; j < sizeX; j++) {
			if (getCell(i, j) != NULL) {
				getCell(i, j)->rysowanie();
			}
			else {
				cout << EMPTY_CELL;
			}
			cout << ' ';
		}
		cout << endl;
	}
	cout << "Tura: " << this->turn << endl;
	cout << Game::getLogs();
	Game::clearLogs();
}

Swiat::~Swiat() {
	if(this->mapa != NULL)delete[] this->mapa;
	for (size_t i = organizmy.size(); i > 0; i--) {
		delete organizmy.back();
		organizmy.pop_back();
	}
}