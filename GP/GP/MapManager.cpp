#include "MapManager.h"
#include "Stage.h"
#include "define.h"
#include "console.h"
MapManager* MapManager::m_pInst = nullptr;

MapManager::MapManager()
{
}

MapManager::~MapManager()
{
	for (int i = 0; i < 3; i++)
	{
		SAFE_DELETE(m_pStage[i]);
	}
}

bool MapManager::Init()
{
	char* pFileName[3] = { (char*)"Stage1.txt",(char*)"Stage2.txt", (char*)"Stage3.txt" };
	for (int i = 0; i < 3; i++)
	{
		m_pStage[i] = new Stage;
		if (!m_pStage[i]->Init(pFileName[i]))
		{
			return false;
		}
	}
	return true;
}

void MapManager::Run(int _iCurStage)
{
	m_iCurstage = _iCurStage;
	while (true)
	{
		Gotoxy(0, 0);
		m_pStage[m_iCurstage]->Render();
	}
}
