#include "SaveLoad.h"
#include "Czlowiek.h"
#include "Owca.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Zolw.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "Wilcza_jagoda.h"

#include <iostream>
#include <fstream>
#include "Settings.h"
#include "Game.h"

SaveLoad::SaveLoad(Swiat* swiat) {
	this->swiat = swiat;
}

void SaveLoad::setSwiat(Swiat* swiat) {
	this->swiat = swiat;
}

Organizm* SaveLoad::getObject(Organizm* temp) {
	Organizm* temp2 = NULL;
	if (temp->getName().compare("Czlowiek") == 0) {
		temp2 = new Czlowiek(0, 0, NULL);
	}
	else if (temp->getName().compare("Antylopa") == 0) {
		temp2 = new Antylopa(0, 0, NULL);
	}
	else if (temp->getName().compare("Lis") == 0) {
		temp2 = new Lis(0, 0, NULL);
	}
	else if (temp->getName().compare("Owca") == 0) {
		temp2 = new Owca(0, 0, NULL);
	}
	else if (temp->getName().compare("Wilk") == 0) {
		temp2 = new Wilk(0, 0, NULL);
	}
	else if (temp->getName().compare("Zolw") == 0) {
		temp2 = new Zolw(0, 0, NULL);
	}
	else if (temp->getName().compare("Barszcz") == 0) {
		temp2 = new BarszczSosnowskiego(0, 0, NULL);
	}
	else if (temp->getName().compare("Guarana") == 0) {
		temp2 = new Guarana(0, 0, NULL);
	}
	else if (temp->getName().compare("Mlecz") == 0) {
		temp2 = new Mlecz(0, 0, NULL);
	}
	else if (temp->getName().compare("Trawa") == 0) {
		temp2 = new Trawa(0, 0, NULL);
	}
	else if (temp->getName().compare("Wilcza_jagoda") == 0) {
		temp2 = new Wilcza_jagoda(0, 0, NULL);
	}
	return temp2;
}

void SaveLoad::saveGame() {
	std::ofstream file1;
	file1.open(DATA_FILE, std::ios::trunc| std::ios::binary);

	file1.write((char*)&(*swiat), sizeof(size_t) * 3);

	for (size_t i = 0; i < swiat->getOrganizmySize(); i++) {
		Organizm* temp = swiat->getOrganizm(i);
		size_t size = temp->size();
		file1.write((char*)&(size),sizeof(size));
		file1.write((char*)&(*temp), size);
	}
	Game::addLogs("ZAPISANO GRE\n");
	file1.close();
}

Swiat* SaveLoad::loadGame() {
	std::ifstream file2;
	size_t size;
	file2.open(DATA_FILE, std::ios::in | std::ios::binary);
	if (!file2.is_open())return NULL;

	file2.seekg(0);

	Swiat tempWorld(0, 0);
	file2.read((char*)&(tempWorld), sizeof(size_t) * 3);
	Swiat* newSwiat = new Swiat(tempWorld.getY(), tempWorld.getX(), tempWorld.getTurn());


	while (file2.read((char*)&(size), sizeof(size_t))) {
		Organizm* temp = (Organizm*)malloc(size);
		file2.read((char*)&(*temp), size);
		Organizm* temp2 = getObject(temp);
		if (temp2 != NULL) {
			temp2->assign(temp);
			newSwiat->wstawOrganizm(temp2);
		}
		free(temp);
	}
	file2.close();
	Game::addLogs("WCZYTANO GRE\n");

	return newSwiat;
}