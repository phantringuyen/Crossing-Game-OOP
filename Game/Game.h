#pragma once
#include <fstream>
#include "Console.h"
#include "Graphics.h"
#include "Menu.h"
#include "TrafficLight.h"
class Game
{
private:
	Console *console;
	Menu* menu;
public:
	Game();
	Game(int, int, const wchar_t*, bool, Color);
	void RunApplication();
	~Game();
};

