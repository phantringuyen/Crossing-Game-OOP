#include "cBird.h"
cBird::cBird() :cAnimal() { speed = 0; }
cBird::cBird(short x, short y, short s) :cAnimal(x, y)
{
	speed = s;
}
void cBird::set_speed(short s) { speed = s; }
void cBird::Move() 
{
	Clear(X + 6, Y + 3);
	X += speed;
	Draw();
}

void cBird::Draw()
{
	Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "bird.txt", COORD{ X,Y }, (int)Color::lightpurple);
}
short cBird::get_speed() { return speed; }