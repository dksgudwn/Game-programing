#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void Init(int* _pNumber)
{
	//셔플
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
	{
		_pNumber[i] = i + 1;
	}
	_pNumber[24] = INT_MAX;

	//섞다
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;
		iTemp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[idx2] = iTemp;
	}
}
void RenderNumber(int* _pNumber)
{
	cout << "=========================================" << endl;
	cout << "|\t 숫자 퍼즐 게임입니다.\t|" << endl;
	cout << "=========================================" << endl;
	cout << "*을 움직여서 1부터 24까지 퍼즐을 맞춰보세요." << endl;
	cout << "=========================================" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (_pNumber[i * 5 + j] == INT_MAX)
				cout << "*" <<"\t";
			else {
				cout << _pNumber[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}
}
char Update(int* _pNumber)
{
	cout << "w: 위, s: 아래, a: 왼쪽, d: 오른쪽, q: 종료" << endl;
	static int iStarIndex = 24;
	char cInput = _getch();
	switch (cInput)
	{
	case 'w':
	case'W':
	{
		if (iStarIndex > 4)
		{
			_pNumber[iStarIndex] = _pNumber[iStarIndex - 5];
			_pNumber[iStarIndex - 5] = INT_MAX;
			iStarIndex -= 5;
		}
	}
	break;
	case 's':
	case'S':
	{
		if (iStarIndex < 20)
		{
			_pNumber[iStarIndex] = _pNumber[iStarIndex + 5];
			_pNumber[iStarIndex + 5] = INT_MAX;
			iStarIndex += 5;
		}
	}
	break;
	case 'a':
	case'A':
	{
		if (iStarIndex % 5 != 0)
		{
			_pNumber[iStarIndex] = _pNumber[iStarIndex - 1];
			_pNumber[iStarIndex - 1] = INT_MAX;
			iStarIndex -= 1;
		}
	}
	break;
	case 'd':
	case'D':
	{
		if (iStarIndex % 5 != 4)
		{
			_pNumber[iStarIndex] = _pNumber[iStarIndex + 1];
			_pNumber[iStarIndex + 1] = INT_MAX;
			iStarIndex += 1;
		}
	}
	break;
	default:
		break;
	}
	return cInput;
}
void PuzzleClear(int* _pNumber)
{
	bool bChk = true;
	for (int i = 0; i < 24; i++)
	{
		if (_pNumber[i] != i + 1)
		{
			bChk = false;
			break;
		}
	}
	if (bChk == true)
	{
		cout << "다 맞췄습니다." << endl;
		return;
	}
}
int main()
{
	int iNumber[25] = {};
	Init(iNumber);

	while (true)
	{
		system("cls");
		RenderNumber(iNumber);
		char cChk = Update(iNumber);
		if (cChk == 'q' || cChk == 'Q') {
			return 0;
		}
		PuzzleClear(iNumber);
	}
}