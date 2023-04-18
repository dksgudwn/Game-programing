#include "StartScene.h"
#include<iostream>
#include<Windows.h>
#include<io.h>
#include<fcntl.h>
#include "console.h"
#include <conio.h>

using namespace std;

void GameTitle()
{
	int curMode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"██████╗  ██████╗ ███╗   ███╗██████╗ ███╗   ███╗ █████╗ ███╗   ██╗" << "\n";
	wcout << L"██╔══██╗██╔═══██╗████╗ ████║██╔══██╗████╗ ████║██╔══██╗████╗  ██║" << "\n";
	wcout << L"██████╔╝██║   ██║██╔████╔██║██████╔╝██╔████╔██║███████║██╔██╗ ██║" << "\n";
	wcout << L"██╔══██╗██║   ██║██║╚██╔╝██║██╔══██╗██║╚██╔╝██║██╔══██║██║╚██╗██║" << "\n";
	wcout << L"██████╔╝╚██████╔╝██║ ╚═╝ ██║██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║" << "\n";
	wcout << L"╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝" << "\n";
	_setmode(_fileno(stdout), curMode);

}

int KeyController()
{
	// cin, _getch(),  _kbhit(), GetAsyncKeyState()
	/*if (GetAsyncKeyState(VK_UP) & 0x8000)
		return (int)KEY::UP;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		return (int)KEY::DOWN;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
		return (int)KEY::SPACEBAR;
	Sleep(50);*/

	int iChk = _getch();
	if (iChk == 224)
	{
		iChk = _getch();
		switch (iChk)
		{
		case 72:
		{
			return (int)KEY::UP;
		}
		break;
		case 80:
		{
			return (int)KEY::DOWN;
		}
		break;
		}
	}
	else if (iChk == 32)
	{
		return (int)KEY::SPACEBAR;
	}
	return -1;
}

void GameInfo()
{
	system("cls");
	cout << endl << endl;
	cout << "[조작법]" << endl;
	cout << "메뉴 이동: 방향키" << endl;
	cout << "메뉴 선택: 스페이스바" << endl;
	cout << "플레이어 이동: 방향키" << endl;
	cout << "폭탄 설치: 스페이스바, E: 푸시능력 ON/OFF" << endl;
	//TO DO LIST: 아이템이 무슨 아이템인지 여기다 적어주자.

	while (true)
	{
		if (KeyController() == (int)KEY::SPACEBAR)
			return;
	}
}

int MenuDraw()
{
	int x = 30;
	int y = 12;
	Gotoxy(x, y);
	cout << "게임 시작";
	Gotoxy(x, y + 1);
	cout << "게임 정보";
	Gotoxy(x, y + 2);
	cout << "종료 하기";

	// 내 키 입력에 따라 >(꺾새)를 이동할겁니다.
	while (true)
	{
		int iKey = KeyController();
		switch (iKey)
		{
		case (int)KEY::UP:
		{
			if (y > 12)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		}
		case (int)KEY::DOWN:
		{
			if (y < 14)
			{
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		}
		case (int)KEY::SPACEBAR:
		{
			return y - 12;
		}
		break;
		}
		Sleep(100);
	}
	return 0;
}
