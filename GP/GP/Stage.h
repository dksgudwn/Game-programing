#pragma once
#include "define.h"
#include <windef.h>
class Stage
{
public:
	Stage();
	~Stage();
private:
	char m_cStage[MAP_y][MAP_x];
	POINT m_tStart;
	POINT m_tEnd;
public:
	POINT GetStart() { return m_tStart; }
	POINT GetEnd() { return m_tEnd; }
	char GetStage(int x, int y) { return m_cStage[y][x]; }

public:
	bool Init(const char* _pFilename);
	void Render();
};
