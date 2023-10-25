#pragma once
//싱글톤 : 인스턴스가 한개만 있어야하고. 어디서든 접근이 가능하여야한다
//다이나믹 싱글톤 장점) 동적으로  생성하고 지운다, 필요할때만 생성한다.
							//단점) 메모리가 힙에 상주한다. 직접 지워주어야한다.
 //정적 싱글톤 : 장점) 메모리가 데이터에 있다. 직접 안 지워도 돼.
						//단점) 필요하지 않아도 생성이 된다.
#include "define.h"
#include"pch.h"
#include "Object.h"

class Core //GAMEMANAGER
{
	SINGLE(Core);
public:
	bool Init(HWND _hWnd, POINT _ptResolution);
	void GameLoop();
	void Release();
private:
	void Update();
	void Render();
private:
	HWND m_hWnd;
	POINT m_ptResolution;
	HDC m_hDC;
	Object m_obj;

	//private:
	//	Core();
	//	~Core();
	//	//static
	//public:
	//	static Core* GetInst()
	//	{
	//		static Core m_Inst;
	//
	//		return &m_Inst;
	//	}
};