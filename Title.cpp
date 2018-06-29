#include "stdafx.h"
#include "Title.h"


Title::Title()
	: x(0), y(0)
{
}


Title::~Title()
{
}

void Title::Update()
{
	if (GetAsyncKeyState(VK_DOWN) && y + 2 <= g_system->srHeight)
	{
		y++;
	}
	if (GetAsyncKeyState(VK_RIGHT) && x + 5 <= g_system->srWidth)
	{
		x++;
	}
	if (GetAsyncKeyState(VK_UP) && y - 1 >= 0)
	{
		y--;
	}
	
	if (GetAsyncKeyState(VK_LEFT) && x - 1 >= 0)
	{
		x--;
	}


	if (GetAsyncKeyState(VK_ESCAPE))
	{
		g_system->exit = true;
	}
}

void Title::Render()
{
	g_system->WriteBuffer(x, y, "¿Ï·á");
}

void Title::Activate()
{
	//g_system->SetGameOver(true);
}

void Title::Deactivate()
{
}
