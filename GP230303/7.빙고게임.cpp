#include <iostream>
#include <Windows.h>
using namespace std;

void Init(int* _pNumber)
{
	//����
	srand((unsigned int)time(NULL));
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
	cout << "=======================================" << endl;
	cout << "|\t �����Դϴ�.\t|" << endl;
	cout << "=======================================" << endl;
	cout << "�������� 5�� �̻��̸� ���ӿ��� �¸��մϴ�." << endl;
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
			cout << "�¸�" << endl;
			break;
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
		//�Էµ� ���� �ٲ�
		for (int i = 0; i < 25; i++)
		{
			if (iNumber[i] == iInput)
			{
				iNumber[i] = INT_MAX;
			}
		}
		//���� üũ

	}
}