#pragma once
#include "cPlayer.h"
#include "TrafficLight.h"
#include <iostream>
#include <conio.h>
#include <thread>
#include <mmsystem.h>
#include <fstream>
#include <Windows.h>
#include <string>
using namespace std;
#define START_GAME_POINT { 0,19 }
#define END_GAME_POINT { 130,37 }
#define START_PLAYER_POINT {75,15}
#define LEFT 0
#define RIGHT 130
#define TOP 19
#define BOTTOM 35
using namespace std;

class cGame
{
private:
	static cGame* instance;
	cTruck* truck;
	cCar* car;
	cPlayer* player;
	cBird* bird;
	cDinosaur* dinosaur;
	bool quit = false;
	int score;
	char MOVING;
	unsigned int curAN;
	unsigned int curVH;
	unsigned int level;

	TrafficLight* lights;
	bool init = true;
	cGame();
public:
	static cGame* getInstance() {
		if (instance == NULL) instance = new cGame();
		return instance;
	}
	static void deleteInstance() {
		if (instance != NULL) delete instance;

	}
	void DrawGame();
	void StartGame();
	void ResumeGame(HANDLE);
	void PauseGame(HANDLE);
	void ExitGame(thread*);
	void UpdatePosPlayer(char);
	void UpdatePosVehicle();
	void UpdatePosAnimal();
	void SaveGame();
	void LoadGame();
	void LevelUp();
	void RunGame();
	HANDLE ohandle = GetStdHandle(STD_OUTPUT_HANDLE);
	void printTrafficLights();
	void deleteObject() {
		if (lights != nullptr) delete lights;
		if (player != nullptr) delete player;
		if (truck != nullptr)delete[]truck;
		if (car != nullptr)delete[]car;
		if (bird != nullptr)delete[]bird;
		if (dinosaur != nullptr)delete[]dinosaur;
	}
};