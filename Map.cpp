#include "stdafx.h"
#include "Map.h"


Map::Map(Player* player, Enemy* enemy, Vector2 size)
	: vSize(size)
{
	map = new string*[size.y];


	for (int i = 0; i < size.y; ++i)
	{
		map[i] = new string[size.x];
	}

	for (int i = 0; i < vSize.y; i++)
	{
		for (int j = 0; j < vSize.x; j++)
		{
			int r = random(100);

			if (r < 15)
				map[i][j] = "бс";
			else
				map[i][j] = "бр";
		}
	}

	WayFinding(player, enemy);
}

Map::~Map()
{
	for (int i = 0; i < vSize.y; ++i)
	{
		SAFE_DELETE_ARRAY(map[i]);
	}
	SAFE_DELETE_ARRAY(map);
}

void Map::WayFinding(Player* player, Enemy* enemy)
{
	int cnt = 1;
	int** cost;
	bool** visit;

	visit = new bool*[vSize.y];
	cost = new int*[vSize.y];

	for (int i = 0; i < vSize.y; ++i)
	{
		visit[i] = new bool[vSize.x];
		cost[i] = new int[vSize.x];

		memset(visit[i], false, sizeof(bool) * vSize.x);
		memset(cost[i], 0, sizeof(int) * vSize.x);
	}

	for (int i = 0; i < vSize.y; ++i)
	{
		for (int j = 0; j < vSize.x; ++j)
		{
			if (map[i][j] == "бс")
			{
				visit[i][j] = true;
			}
		}
	}

	cost[enemy->pos.y][enemy->pos.x] = 0;
	visit[enemy->pos.y][enemy->pos.x] = true;

	for (int i = enemy->pos.y; i < vSize.y; ++i)
	{
		for (int j = enemy->pos.x; j < vSize.x; ++j)
		{
			int count = cnt;
			for (int y = -1; y < 2; ++y)
			{
				for (int x = -1; x < 2; ++x)
				{
					if (y == 0 && x == 0)
						continue;

					if (x != 0 || y != 0)
						count += 2;
					else
						count += 1;

					if (!isOver(j + x, i + y) && visit[i + y][j + x] == false)
					{
						cost[i + y][j + x] = cnt;
						visit[i + y][j + x] = true;
					}

					count = cnt;
				}
			}
		}
	}

	for (int i = enemy->pos.y; i >= 0; --i)
	{
		for (int j = enemy->pos.x; j >= 0; --j)
		{
			int count = cnt;
			for (int y = -1; y < 2; ++y)
			{
				for (int x = -1; x < 2; ++x)
				{
					if (y == 0 && x == 0)
						continue;

					if (x != 0 || y != 0)
						count += 2;
					else
						count += 1;

					if (!isOver(j + x, i + y) && visit[i + y][j + x] == false)
					{
						cost[i + y][j + x] = cnt;
						visit[i + y][j + x] = true;
					}

					count = cnt;
				}
			}
			cnt += 2;
		}
	}

	for (int i = 0; i < vSize.y; ++i)
	{
		for (int j = 0; j < vSize.x; ++j)
		{
			if (visit[i][j] == true)
			{
				int a;
			}
			else
			{
				int b;
			}
		}
	}
}

bool Map::isOver(int x, int y)
{
	if (x < 0 || x >= vSize.x || y < 0 || y >= vSize.y)
		return true;
	return false;
}

