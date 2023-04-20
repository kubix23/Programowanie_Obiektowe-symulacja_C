#pragma once
#include "Swiat.h"

class SaveLoad
{
private:
	Swiat* swiat;
public:
	SaveLoad(Swiat* swiat);
	void setSwiat(Swiat* swiat);
	void saveGame();
	Organizm* getObject(Organizm* temp);
	Swiat* loadGame();
};

