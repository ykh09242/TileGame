#include "stdafx.h"
#include "Title.h"


void Title::Activate()
{
}

void Title::Update()
{
	if (g_input->OnceKeyDown(VK_NUM1))
	{
		g_scene->Activate(sInGame);
		return;
	}

	if (g_input->OnceKeyDown(VK_NUM2) || g_input->OnceKeyDown(VK_ESCAPE))
	{
		g_system->exit = true;
	}
}

void Title::Render()
{
	g_system->WriteText(g_system->srWidth / 2 - 14, g_system->srHeight / 2 - 3, "1. 게임 시작   2. 게임 종료");
}

void Title::Deactivate()
{
}
