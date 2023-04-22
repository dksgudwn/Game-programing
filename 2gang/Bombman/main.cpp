#include<iostream>
#include<Windows.h>
#include<io.h>
#include<vector>
#include<fcntl.h>
#include"StartScene.h"
#include"GameLogic.h"
#include "console.h"

using namespace std;

int main()
{
	char cMaze[VERTICAL][HORIZON] = {};
	PLAYER tPlayer = {};
	POS tStartpos = {};
	POS tEndpos = {};
	vector<BOOM> vecBomb;
	vector<POS> boomEffect;
	Init(cMaze, &tPlayer, &tStartpos, &tEndpos);
	//시작씬 만들기.
	while (true)
	{
		system("cls");
		GameTitle();
		int iMenu = MenuDraw();
		if (iMenu == 0)
		{
			break;
		}
		else if (iMenu == 1)
			GameInfo();
		else if (iMenu == 2)
		{
			//게임종료
			cout << "게임을 종료합니다." << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << '\r' << 3 - i << "...";
				Sleep(1000);
			}
			return 0;

		}
	}
	system("cls");
	//게임 로직
	while (true)
	{
		Gotoxy(0, 0);
		Render(cMaze, &tPlayer, boomEffect);
		Update(cMaze, &tPlayer, vecBomb, boomEffect);

	}

}
