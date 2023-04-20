#include <iostream>
#include <fstream>

#include "BarszczSosnowskiego.h"
#include "Lis.h"
#include "Owca.h"
#include "Antylopa.h"
#include "Zolw.h"

#include "Czlowiek.h"

#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "Wilcza_jagoda.h"
#include "Wilk.h"

#include "swiat.h"
#include "SaveLoad.h"
#include "Game.h"
#include "Settings.h"
#include <Windows.h>

using namespace std;

int main()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);


    Game game(new Swiat(WORLD_Y, WORLD_X), new Czlowiek(0, 0, NULL), new SaveLoad(NULL));

    game.getSwiat()->wstawOrganizm(new Wilk(3, 4, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilk(4, 4, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilk(5, 12, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilk(6, 12, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilk(7, 12, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilk(8, 12, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilk(9, 12, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilcza_jagoda(1, 2, game.getSwiat()));
    game.getSwiat()->wstawOrganizm(new Wilcza_jagoda(1, 4, game.getSwiat()));

    game.getSwiat()->rysujSwiat();
    game.run();

    return 0;
}
