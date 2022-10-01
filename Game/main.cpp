#include <iostream>
#include "Game.h"
#pragma execution_character_set("utf-8")
cGame* cGame::instance = NULL;
int main()
{
    Game* game = new Game(1244, 870, L"ROSSING GAME", false, Color::yellow);
    game->RunApplication();
    system("pause > nul");
    return 0;
}