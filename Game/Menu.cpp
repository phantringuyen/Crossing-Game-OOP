#include "Menu.h"
#include "Graphics.h"
#include "Console.h"

//MENU
Menu::Menu() {
	a = cGame::getInstance();
}

void Menu::PlayMusic()
{
	if (flagmusic)
	{
		PlaySound(L"BackGroundMS.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	}
	else
	{
		PlaySound(0, NULL, NULL);
	}
}

void Menu::PauseMusic()
{
	if (flagmusic)
	{
		flagmusic = false;
		PlaySound(0,NULL,NULL);
	}
	else
	{
		flagmusic = true;
		PlaySound(L"BackGroundMS.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);
	}
}

void Menu::DrawMenu()
{
	PlayMusic();
	Graphics::DrawGraphics(ohandle, "brand.txt", COORD{ 3,2 }, (int)Color::yellow);
	Graphics::DrawGraphics(ohandle, "menu.txt", COORD{ 35 ,3 }, (int)Color::lightaqua);
}

void Menu::MoveMenu()
{
	Graphics::DrawTexts(ohandle, " NEW GAME ", COORD{ 77,24 }, 240);
	int y = 1;
	while (true)
	{
		if (Graphics::Checkey(VK_DOWN) || Graphics::Checkey(VK_RIGHT))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			Graphics::DrawTexts(ohandle, " NEW GAME ", COORD{ 77,24 }, 11);
			Graphics::DrawTexts(ohandle, " LOAD GAME ", COORD{ 77,25 }, 11);
			Graphics::DrawTexts(ohandle, " OPTIONS ", COORD{ 77,26 }, 11);
			Graphics::DrawTexts(ohandle, " EXIT ", COORD{ 77,27 }, 11);
			if (y < 4)
				++y;
			else
				y = 1;
			if (y == 1) Graphics::DrawTexts(ohandle, " NEW GAME ", COORD{ 77,24 }, 240);
			if (y == 2) Graphics::DrawTexts(ohandle, " LOAD GAME ", COORD{ 77,25 }, 240);
			if (y == 3) Graphics::DrawTexts(ohandle, " OPTIONS ", COORD{ 77,26 }, 240);
			if (y == 4) Graphics::DrawTexts(ohandle, " EXIT ", COORD{ 77,27 }, 240);
		}
		if (Graphics::Checkey(VK_UP) || Graphics::Checkey(VK_LEFT))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			Graphics::DrawTexts(ohandle, " NEW GAME ", COORD{ 77,24 }, 11);
			Graphics::DrawTexts(ohandle, " LOAD GAME ", COORD{ 77,25 }, 11);
			Graphics::DrawTexts(ohandle, " OPTIONS ", COORD{ 77,26 }, 11);
			Graphics::DrawTexts(ohandle, " EXIT ", COORD{ 77,27 }, 11);
			if (y > 1)
				--y;
			else
				y = 4;
			if (y == 1) Graphics::DrawTexts(ohandle, " NEW GAME ", COORD{ 77,24 }, 240);
			if (y == 2) Graphics::DrawTexts(ohandle, " LOAD GAME ", COORD{ 77,25 }, 240);
			if (y == 3) Graphics::DrawTexts(ohandle, " OPTIONS ", COORD{ 77,26 }, 240);
			if (y == 4) Graphics::DrawTexts(ohandle, " EXIT ", COORD{ 77,27 }, 240);
		}

		if (Graphics::Checkey(VK_RETURN))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			LoadStateMenu(y);
			break;
		}
		else if (Graphics::Checkey(0x4E))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			PauseMusic();
			break;
		}
		else if (Graphics::Checkey(0x4C))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			break;
		}
		else if (Graphics::Checkey(0x4F))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			DrawOption();
			break;
		}
		else if (Graphics::Checkey(0x45))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			DrawExit();
			exit(0);
			break;
		}

	}
}

void Menu::LoadStateMenu(short y)
{
	if (y == 1)
	{
		PauseMusic();
		a->StartGame();
		a->RunGame();
	}
	else if (y == 2) {
		PauseMusic();
		a->LoadGame();
		a->RunGame();
	}
	else if (y == 3)
	{
		DrawOption();
	}
	else if (y == 4)
	{
		DrawExit();
		exit(0);
	}

}

