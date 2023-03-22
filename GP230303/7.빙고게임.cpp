#include <iostream>
#include <Windows.h>
using namespace std;

void Init(int* _pNumber)
{
	//셔플
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 25; i++)
	{
		_pNumber[i] = i + 1;
	}

	//섞다
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[idx2] = iTemp;
	}
}
void RenderNumber(int* _pNumber, int& _iBingo)
{
	cout << "=======================================" << endl;
	cout << "|\t 빙고입니다.\t|" << endl;
	cout << "=======================================" << endl;
	cout << "빙고줄이 5줄 이상이면 게임에서 승리합니다." << endl;
	cout << "=======================================" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (_pNumber[i * 5 + j] == INT_MAX)
				cout << "*" << "\t";
			else {
				cout << _pNumber[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}
	cout << "Bingo Line: " << _iBingo << endl;
}
int main()
{
	int iNumber[25] = {};
	int iBingo = 0;
	int iInput;
	Init(iNumber);
	while (true)
	{
		system("cls");
		RenderNumber(iNumber, iBingo);
		if (iBingo >= 5)
		{
			cout << "승리" << endl;
			break;
		}
		cout << "숫자를 입력하세요(0:종료)" << endl;
		cin >> iInput;

		if (iInput == 0)
		{
			cout << "게임을 종료" << endl;
			return 0;
		}
		else if (iInput < 1 || iInput>25)
		{
			cout << "잘못 입력" << endl;
			break;
		}
		//입력된 수를 바꿈
		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
			}
		}
		//빙고 체크

	}
}