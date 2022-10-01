#pragma once
#include "Graphics.h"
#include "cVehicle.h"
#include "cTruck.h"
#include "cCar.h"
#include "cAnimal.h"
#include "cDinosaur.h"
#include "cBird.h"
#include "Console.h"
#define HEIGH_CAT 2//CHIEU CAO MEO
#define WIDTH_CAT 5//CHIEU DAI MEO

class cPlayer
{
private:
	short X, Y;
	bool state;
	int SPEED;
public:
	cPlayer(COORD start_point, short speed, bool stat);
	short Get_X();
	short Get_Y();
	short Get_Speed();
	short Get_State();
	void Set_X(short x);
	void Set_Y(short y);
	void setPosition(short x, short y);
	void Up();
	void Down();
	void Right();
	void Left();
	void Draw();
	void Clear();
	bool isDead();
	bool isImpactTruck(cTruck* p, int lv);
	bool isImpactCar(cCar* p, int lv);
	bool isImpactBird(cBird* p, int lv);
	bool isImpactDinosaur(cDinosaur* p, int lv);

	bool isFinish();
	void Set_State(bool a);
	void Set_Speed(short s);
};
