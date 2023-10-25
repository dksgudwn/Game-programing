#include"pch.h"
#include "TimeMgr.h"

void TimeMgr::Init()
{
	m_llPrevCount = {};
	m_llFrequency = {};
	m_llCurCount = {};
	m_dt = 0.f;
	m_framecount

	QueryPerformanceCounter(&m_llPrevCount);

	//초당 카운트 횟수 반환
	//현재 타이머가 동작하는 주파수를 알려줘요
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	//dt 1프레임당 시간
	QueryPerformanceCounter(&m_llCurCount);
	m_dt - (float)m_llCurCount.QuadPart - m_llPrevCount.QuadPart / (float)m_llFrequency.QuadPart;
	m_llPrevCount = m_llCurCount;

	//fps
	UINT m_framecount;
	float m_accFrameTime; 
	UINT m_fps;
}
