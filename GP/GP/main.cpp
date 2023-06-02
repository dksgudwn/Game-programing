#include <iostream>
#include "Core.h"

int main()
{
	//Core초기화
	if (!Core::GetInst()->Init())
	{
		//종료
	}
	//Core게임구동
	Core::GetInst()->Run();

	//core끄기
	Core::DestroyInst();
}