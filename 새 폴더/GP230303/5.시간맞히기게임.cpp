#include <iostream>
#include <Windows.h>
#include <conio.h> //console input output.
using namespace std;

int main()
{
	// _getch(), kbhit();
	cout << "Ű�Է�" << endl;
	char ch = _getch();
	cout << "����" << endl;
	long iStartTime = time(NULL);
	cout << iStartTime << endl;

	while (true)
	{
		if (_kbhit()) {
			cout << "��" << endl;
			break;
		}
	}

	if (time(NULL) - iStartTime == 10) {
		cout << "����" << endl;
	}
	else if (time(NULL) - iStartTime > 10) {
		cout << "����" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}
