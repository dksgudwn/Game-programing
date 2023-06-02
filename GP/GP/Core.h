#pragma once
#include "define.h"
class Core
{
private:
	Core();
	~Core();
public:
	static Core* m_pInst;
public:
	static Core* GetInst()
	{
		m_pInst = new Core;
		return m_pInst;
	}
	static void DestroyInst()
	{
		if (m_pInst)
		{
			SAFE_DELETE(m_pInst);
			/*delete m_pInst;
			m_pInst = nullptr;*/
		}
	}
public:
	bool Init();
	void Run();
	int MenuDraw();
};
