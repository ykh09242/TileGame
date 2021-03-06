// TileGame.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	_CrtDumpMemoryLeaks();
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	g_system->Init();

	DWORD dwTime = GetTickCount();

	while (!g_system->exit)
	{
		if (dwTime + 60 < GetTickCount())
		{
			dwTime = GetTickCount();

			g_system->Update();
			g_system->Render();
		}
	}
	g_system->Quit();
    return 0;
}

