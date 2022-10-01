#include "cAnimal.h"
cAnimal::cAnimal() { X = Y = 0; }
cAnimal::cAnimal(short x, short y)
{
	X = x;
	Y = y;
}
short cAnimal::Get_X()
{
	return X;
}
short cAnimal::Get_Y()
{
	return Y;
}
void cAnimal::Set_X(short x)
{
	X = x;
}
void cAnimal::Set_Y(short y)
{
	Y = y;
}
void cAnimal::setPosition(short x, short y)
{
	X = x;
	Y = y;
}
void cAnimal::Clear(short x, short y)
{
	Graphics::CleanArea(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ X,Y }, COORD{ x,y });
}