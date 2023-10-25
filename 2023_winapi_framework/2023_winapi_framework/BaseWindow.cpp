#include "pch.h"
#include "BaseWindow.h"
#include "Resource.h"
#include "Core.h"
BaseWindow::BaseWindow(POINT _ptResolution)
	:m_hInst(0)
	, m_hWnd(0)
	, m_ptResolution(_ptResolution)
{
}

BaseWindow::~BaseWindow()
{
}

int BaseWindow::Run(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	this->m_hInst = hInstance;
	this->MyRegisterClass();
	this->WindowCreate();
	this->WindowShow(nCmdShow);
	this->WindowUpdate();
	if (!Core::GetInst()->Init(m_hWnd, m_ptResolution))
	{
		MessageBox(m_hWnd, L"Core Error", L"ERROR", MB_OK);
	}

	return this->MessageLoop();
}

ATOM BaseWindow::MyRegisterClass()
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_MY2023WINAPIFRAMEWORK));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = WINDOW_CLASS_NAME;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

void BaseWindow::WindowCreate()
{
	int iWinposx = GetSystemMetrics(SM_CXSCREEN) / 2 - m_ptResolution.x / 2;
	int iWinposy = GetSystemMetrics(SM_CYSCREEN) / 2 - m_ptResolution.y / 2;
	m_hWnd = CreateWindowW(WINDOW_CLASS_NAME, L"Game-Framwork", WS_OVERLAPPEDWINDOW,
		iWinposx, iWinposy, m_ptResolution.x, m_ptResolution.y, nullptr, nullptr, m_hInst, nullptr);
	RECT rt = { iWinposx, iWinposy, iWinposx + m_ptResolution.x, iWinposy + m_ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	MoveWindow(m_hWnd, iWinposx, iWinposy, rt.right - rt.left, rt.bottom - rt.top, true);
}

void BaseWindow::WindowShow(int _nCmdShow)
{
	ShowWindow(m_hWnd, _nCmdShow);
}

void BaseWindow::WindowUpdate()
{
	UpdateWindow(m_hWnd);
}

LRESULT BaseWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//case WM_PAINT:
		//{
		//	PAINTSTRUCT ps;
		//	HDC hdc = BeginPaint(hWnd, &ps);

		//	EndPaint(hWnd, &ps);
		//}
		//break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

int BaseWindow::MessageLoop()
{
	MSG msg;
	memset(&msg, 0, sizeof(msg));
	// 기본 메시지 루프입니다:
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (WM_QUIT == msg.message)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Core::GetInst()->GameLoop();
		}
	}
	Core::GetInst()->Release();
	return (int)msg.wParam;
}