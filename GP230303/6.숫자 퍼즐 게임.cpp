#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void Init(int* _pNumber)
{
	//����
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
	{
		_pNumber[i] = i + 1;
	}
	_pNumber[24] = INT_MAX;

	//����
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
	cout << "|\t ���� ���� �����Դϴ�.\t|" << endl;
	cout << "=========================================" << endl;
	cout << "*�� �������� 1���� 24���� ������ ���纸����." << endl;
	cout << "=========================================" << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (_pNumber[i * 5 + j] == INT_MAX)
				cout << "*";
			else {
				cout << _pNumber[i * 5 + j] << "\t";
			}
		}
	}
}
void Update(int* _pNumber)
{
	cout << "w: ��, s: �Ʒ�, a: ����, d: ������, q: ����" << endl;
}
int main()
{
	int iNumber[25] = {};
	Init(iNumber);

	while (true)
	{
		system("cls");
		RenderNumber(iNumber);
		Update(iNumber);
	}

}