//OPTION
void Menu::DrawOption()
{
	Graphics::SetColor(ohandle, 0);
	Graphics::CleanArea(ohandle, COORD{ 0,0 }, COORD{ 100,100 });
	Graphics::DrawGraphics(ohandle, "Option.txt", COORD{ 50,10 }, 11);

	if (flagmusic == false)
	{
		Graphics::DrawTexts(ohandle, " OFF", COORD{ 84,20 }, 11);
	}
	else
	{
		Graphics::DrawTexts(ohandle, " ON ", COORD{ 84,20 }, 11);
	}

	MoveOption();
}

void Menu::MoveOption()
{
	Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 240);
	short ytmp = 1;
	while (true)
	{
		if (Graphics::Checkey(VK_DOWN))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 11);
			Graphics::DrawTexts(ohandle, " RETURN ", COORD{ 77,22 }, 11);
			if (ytmp < 2)
				++ytmp;
			else
				ytmp = 1;
			if (ytmp == 1)
				Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 240);
			if (ytmp == 2)
				Graphics::DrawTexts(ohandle, " RETURN ", COORD{ 77,22 }, 240);
		}

		else if (Graphics::Checkey(VK_UP))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);

			Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 11);
			Graphics::DrawTexts(ohandle, " RETURN ", COORD{ 77,22 }, 11);
			if (ytmp > 1)
				--ytmp;
			else
				ytmp = 2;

			if (ytmp == 1)
				Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 240);
			if (ytmp == 2)
				Graphics::DrawTexts(ohandle, " RETURN ", COORD{ 77,22 }, 240);
		}
		else if (Graphics::Checkey(VK_RETURN))
		{
			mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
			LoadStateOption(ytmp);
		}
	}
}

void Menu::LoadStateOption(short& ytmp)
{
	if (ytmp == 1)
	{
		Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 11);
		if (flagmusic == false)
			Graphics::DrawTexts(ohandle, " OFF", COORD{ 84,20 }, 240);
		else
			Graphics::DrawTexts(ohandle, " ON ", COORD{ 84,20 }, 240);

		while (true)
		{
			if (Graphics::Checkey(VK_RETURN))
			{
				if (flagmusic == true)
				{
					PauseMusic();
					Graphics::DrawTexts(ohandle, " OFF", COORD{ 84,20 }, 240);
				}
				else
				{
					PauseMusic();
					Graphics::DrawTexts(ohandle, " ON ", COORD{ 84,20 }, 240);
				}
			}
			else if (Graphics::Checkey(VK_DOWN))
			{
				mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
				if (flagmusic == false) Graphics::DrawTexts(ohandle, " OFF", COORD{ 84,20 }, 11);
				else Graphics::DrawTexts(ohandle, " ON ", COORD{ 84,20 }, 11);
				if (ytmp < 2)
					++ytmp;
				else
					ytmp = 1;
				if (ytmp == 1) Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 240);
				if (ytmp == 2) Graphics::DrawTexts(ohandle, " RETURN ", COORD{ 77,22 }, 240);
				return;
			}

			else if (Graphics::Checkey(VK_UP))
			{
				mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
				if (flagmusic == false) Graphics::DrawTexts(ohandle, " OFF", COORD{ 84,20 }, 11);
				else Graphics::DrawTexts(ohandle, " ON ", COORD{ 84,20 }, 11);
				if (ytmp > 1)
					--ytmp;
				else
					ytmp = 2;

				if (ytmp == 1) Graphics::DrawTexts(ohandle, " MUSIC ", COORD{ 74,20 }, 240);
				else if (ytmp == 2) Graphics::DrawTexts(ohandle, " RETURN ", COORD{ 77,22 }, 240);
				return;
			}
		}
	}

	else if (ytmp == 2)
	{
		mciSendString(L"play StepFoot.wav ", NULL, 0, NULL);
		Graphics::SetColor(ohandle, 0);
		Graphics::CleanArea(ohandle, COORD{ 0,0 }, COORD{ 100,100 });
		DrawMenu();
		MoveMenu();
	}
}

//EXIT
void Menu::DrawExit()
{
	Graphics::SetColor(ohandle, 0);
	Graphics::CleanArea(ohandle, COORD{ 0,0 }, COORD{ 100,100 });
	Graphics::DrawGraphics(ohandle, "Exit.txt", COORD{ 35,3 }, (int)Color::lightblue);
}


