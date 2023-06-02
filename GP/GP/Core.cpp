#include <iostream>
#include "Core.h"
#include "MapManager.h"
using namespace std;
Core* Core::m_pInst = nullptr;

Core::Core()
{
}

Core::~Core()
{
}

bool Core::Init()
{
	MapManager::GetInst()->Init();
	return false;
}

void Core::Run()
{
	int iStage = MenuDraw();
}

int Core::MenuDraw()
{
	cout << "1. Stage 1" << endl;
	cout << "2. Stage 2" << endl;
	cout << "3. Stage 3" << endl;
	cout << "4. Stage 4" << endl;
	int iInput;
	cin >> iInput;
	return iInput;
}
