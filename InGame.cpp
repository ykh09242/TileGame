#include "stdafx.h"
#include "InGame.h"


void InGame::Activate()
{
	randomize();
	map = new Map(Vector2(20, 20));

	player = new Player("¡Ú", Vector2(1, 1));
	enemy = new Enemy("¡Ü", Vector2(5, 5));

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
}

void InGame::Deactivate()
{
	SAFE_DELETE(map);
	SAFE_DELETE(enemy);
	SAFE_DELETE(player);
}