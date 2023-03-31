#include <iostream>
#include <Windows.h>
#include <conio.h>	
using namespace std;
//�Էº����ϱ�///////////////////////////////////////////////////////////////////////+859
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
		cout << "�߸� �Է��Ͽ����ϴ�." << endl;
		break;
	}
	}
	Sleep(1000);
}

void Init()
{
	cout << "======================================" << endl;
	cout << "���� ��� ���� �Դϴ�. ��带 �����ϼ���." << endl;
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
		cout << "EASY ��� �Դϴ�." << endl;
		break;
	case NORMAL:
		cout << "NORMAL ��� �Դϴ�." << endl;
		break;
	case HARD:
		cout << "HARD ��� �Դϴ�." << endl;
		break;
	}
	cout << "��� �� ���ڸ� �Է��ϼ���. " << endl;
	for (int i = 0; i < _eMode * 5; i++) {
		cin >> iInput;
		if (iNumber[i] != iInput)
		{
			cout << "Ʋ��" << endl;
			delete[] iNumber;
			return;
		}

	}
	cout << "����" << endl;
	delete[] iNumber;
}
