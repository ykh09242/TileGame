#include "stdafx.h"
#include "InGame.h"


void InGame::Activate()
{
	randomize();

	player = new Player("¡Ú", Vector2(1, 1));
	enemy = new Enemy("¡Ü", Vector2(3, 3));
	map = new Map(player, enemy, Vector2(5, 5));

	turn = PlayerTurn;
}

void InGame::Update()
{
	if (g_input->OnceKeyDown(VK_ESCAPE))
	{
		g_scene->Activate(sTitle);
		return;
	}

	switch (turn)
	{
	case PlayerTurn:
		player->Moving(map);
		break;
	case EnemyTurn:
		break;
	}
}

void InGame::Render()
{
	map->map[player->pos.y][player->pos.x] = player->shape;
	map->map[enemy->pos.y][enemy->pos.x] = enemy->shape;

	for (int i = 0; i < map->vSize.y; ++i)
	{
		int z = 0;
		for (int j = 0; j < map->vSize.x * 2; j += 2)
			g_system->WriteText(j, i, map->map[i][z++].c_str());
	}
	map->min = map->vSize.x * map->vSize.y;
	map->WayFinding(enemy->pos.x, enemy->pos.y, 1);
	g_system->WriteText(30, 30, to_string(map->min - 1).c_str());
	g_system->WriteText(40, 10, to_string(map->path.back().x).c_str());
	g_system->WriteText(50, 10, to_string(map->path.back().y).c_str());
	
}

void InGame::Deactivate()
{
	SAFE_DELETE(map);
	SAFE_DELETE(enemy);
	SAFE_DELETE(player);
}