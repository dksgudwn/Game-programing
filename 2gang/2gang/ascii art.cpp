#include<iostream>
#include<io.h>
#include<fcntl.h>
using namespace std;

int main()
{
	cout << "GAMEOVER" << endl;

	int iCurmode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"	 ██████╗  █████╗ ███╗   ███╗███████╗ ██████╗ ██╗   ██╗███████╗██████╗ " << endl;
	wcout << L"	██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔═══██╗██║   ██║██╔════╝██╔══██╗ " << endl;
	wcout << L"	██║  ███╗███████║██╔████╔██║█████╗  ██║   ██║██║   ██║█████╗  ██████╔╝ " << endl;
	wcout << L"	██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗ " << endl;
	wcout << L"	╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗╚██████╔╝ ╚████╔╝ ███████╗██║  ██║ " << endl;
	wcout << L"	 ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝ " << endl;

	_setmode(_fileno(stdout), iCurmode);
	cout << "안녕하세요" << endl;

}