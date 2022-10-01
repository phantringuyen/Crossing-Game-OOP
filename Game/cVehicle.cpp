#include "cVehicle.h"
cVehicle::cVehicle() { X = Y = 0; }
cVehicle::cVehicle(short x, short y)
{
	X = x;
	Y = y;
}
short cVehicle::Get_X() { return X; }
short cVehicle::Get_Y() { return Y; }

void cVehicle::Set_X(short x)
{
	X = x;
}
void cVehicle::Set_Y(short y)
{
	Y = y;
}
void cVehicle::setPosition(short x, short y)
{
	X = x;
	Y = y;
}
void cVehicle::Clear(short x, short y)
{
	Graphics::CleanArea(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ X,Y }, COORD{ x,y });
}