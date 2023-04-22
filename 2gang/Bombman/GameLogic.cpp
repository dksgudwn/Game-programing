#include<iostream>
#include<Windows.h>
#include <algorithm>
#include <vector>
#include "GameLogic.h"
#include "console.h"
using namespace std;

void Init(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, PPOS _pStartpos, PPOS _pEndpos)
{
	system("mode con cols=80 lines=30");
	SetConsoleTitle(TEXT("2-3 Bomb man"));
	Cursorset(false, 1);
	//strcpy_s : string copy/0 벽, 1:길,2:시작,3:도착
	strcpy_s(_cMaze[0], "21111111111111111111");
	strcpy_s(_cMaze[1], "10001000010000001001");
	strcpy_s(_cMaze[2], "10001000010000001001");
	strcpy_s(_cMaze[3], "10001000010000101000");
	strcpy_s(_cMaze[4], "10001000010000101000");
	strcpy_s(_cMaze[5], "00001000010000101000");
	strcpy_s(_cMaze[6], "00001000010000101000");
	strcpy_s(_cMaze[7], "00001000010000101000");
	strcpy_s(_cMaze[8], "00001111110000101000");
	strcpy_s(_cMaze[9], "00001000010000101000");
	strcpy_s(_cMaze[10], "00001000010000101000");
	strcpy_s(_cMaze[11], "01111000010000101000");
	strcpy_s(_cMaze[12], "01001000010000101000");
	strcpy_s(_cMaze[13], "01001000010000101000");
	strcpy_s(_cMaze[14], "01001000010000100000");
	strcpy_s(_cMaze[15], "01001000011100111110");
	strcpy_s(_cMaze[16], "01011111111100100010");
	strcpy_s(_cMaze[17], "01010000000000100010");
	strcpy_s(_cMaze[18], "01111111111111100010");
	strcpy_s(_cMaze[19], "00000000000000111130");
	_pStartpos->x = 0;
	_pStartpos->y = 0;
	_pEndpos->x = 18;
	_pEndpos->y = 19;
	PLAYER tSetplayer = { *_pStartpos, 1,0,false,false };
	*_pPlayer = tSetplayer;

}

void Update(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, vector<BOOM> vecBomb, vector<POS>boomEffect)
{
	_pPlayer->tNewpos = _pPlayer->tpos;
	//키 입력받아서 플레이어의 좌표를 바꿔줘야해
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		--_pPlayer->tNewpos.y;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		++_pPlayer->tNewpos.y;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		--_pPlayer->tNewpos.x;
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		++_pPlayer->tNewpos.x;
	//벽 밖으로 나가는거 예외처리
	_pPlayer->tNewpos.x = std::clamp(_pPlayer->tNewpos.x, 0, HORIZON - 2);
	_pPlayer->tNewpos.y = std::clamp(_pPlayer->tNewpos.y, 0, VERTICAL - 1);

	if (_cMaze[_pPlayer->tNewpos.y][_pPlayer->tNewpos.x] != '0')
	{
		_pPlayer->tpos = _pPlayer->tNewpos;
	}
	if (_cMaze[_pPlayer->tpos.y][_pPlayer->tpos.x] == '3')
	{
		Beep((DWORD)523.25, 500);
		Beep((DWORD)659.26, 500);
		Beep((DWORD)783.99, 500);
		Beep((DWORD)1046.50, 500);
	}
	Sleep(100);
}

void Render(char _cMaze[VERTICAL][HORIZON], PPLAYER _pPlayer, vector<POS>boomEffect)
{
	for (int i = 0; i < VERTICAL; i++) {
		for (int j = 0; j < HORIZON; j++)
		{
			if (_pPlayer->tpos.x == j && _pPlayer->tpos.y == i)
				cout << "§";
			else if (_cMaze[i][j] == '0')
				cout << "■";//벽
			else if (_cMaze[i][j] == '1')
				cout << " "; //공백을 1번 길
			else if (_cMaze[i][j] == '2')
				cout << "®";//시작점
			else if (_cMaze[i][j] == '3')
				cout << "♨";//도착
			else if (_cMaze[i][j] == '4') //물풍선 파워업
				cout << "◐";
			else if (_cMaze[i][j] == '5') //슬라임
				cout << "♤";
			else if (_cMaze[i][j] == '6') //벽 푸시
				cout << "▩";
			else if (_cMaze[i][j] == 'b') //물풍선
			{
				SetColor((int)COLOR::LIGHT_BLUE, (int)COLOR::BLACK);
				cout << "＠";
			}
			else if (_cMaze[i][j] == 'p') //물풍선 깜빡
			{
				SetColor((int)COLOR::MINT, (int)COLOR::BLACK);
				cout << "⊙";
			}
			SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
		}
		cout << endl;
	}
}

