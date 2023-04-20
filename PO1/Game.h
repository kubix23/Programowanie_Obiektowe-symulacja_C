#pragma once
#include "Swiat.h"
#include "Czlowiek.h"
#include "SaveLoad.h"
#include <string> 

class Game
{
private:
	Swiat* swiat;
	Czlowiek* czlowiek;
	SaveLoad* saveLoad;
	static std::string logs;
public:
	Game(Swiat* swiat, Czlowiek* czlowiek, SaveLoad* saveLoad);
	Swiat* getSwiat();
	Czlowiek* getCzlowiek();
	SaveLoad* getSaveLoad();
	void setSwiat(Swiat* swiat);
	void setCzlowiek(Czlowiek* czlowiek);
	void setSaveLoad(SaveLoad* saveLoad);
	void run();
	static void addLogs(std::string s);
	static std::string getLogs();
	static void clearLogs();
};

