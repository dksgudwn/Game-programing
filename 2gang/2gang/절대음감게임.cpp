#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;


void playsound(float arr[])
{
	int num = rand() % 8;
	int input;
	cout << endl << "�ƹ�Ű����������" << endl;
	while (true)
	{
		if (_kbhit())
		{
			for (int i = 3; i > 0; i--)
			{
				cout << "\r" << i;
				Sleep(1000);
			}
			Beep(arr[num], 500);
			cout << "\r" << "�Է��ϼ���" << endl;
			cin >> input;
			if (input == num)
			{
				cout << "����" << endl;
			}
			else
			{
				cout << "����" << endl;
			}
			break;
		}
	}
}
int main()
{
	float arr[8]{ 523.25, 587.33, 659.29, 698.46, 783.99, 880, 987.77, 1046.50 };
	string s[8]{ "��(0)","��(1)","��(2)","��(3)","��(4)","��(5)","��(6)","��(7)" };
	string ss;
	srand((unsigned int)time(NULL));
	cout << "��������" << endl;
	cout << "--------------------------" << endl;
	//���ļ�, ��(ms)
	for (int i = 0; i < 8; i++)
	{
		cout << s[i] << "\t";
		Beep(arr[i], 500);
		Sleep(500);
	}
	while (true)
	{
		playsound(arr);
		cout << "������ �׸��ѱ��?(Y/N)" << endl;
		cin >> ss;
		if (ss == "y" && ss == "Y")playsound(arr);
		else if (ss == "N" && ss == "n")break;
	}
}