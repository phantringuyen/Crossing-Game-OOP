#include "Graphics.h"

void Graphics::SetColor(HANDLE hwnd, int color)
{
	SetConsoleTextAttribute(hwnd, color);
}

void Graphics::DrawGraphics(HANDLE handle, std::string filename, COORD pointer, int color)
{
	std::string str;
	std::ifstream inp(filename);
	SetColor(handle, color);
	while (!inp.eof())
	{
		std::getline(inp, str);
		GotoXY(handle, pointer);
		std::cerr << str;
		pointer.Y++;
	}
	inp.close();
}

void Graphics::GotoXY(HANDLE hwnd, COORD pos)
{
	SetConsoleCursorPosition(hwnd, pos);
}

void Graphics::DrawTexts(HANDLE handle, std::string str, COORD pointer, int color)
{
	GotoXY(handle, pointer);
	SetColor(handle, color);
	std::cout << str;
}

void Graphics::CleanArea(HANDLE hwnd, COORD s_point, COORD e_point)
{
	for (SHORT x = s_point.X; x <= e_point.X; ++x)
	{
		for (SHORT y = s_point.Y; y <= e_point.Y; ++y)
		{
			GotoXY(hwnd, COORD{ x, y });
			std::cout << " ";
		}
		std::cout << "\n";
	}
}

SHORT Graphics::Checkey(int key)
{
	return SHORT(GetAsyncKeyState(int(key)) & 1 && GetKeyState(int(key)) >> 15);
}