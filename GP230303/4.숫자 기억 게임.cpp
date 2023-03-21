#include <iostream>
#include <Windows.h>
#include <conio.h>	
using namespace std;
//입력부터하기///////////////////////////////////////////////////////////////////////+859
enum MODE
{
	EASY = 1,
	NORMAL,
	HARD
};


void Init();
void GameStart(MODE _eMode, int Sleeptime);
int main()
{
	Init();
	srand(unsigned int(time(NULL)));
	int iSelectmode;
	cin >> iSelectmode;
	system("cls");

	switch (iSelectmode)
	{
	case EASY: {
		GameStart(EASY, 1000);
		break;
	}
	case NORMAL: {
		GameStart(NORMAL, 700);
		break;
	}
	case HARD: {
		GameStart(HARD, 500);
		break;
	default:
		cout << "잘못 입력하였습니다." << endl;
		break;
	}
	}
	Sleep(1000);
}

void Init()
{
	cout << "======================================" << endl;
	cout << "숫자 기억 게임 입니다. 모드를 선택하세요." << endl;
	cout << "EASY: 1, NORMAL: 2, HARD: 3" << endl;
	cout << "======================================" << endl;
	srand(unsigned int(time(NULL)));
}

void GameStart(MODE _eMode, int Sleeptime)
{
	int iInput;
	int* iNumber = new int[_eMode * 5];
	for (int i = 0; i < _eMode * 5; i++) {
		iNumber[i] = rand() % 100 + 1;
	}

	for (int i = 0; i < 5 * _eMode; i++) {
		cout << iNumber[i] << " ";
		Sleep(Sleeptime);
	}
	system("cls");
	switch (_eMode)
	{
	case EASY:
		cout << "EASY 모드 입니다." << endl;
		break;
	case NORMAL:
		cout << "NORMAL 모드 입니다." << endl;
		break;
	case HARD:
		cout << "HARD 모드 입니다." << endl;
		break;
	}
	cout << "방금 본 숫자를 입력하세요. " << endl;
	for (int i = 0; i < _eMode * 5; i++) {
		cin >> iInput;
		if (iNumber[i] != iInput)
		{
			cout << "틀림" << endl;
			delete[] iNumber;
			return;
		}

	}
	cout << "축하" << endl;
	delete[] iNumber;
}
