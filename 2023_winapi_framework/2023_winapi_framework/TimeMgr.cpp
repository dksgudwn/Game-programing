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

	//�ʴ� ī��Ʈ Ƚ�� ��ȯ
	//���� Ÿ�̸Ӱ� �����ϴ� ���ļ��� �˷����
	QueryPerformanceFrequency(&m_llFrequency);
}

void TimeMgr::Update()
{
	//dt 1�����Ӵ� �ð�
	QueryPerformanceCounter(&m_llCurCount);
	m_dt - (float)m_llCurCount.QuadPart - m_llPrevCount.QuadPart / (float)m_llFrequency.QuadPart;
	m_llPrevCount = m_llCurCount;

	//fps
	UINT m_framecount;
	float m_accFrameTime; 
	UINT m_fps;
}
