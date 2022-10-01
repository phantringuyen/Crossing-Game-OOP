#pragma once
#include "cVehicle.h"
class cCar :public cVehicle
{
private:
	short speed;
public:
	cCar();
	cCar(short x, short y, short s);
	void set_speed(short s);
	short get_speed();
	void Move();
	void Draw();
};