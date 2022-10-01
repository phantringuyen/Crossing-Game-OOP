#include "cPlayer.h"
cPlayer::cPlayer(COORD start_point, short speed, bool stat)
{
	X = start_point.X;
	Y = start_point.Y;
	state = stat;
	SPEED = speed;
}
short cPlayer::Get_X()
{
	return X;
}
short cPlayer::Get_Y()
{
	return Y;
}
short cPlayer::Get_Speed()
{
	return SPEED;
}
short cPlayer::Get_State()
{
	return state;
}
void cPlayer::Set_X(short x)
{
	X = x;
}
void cPlayer::Set_Y(short y)
{
	Y = y;
}
void cPlayer::setPosition(short x, short y)
{
	X = x;
	Y = y;
}
void cPlayer::Up()
{
	Y -= 0 * SPEED;
}
void cPlayer::Down()
{
	Y += SPEED;
}
void cPlayer::Right()
{
	X += 2 * SPEED;
}
void cPlayer::Left()
{
	X -= 2 * SPEED;
}

void cPlayer::Draw()
{
	Graphics::DrawGraphics(GetStdHandle(STD_OUTPUT_HANDLE), "character.txt", COORD{ X,Y }, (int)Color::lightred);
}
void cPlayer::Clear()
{
	Graphics::CleanArea(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ X,Y }, COORD{ (short)(X + WIDTH_CAT),(short)(Y + HEIGH_CAT) });
}
bool cPlayer::isDead()
{
	return state == false;
}

bool cPlayer::isImpactTruck(cTruck* p, int lv) // blue
{
	for (int i = 0; i < lv; i++)
	{
		int x = p[i].Get_X(), y = p[i].Get_Y();
		if ((x <= X && X <= x + 12) && (y <= Y && Y <= y + 4))
		{
			state = false;
			return true;
		}
	}
	return false;
}

bool cPlayer::isImpactCar(cCar* p, int lv)
{
	for (int i = 0; i < lv; i++)
	{
		int x = p[i].Get_X(), y = p[i].Get_Y();
		if ((x <= X && X <= x + 12) && (y <= Y && Y <= y + 4))
		{
			state = false;
			return true;
		}
	}
	return false;
}

bool cPlayer::isImpactBird(cBird* p, int lv)
{
	for (int i = 0; i < lv; i++)
	{
		int x = p[i].Get_X(), y = p[i].Get_Y();
		if ((x <= X && X <= x + 6) && (y <= Y && Y <= y + 3))
		{
			state = false;
			return true;
		}
	}
	return false;
}

bool cPlayer::isImpactDinosaur(cDinosaur* p, int lv)
{
	for (int i = 0; i < lv; i++)
	{
		int x = p[i].Get_X(), y = p[i].Get_Y();
		if ((x <= X && X <= x + 10) && (y <= Y && Y <= y + 3))
		{
			state = false;
			return true;
		}
	}
	return false;
}

bool cPlayer::isFinish()
{
	return Y >= 36;
}
void cPlayer::Set_State(bool a)
{
	state = a;
}
void cPlayer::Set_Speed(short s)
{
	SPEED = s;
}