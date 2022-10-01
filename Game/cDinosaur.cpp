#include "cDinosaur.h"
cDinosaur::cDinosaur() :cAnimal() { speed = 0; }
cDinosaur::cDinosaur(short x, short y, short s) :cAnimal(x, y)
{
	speed = s;
}
void cDinosaur::set_speed(short s) { speed = s; }
void cDinosaur::Move()
{
	Clear(X + 12, Y + 4);
	X += speed;
	Draw();
}

void cDinosaur::Draw()
{
	Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "dinosaur.txt", COORD{ X,Y }, (int)Color::lightgreen);
}
short cDinosaur::get_speed() { return speed; }