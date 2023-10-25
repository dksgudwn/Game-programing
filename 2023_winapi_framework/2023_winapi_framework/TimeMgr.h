#pragma once
class TimeMgr
{
	SINGLE(TimeMgr);
public:
	void Init();
	void Update();
private:
	//DT(Delta time): 1�����Ӵ� �ð�
	//fps
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llFrequency;
	float m_dt;
};