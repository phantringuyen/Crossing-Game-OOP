#pragma once
#include "Game.h"

Game::Game() {}

Game::Game(int w, int h, const wchar_t* title, bool f, Color color)
{
	console = new Console(w, h, title, f, color);
}

void Game::RunApplication()
{
	menu = new Menu();
	while (true)
	{
		menu->DrawMenu();
		menu->MoveMenu();
	}
}

Game::~Game()
{
	delete menu;
	delete console;
}
