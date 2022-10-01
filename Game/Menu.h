#pragma once
#include "Console.h"
#include "Graphics.h"
#include "cPlayer.h"
#include "cVehicle.h"
#include "cGame.h"
#include <iostream>
using namespace std;

class Menu
{
private:
	cGame* a;
	bool flagmusic = true; // co nhac
public:
	Menu();

	void PlayMusic();
	void PauseMusic();
	
	void DrawMenu();
	void MoveMenu();
	void LoadStateMenu(short);

	void DrawOption();
	void MoveOption();
	void LoadStateOption(short&);

	void DrawExit();
	~Menu(){ cGame::deleteInstance(); }
	HANDLE ohandle = GetStdHandle(STD_OUTPUT_HANDLE);
};

