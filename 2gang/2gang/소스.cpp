#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	float arr[8]{ 523.25, 587.33, 659.29, 698.46, 783.99, 880, 987.77, 1046.50 };
	string s[8]{ "��(0)","��(1)","��(2)","��(3)","��(4)","��(5)","��(6)","��(7)" };
	cout << "��������" << endl;
	cout << "--------------------------" << endl;
	//���ļ�, ��(ms)
	for (int i = 0; i < 8; i++)
	{
		cout << s[i] << "\t";
		Beep(arr[i], 500);
		Sleep(500);
	}
	int num = rand() % 8;
	cout << endl << "�ƹ�Ű����������" << endl;
	while (true)
	{
		if (_kbhit()) {
			Beep(arr[num], 500);
			break;
		}
	}

}