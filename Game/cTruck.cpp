#include "cTruck.h"
cTruck::cTruck() :cVehicle() { speed = 0; }
cTruck::cTruck(short x, short y, short s) :cVehicle(x, y) { speed = s; }
void cTruck::set_speed(short s) { speed = s; }
void cTruck::Move()
{
	Clear(X + speed, Y + 4);
	X += speed;
	Draw();
}

void cTruck::Draw()
{
	Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "truck.txt", COORD{ X,Y }, (int)Color::lightblue);
}
short cTruck::get_speed() { return speed; }