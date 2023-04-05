#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#include "resource.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

int main()
{
	//1: 리소스 이름, 2: 핸들, 3: 플래그
	//파일자체를 불러오는 방법
	//PlaySound(TEXT("explosion.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//리소스자체를 업로드하는 방법
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
	_getch();
}
