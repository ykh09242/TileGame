#include "stdafx.h"
#include "InGame.h"


void InGame::Activate()
{
	
}

void InGame::Update()
{
}

void InGame::Render()
{
	
	for (short i = 0; i < 10; ++i)
	{
		int z = 0;
		for (short j = 0; j < 20; j += 2)
		{
			g_system->WriteText(j + 30, i + 8, cMap[i][z++]);
		}
	}
}

void InGame::Deactivate()
{
}
