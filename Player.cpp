#include "stdafx.h"
#include "Player.h"


Player::Player(string shape, Vector2 startPos, int move)
	: shape(shape), pos(startPos), move(move), turnEnd(false), item(false)
{}

void Player::Moving(Map* map)
{
	while (!turnEnd)
	{
		item = false;

		if (g_input->OnceKeyDown(VK_ESCAPE))
		{
			g_scene->Activate(sTitle);
			return;
		}

		if (g_input->OnceKeyDown(VK_UP) && pos.y > 0 && map->map[pos.y - move][pos.x] != "бс")
		{
			map->map[pos.y][pos.x] = "бр";


			if (pos.y - move < 0)
				pos.y = 0;
			else
			{
				if (map->map[pos.y - move][pos.x] == "б▀")
					item = true;
				pos.y -= move;
				if (item)
					move++;
			}
			turnEnd = true;
			return;
		}
		if (g_input->OnceKeyDown(VK_DOWN) && pos.y < map->vSize.y - 1 && map->map[pos.y + move][pos.x] != "бс")
		{
			map->map[pos.y][pos.x] = "бр";

			if (pos.y + move >= map->vSize.y - 1)
				pos.y = map->vSize.y - 1;
			else
			{
				if (map->map[pos.y + move][pos.x] == "б▀")
					item = true;
				pos.y += move;
				if (item)
					move++;
			}
			turnEnd = true;
			return;
		}
		if (g_input->OnceKeyDown(VK_LEFT) && pos.x > 0 && map->map[pos.y][pos.x - move] != "бс")
		{
			map->map[pos.y][pos.x] = "бр";

			if (pos.x - move < 0)
				pos.x = 0;
			else
			{
				if (map->map[pos.y][pos.x - move] == "б▀")
					item = true;
				pos.x -= move;
				if (item)
					move++;
			}
			turnEnd = true;
			return;
		}
		if (g_input->OnceKeyDown(VK_RIGHT) && pos.x < map->vSize.x - 1 && map->map[pos.y][pos.x + move] != "бс")
		{
			map->map[pos.y][pos.x] = "бр";

			if (pos.x + move > map->vSize.x - 1)
				pos.x = map->vSize.y - 1;
			else
			{
				if (map->map[pos.y][pos.x + move] == "б▀")
					item = true;
				pos.x += move;
				if (item)
					move++;
			}
			turnEnd = true;
			return;
		}
	}
}
