#pragma once
#include "cAnimal.h"
class cDinosaur :public cAnimal
{
private:
	short speed;
public:
	cDinosaur();
	cDinosaur(short x, short y, short s);
	void set_speed(short s);
	void Move();
	void Draw();
	short get_speed();
};