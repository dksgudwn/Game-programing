#pragma once
//�̱��� : �ν��Ͻ��� �Ѱ��� �־���ϰ�. ��𼭵� ������ �����Ͽ����Ѵ�
//���̳��� �̱��� ����) ��������  �����ϰ� �����, �ʿ��Ҷ��� �����Ѵ�.
							//����) �޸𸮰� ���� �����Ѵ�. ���� �����־���Ѵ�.
 //���� �̱��� : ����) �޸𸮰� �����Ϳ� �ִ�. ���� �� ������ ��.
						//����) �ʿ����� �ʾƵ� ������ �ȴ�.
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