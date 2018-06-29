#include "stdafx.h"
#include "Title.h"


void Title::Activate()
{
	x = 0;
	y = 0;
}

void Title::Update()
{
	if (g_input->OnceKeyUp(VK_ESCAPE))
	{
		g_system->exit = true;
	}

	if (g_input->StayKeyDown(VK_RIGHT) && x < g_system->srWidth - 3)
	{
		x++;
	}
	if (g_input->StayKeyDown(VK_LEFT) && x > 0)
	{
		x--;
	}
	if (g_input->StayKeyDown(VK_UP) && y > 0)
	{
		y--;
	}
	if (g_input->StayKeyDown(VK_DOWN) && y <= g_system->srHeight - 3)
	{
		y++;
	}

	if (g_input->OnceKeyDown(VK_NUMPAD1))
	{
		g_scene->Activate(sInGame);
	}
}

void Title::Render()
{
	//g_system->WriteBuffer(g_system->srWidth / 2 - 5, g_system->srHeight / 2 - 5, "게임 시작");
	g_system->WriteBuffer(x, y, "ㅇ");
}

void Title::Deactivate()
{
}
