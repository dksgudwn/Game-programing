#include"pch.h"
#include "Core.h"
#include "TimeMgr.h"

bool Core::Init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;

	m_hDC = GetDC(m_hWnd);
	m_obj.SetPos(Vec2(m_ptResolution));
	m_obj.SetScale({ 150,150 });

	TimeMgr::GetInst()->Init();
	return true;
}

void Core::GameLoop()
{
	static int callcount = 0;
	++callcount;
	static int prev = GetTickCount64();
	int cur = GetTickCount64();
	if (cur - prev > 1000)
	{
		prev = cur;
		callcount = 0;
	}
	Update();
	Render();
}

void Core::Release()
{
}

void Core::Update()
{
	Vec2 vPos = m_obj.GetPos();
	if (GetAsyncKeyState(VK_LEFT) & 0X8000)
		vPos.x -= 0.01f;
	if (GetAsyncKeyState(VK_RIGHT) & 0X8000)
		vPos.x += 0.01f;
	m_obj.SetPos(vPos);

}

void Core::Render()
{
	Vec2 vPos = m_obj.GetPos();
	Vec2 vScale = m_obj.GetScale();
	//RECT_RENDER(m_obj.m_ptPos.x, m_obj.m_ptPos.y, m_obj.m_ptScale.x, m_obj.m_ptScale.y, m_hDC);
	//Rectangle(m_hDC, 100, 100, 500, 500);
}
