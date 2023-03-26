#include <iostream>
#include <Windows.h>
using namespace std;

enum class AI_MODE
{
	AM_EASY = 1,
	AM_NORMAL,
	AM_HARD
	//HARD: 1) 가운데 무조건->양쪽 모서리 ->대각선 -> 가장 높은줄.
};
void Init(int* _pNumber)
{
	//셔플
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

int BingoCount(int* pNumber) {
	int iBingo = 0;
	int iHorLine = 0, iVerLine = 0, iLLine = 0, iRLine = 0;

	for (int i = 0; i < 5; i++) {
		iHorLine = 0;
		iVerLine = 0;
		for (int j = 0; j < 5; j++) {
			if (pNumber[i * 5 + j] == INT_MAX) {
				iHorLine++;
			}
			if (pNumber[j * 5 + i] == INT_MAX) {
				iVerLine++;
			}

		}
		if (iHorLine == 5)
			iBingo++;
		if (iVerLine == 5)
			iBingo++;
	}
	;

	for (int i = 0; i <= 25; i += 6) {
		if (pNumber[i] == INT_MAX) {
			iLLine++;
		}
	}
	if (iLLine == 5)
		iBingo++;

	for (int i = 4; i <= 20; i += 4) {
		if (pNumber[i] == INT_MAX) {
			iRLine++;
		}
	}
	if (iRLine == 5)
		iBingo++;

	return iBingo;
}

void ChangeNumber(int* _pNumber, int& _iInput) {
	for (int i = 0; i < 25; i++)
	{
		if (_pNumber[i] == _iInput)
		{
			_pNumber[i] = INT_MAX;
		}
	}
}
AI_MODE SelectAimode()
{
	cout << "=======================================" << endl;
	cout << "|\t 빙고입니다.\t|" << endl;
	cout << "=======================================" << endl;
	cout << "빙고줄이 5줄 이상이면 게임에서 승리합니다." << endl;
	cout << "=======================================" << endl;
	cout << "1. EASY " << endl;
	cout << "2. NORMAL " << endl;
	cout << "AI모드를 선택하세요:  " << endl;
	int iAimode;
	cin >> iAimode;
	//예외처리. static_cast: c++, (): c
	if (iAimode < static_cast<int>(AI_MODE::AM_EASY) || iAimode>(int)AI_MODE::AM_NORMAL)
	{
		cout << "잘못 입력하셨습니다." << endl;
	}
	return (AI_MODE)iAimode;
}

int SelectAinumber(int* _pNumber, AI_MODE _eMode)
{
	//안고른다 때문에 배열
	int iNoneSelect[25] = {};
	int iNoneSelectcnt = 0;
	switch (_eMode)
	{
	case AI_MODE::AM_EASY:
	{
		for (int i = 0; i < 25; i++)
		{
			if (_pNumber[i] != INT_MAX)//숫자다.
			{

				iNoneSelect[iNoneSelectcnt] = _pNumber[i];
				++iNoneSelectcnt;
			}
		}
		return iNoneSelect[rand() % iNoneSelectcnt];
	}
	break;
	case AI_MODE::AM_NORMAL:
		//
		break;
	case AI_MODE::AM_HARD:
		break;
	default:
		break;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int iNumber[25] = {};
	int iAiNumber[25] = {};
	int iBingo = 0, iAiBingo = 0;
	int iCount = 0;
	int iInput;
	Init(iNumber);
	Init(iAiNumber);
	AI_MODE eAimode = SelectAimode();
	while (true)
	{
		system("cls");
		// Player그리기
		cout << "=======================================Player=======================================" << endl;
		RenderNumber(iNumber, iBingo);
		//ai그리기
		cout << "=======================================Ai=========================================" << endl;
		switch (eAimode)
		{
		case AI_MODE::AM_EASY:
			cout << "AIMode: Easy" << endl;
			break;
		case AI_MODE::AM_NORMAL:
			cout << "AIMode: Normal" << endl;
			break;
		case AI_MODE::AM_HARD:
			cout << "AIMode: Hard" << endl;
			break;
		default:
			break;
		}
		RenderNumber(iAiNumber, iAiBingo);
		if (iBingo >= 5)
		{
			cout << "Player승리" << endl;
			break;
		}
		else if (iAiBingo >= 5)
		{
			cout << "AI가 게임에서 승리하셨습니다." << endl;
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

		//입력된 수를 별로 바꿈
		//플레이어턴
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		//ai모드에 따라서 ai가 선택할 숫자를 만들어야 한다.
		iInput = SelectAinumber(iAiNumber, eAimode);//ai모드에 따라서 선택할것이다.
		cout << "AI가 선택한 숫자는 " << iInput << "입니다." << endl;
		Sleep(1000);
		//AI 턴
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		//빙고 체크
		iBingo = BingoCount(iNumber);
		iAiBingo = BingoCount(iAiNumber);
	}
}