#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<mmsystem.h>
#include "resource.h"
#pragma comment(lib, "winmm.lib")
using namespace std;

int main()
{
	//1: ���ҽ� �̸�, 2: �ڵ�, 3: �÷���
	//������ü�� �ҷ����� ���
	//PlaySound(TEXT("explosion.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//���ҽ���ü�� ���ε��ϴ� ���
	//PlaySound(MAKEINTRESOURCE(IDR_WAVE1), NULL, SND_RESOURCE);
	_getch();
}
