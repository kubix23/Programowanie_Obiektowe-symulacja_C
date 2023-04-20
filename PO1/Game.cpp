#include "Game.h"
#include <Windows.h>
#include "Settings.h"

std::string Game::logs = "";

Game::Game(Swiat* swiat, Czlowiek* czlowiek, SaveLoad* saveLoad) {
	setSwiat(swiat);
	setCzlowiek(czlowiek);
	setSaveLoad(saveLoad);
}

Swiat* Game::getSwiat() {
	return swiat;
}

Czlowiek* Game::getCzlowiek() {
	return czlowiek;
}

SaveLoad* Game::getSaveLoad() {
	return saveLoad;
}

void Game::setSwiat(Swiat* swiat) {
	if (swiat == NULL)return;
	if(this->saveLoad != NULL)this->saveLoad->setSwiat(swiat);
	for (size_t i = 0; i < swiat->getOrganizmySize(); i++) {
		Organizm* temp = swiat->getOrganizm(i);
		if (typeid(*temp) == typeid(Czlowiek)) {
			czlowiek->setSwiat(swiat);
			this->czlowiek = (Czlowiek*)temp;
			break;
		}
	}
	delete this->swiat;
	this->swiat = swiat;
}

void Game::setCzlowiek(Czlowiek* czlowiek) {
	if(this->czlowiek != NULL)swiat->usunOrganizm(this->czlowiek);
	czlowiek->setSwiat(swiat);
	swiat->wstawOrganizm(czlowiek);
	this->czlowiek = czlowiek;
}

void Game::setSaveLoad(SaveLoad* saveLoad) {
	delete this->saveLoad;
	saveLoad->setSwiat(swiat);
	this->saveLoad = saveLoad;
}

void Game::run() {
    bool move = false;
    while (true) {
        if (GetKeyState(VK_LEFT) & 0x8000) {
            czlowiek->moveSpeedYX(0, -1);
            move = true;
        }
        if (GetKeyState(VK_UP) & 0x8000) {
            czlowiek->moveSpeedYX(-1, 0);
            move = true;
        }
        if (GetKeyState(VK_RIGHT) & 0x8000) {
            czlowiek->moveSpeedYX(0, 1);
            move = true;
        }
        if (GetKeyState(VK_DOWN) & 0x8000) {
            czlowiek->moveSpeedYX(1, 0);
            move = true;
        }
        if (GetKeyState(VK_DOWN) & 0x8000) {
            czlowiek->moveSpeedYX(1, 0);
            move = true;
        }
        if (GetKeyState(VK_ESCAPE) & 0x8000) {
            break;
        }
        if (GetKeyState(SKILL_KEY) & 0x8000) {
            system("cls");
            czlowiek->skill();
            swiat->rysujSwiat();
        }
        if (GetKeyState(SAVE_KEY) & 0x8000) {
            saveLoad->saveGame();
            system("cls");
            swiat->rysujSwiat();
        }
        if (GetKeyState(LOAD_KAY) & 0x8000) {
            system("cls");
            setSwiat(saveLoad->loadGame());
            swiat->rysujSwiat();
        }
        if (move || !true) {
            system("cls");
            swiat->wykonajTure();
            swiat->rysujSwiat();
        }
        Sleep(100);
        move = false;
    }
}

void Game::addLogs(std::string s) {
	logs += s;
}

std::string Game::getLogs() {
	return logs;
}

void Game::clearLogs() {
	logs = "";
}