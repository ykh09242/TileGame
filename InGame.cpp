#include "stdafx.h"
#include "InGame.h"


void InGame::Activate()
{
	string temp[10][10] =
	{
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" },
		{ "бр", "бр", "бр", "бр" , "бр" ,"бр" ,"бр" ,"бр" , "бр", "бр" }
	};
	map = new Map();
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			map->map[i][j] = temp[i][j];

	player = new Player("бс", Vector2(1, 1));
	enemy = new Enemy("б▄", Vector2(5, 5));

	
}

void InGame::Update()
{
	if (g_input->OnceKeyDown(VK_ESCAPE))
	{
		g_scene->Activate(sTitle);
		return;
	}
}

void InGame::Render()
{
	map->map[player->pos.x][player->pos.y] = player->shape;
	map->map[enemy->pos.x][enemy->pos.y] = enemy->shape;

	for (int i = 0; i < 10; ++i)
	{
		int z = 0;
		for (int j = 0; j < 20; j += 2)
			g_system->WriteText(j + 30, i + 8, map->map[i][z++].c_str());
	}

	
}

void InGame::Deactivate()
{
	SAFE_DELETE(map);
	SAFE_DELETE(enemy);
	SAFE_DELETE(player);
}