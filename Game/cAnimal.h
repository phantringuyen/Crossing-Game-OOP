#pragma once
#include "Graphics.h"
class cAnimal 
{
protected:
	short X;// x va y la diem khoi dau cua xe
	short Y;
public:
	cAnimal();
	cAnimal(short x, short y);
	short Get_X();
	short Get_Y();
	void Set_X(short x);
	void Set_Y(short y);
	void setPosition(short x, short y);
	virtual void Move() = 0;
	virtual void Draw() = 0;
	void Clear(short x, short y);
};