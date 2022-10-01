#pragma once
#include "cAnimal.h"
class cBird :public cAnimal
{
private:
	short speed;
public:
	cBird();
	cBird(short x, short y, short s);
	void set_speed(short s);
	void Move() override;
	void Draw();
	short get_speed();
};