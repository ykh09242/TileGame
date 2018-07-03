#include "stdafx.h"
#include "InGame.h"


void InGame::Activate()
{
	randomize();

	map = new Map(Vector2(20, 20));

	randX = random(map->vSize.x - 1);
	randY = random(map->vSize.y - 1);
	while (map->map[randY][randX] != "бс")
	{
		randX = random(map->vSize.x);
		randY = random(map->vSize.y);
	}
	player = new Player("б┌", Vector2(randX, randY));

	randX = random(map->vSize.x - 1);
	randY = random(map->vSize.y - 1);

	while (map->map[randY][randX] != "бс")
	{
		randX = random(map->vSize.x);
		randY = random(map->vSize.y);
	}
	enemy = new Enemy("б▄", Vector2(randX, randY));

	turn = PlayerTurn;
}

void InGame::Update()
{
	randomize();

	switch (turn)
	{
	case PlayerTurn:
		player->turnEnd = false;
		turn = EnemyTurn;
		r = random(100);
		randX = random(map->vSize.x - 1);
		randY = random(map->vSize.y - 1);
		if (r < 10)
		{
			if (map->map[randY][randX] == "бс")
			{
				randX = random(map->vSize.x);
				randY = random(map->vSize.y);
			}
			map->map[randY][randX] = "б▀";
		}
		player->Moving(map);
		break;
	case EnemyTurn:
		enemy->turnEnd = false;
		turn = PlayerTurn;
		enemy->Moving(player, map);
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