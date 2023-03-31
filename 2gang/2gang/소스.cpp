#include<iostream>
#include<Windows.h>
#include<conio.h>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	float arr[8]{ 523.25, 587.33, 659.29, 698.46, 783.99, 880, 987.77, 1046.50 };
	string s[8]{ "도(0)","레(1)","미(2)","파(3)","솔(4)","라(5)","시(6)","도(7)" };
	cout << "절대음감" << endl;
	cout << "--------------------------" << endl;
	//주파수, 초(ms)
	for (int i = 0; i < 8; i++)
	{
		cout << s[i] << "\t";
		Beep(arr[i], 500);
		Sleep(500);
	}
	int num = rand() % 8;
	cout << endl << "아무키나누르세요" << endl;
	while (true)
	{
		if (_kbhit()) {
			Beep(arr[num], 500);
			break;
		}
	}

}