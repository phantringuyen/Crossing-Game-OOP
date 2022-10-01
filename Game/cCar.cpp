#include "cCar.h"
cCar::cCar() :cVehicle() { speed = 0; }
cCar::cCar(short x, short y, short s) :cVehicle(x, y)
{
	speed = s;
}
void cCar::set_speed(short s) { speed = s; }
short cCar::get_speed() { return speed; }
void cCar::Move() 
{
	Clear(X + speed, Y + 4);
	X += speed;
	Draw();
}

void cCar::Draw()
{
	Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "car.txt", COORD{ X,Y }, (int)Color::lightyellow);
}