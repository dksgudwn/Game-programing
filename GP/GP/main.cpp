#include <iostream>
#include "Core.h"

int main()
{
	//Core�ʱ�ȭ
	if (!Core::GetInst()->Init())
	{
		//����
	}
	//Core���ӱ���
	Core::GetInst()->Run();

	//core����
	Core::DestroyInst();
}