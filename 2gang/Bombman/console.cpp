#include "console.h"

void FullScreen()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(hOut, CONSOLE_FULLSCREEN_MODE, NULL);
}

void Gotoxy(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x,y };
	SetConsoleCursorPosition(hOut, Cur);
}

BOOL Gotoxytest(int x, int y)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Cur = { x,y };
	return SetConsoleCursorPosition(hOut, Cur);
}

void Cursorset(bool _bVis, DWORD _dwSize)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Curinfo;
	Curinfo.bVisible = _bVis;
	Curinfo.dwSize = _dwSize;
	SetConsoleCursorInfo(hOut, &Curinfo);
}

void SetColor(int _color, int _bgColor)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, (_bgColor << 4) | _color);
}

int GetColor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hOut, &info);
	int color = info.wAttributes & 0xf;
	return color;
}

int GetbgColor()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(hOut, &info);
	int color = (info.wAttributes & 0xf) >> 4;
	return color;
}

void fontsize(UINT _weight, UINT _sizex, UINT _sizey)
{
	static CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hout, false, &font);
	font.FontWeight = _weight;
	font.dwFontSize.X = _sizex;
	font.dwFontSize.Y = _sizey;
	SetCurrentConsoleFontEx(hout, false, &font);
}