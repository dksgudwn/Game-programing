#include <iostream>
#include <Windows.h>
#include <conio.h> //console input output.
using namespace std;

int main()
{
	// _getch(), kbhit();
	cout << "키입력" << endl;
	char ch = _getch();
	cout << "시작" << endl;
	long iStartTime = time(NULL);
	cout << iStartTime << endl;

	while (true)
	{
		if (_kbhit()) {
			cout << "끝" << endl;
			break;
		}
	}

	if (time(NULL) - iStartTime == 10) {
		cout << "축하" << endl;
	}
	else if (time(NULL) - iStartTime > 10) {
		cout << "지남" << endl;
	}
	else
	{
		cout << "아직" << endl;
	}
}
