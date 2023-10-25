#include "StartScene.h"
#include<iostream>
#include<Windows.h>
#include<io.h>
#include<fcntl.h>
#include "console.h"
#include <conio.h>

using namespace std;

void GameTitle()
{
	int curMode = _setmode(_fileno(stdout), _O_U16TEXT);
	SetColor((int)COLOR::LIGHT_VIOLET, (int)COLOR::BLACK);
	
	wcout << L" =====================================================  " << "\n";
	wcout << L" ====   ======      ========  ======     =============  " << "\n";
	wcout << L" ==   =   ===   ==   ======   =====  ===  ============  " << "\n";
	wcout << L" =   ===   ==  ====  =====    ====  =====  ===  ==  ==  " << "\n";
	wcout << L" ======   ===  ====  ====  =  =====  ===  =====    ===  " << "\n";
	wcout << L" =====   ====  ====  ===  ==  ======     ====        =  " << "\n";
	wcout << L" ====   =====  ====  ==  ===  =====  ===  =====    ===  " << "\n";
	wcout << L" ===   ======  ====  ==         ==  =====  ===  ==  ==  " << "\n";
	wcout << L" ==   =======   ==   =======  =====  ===  ============  " << "\n";
	wcout << L" =        ====      ========  ======     =============  " << "\n";
	wcout << L" =====================================================  " << "\n";

	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	_setmode(_fileno(stdout), curMode);

}
