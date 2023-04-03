#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;


void playsound(float arr[])
{
	int num = rand() % 8;
	int input;
	cout << endl << "아무키나누르세요" << endl;
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
			cout << "\r" << "입력하세요" << endl;
			cin >> input;
			if (input == num)
			{
				cout << "성공" << endl;
			}
			else
			{
				cout << "실패" << endl;
			}
			break;
		}
	}
}
int main()
{
	float arr[8]{ 523.25, 587.33, 659.29, 698.46, 783.99, 880, 987.77, 1046.50 };
	string s[8]{ "도(0)","레(1)","미(2)","파(3)","솔(4)","라(5)","시(6)","도(7)" };
	string ss;
	srand((unsigned int)time(NULL));
	cout << "절대음감" << endl;
	cout << "--------------------------" << endl;
	//주파수, 초(ms)
	for (int i = 0; i < 8; i++)
	{
		cout << s[i] << "\t";
		Beep(arr[i], 500);
		Sleep(500);
	}
	while (true)
	{
		playsound(arr);
		cout << "게임을 그만둘까요?(Y/N)" << endl;
		cin >> ss;
		if (ss == "y" && ss == "Y")playsound(arr);
		else if (ss == "N" && ss == "n")break;
	}
}