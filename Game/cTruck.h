#pragma once
#include "cVehicle.h"
class cTruck :public cVehicle
{
private:
	short speed;
public:
	cTruck();
	cTruck(short x, short y, short s);
	void set_speed(short s);
	void Move();
	void Draw();
	short get_speed();
};