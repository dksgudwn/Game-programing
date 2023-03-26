#include <iostream>
#include <Windows.h>
using namespace std;

enum class AI_MODE
{
	AM_EASY = 1,
	AM_NORMAL,
	AM_HARD
	//HARD: 1) ��� ������->���� �𼭸� ->�밢�� -> ���� ������.
};
void Init(int* _pNumber)
{
	//����
	for (int i = 0; i < 25; i++)
	{
		_pNumber[i] = i + 1;
	}

	//����
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
	cout << "|\t �����Դϴ�.\t|" << endl;
	cout << "=======================================" << endl;
	cout << "�������� 5�� �̻��̸� ���ӿ��� �¸��մϴ�." << endl;
	cout << "=======================================" << endl;
	cout << "1. EASY " << endl;
	cout << "2. NORMAL " << endl;
	cout << "AI��带 �����ϼ���:  " << endl;
	int iAimode;
	cin >> iAimode;
	//����ó��. static_cast: c++, (): c
	if (iAimode < static_cast<int>(AI_MODE::AM_EASY) || iAimode>(int)AI_MODE::AM_NORMAL)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
	return (AI_MODE)iAimode;
}

int SelectAinumber(int* _pNumber, AI_MODE _eMode)
{
	//�Ȱ��� ������ �迭
	int iNoneSelect[25] = {};
	int iNoneSelectcnt = 0;
	switch (_eMode)
	{
	case AI_MODE::AM_EASY:
	{
		for (int i = 0; i < 25; i++)
		{
			if (_pNumber[i] != INT_MAX)//���ڴ�.
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
		// Player�׸���
		cout << "=======================================Player=======================================" << endl;
		RenderNumber(iNumber, iBingo);
		//ai�׸���
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
			cout << "Player�¸�" << endl;
			break;
		}
		else if (iAiBingo >= 5)
		{
			cout << "AI�� ���ӿ��� �¸��ϼ̽��ϴ�." << endl;
		}
		cout << "���ڸ� �Է��ϼ���(0:����)" << endl;
		cin >> iInput;

		if (iInput == 0)
		{
			cout << "������ ����" << endl;
			return 0;
		}
		else if (iInput < 1 || iInput>25)
		{
			cout << "�߸� �Է�" << endl;
			break;
		}

		//�Էµ� ���� ���� �ٲ�
		//�÷��̾���
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		//ai��忡 ���� ai�� ������ ���ڸ� ������ �Ѵ�.
		iInput = SelectAinumber(iAiNumber, eAimode);//ai��忡 ���� �����Ұ��̴�.
		cout << "AI�� ������ ���ڴ� " << iInput << "�Դϴ�." << endl;
		Sleep(1000);
		//AI ��
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		//���� üũ
		iBingo = BingoCount(iNumber);
		iAiBingo = BingoCount(iAiNumber);
	}
}