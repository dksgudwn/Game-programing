#include<iostream>
#include<Windows.h>
#include<conio.h>
#include "console.h"
using namespace std;

int main()
{
	////system("calc");
	////system("notepad");
	////system("title Bombman");
	////SetConsoleTitle(Text("d Bombman"));
	//system("mode con cols=50 lines=25 | title Bombman");
	////exit(0);
	//Gotoxy(10, 10);
	//cout << "Hello World!" << endl;
	//Sleep(1000);
	//int oldcolor = GetColor() | (GetbgColor() << 4);
	//for (int i = 0; i < 15; i++)
	//{
	//	Gotoxy(i, i);
	//	SetColor(i, 0);
	//	cout << "color number";
	//	SetColor(oldcolor, oldcolor >> 4);
	//	cout << i << endl;
	//}
	//Cursorset(false, 1);

	//int a = 0;
	//cin >> a;
	int test;
	int x = 0, y = 0;
	while (true)
	{
		if (_kbhit())
		{
			Gotoxy(x, y);
			_putch('a');
			if (GetAsyncKeyState(VK_UP) & 0x8000) y--;
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)y++;
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)x--;
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)x++;
			Sleep(50);


			//test = _getch();
			//switch (test)
			//{
			//case 72:
			//	//cout << "위쪽" << endl;
			//	y--;
			//	break;
			//case 75:
			//	//cout << "왼쪽" << endl;
			//	x--;
			//	break;
			//case 77:
			//	//cout << "오른쪽" << endl;
			//	x++;
			//	break;
			//case 80:
			//	//cout << "아래쪽" << endl;
			//	y++;
			//	break;
			//default:
			//	break;
			//}
		}

	}
}