#include "stdafx.h"
#include "Map.h"


Map::Map(Player* player, Enemy* enemy, Vector2 size)
	: vSize(size), player(player)
{
	map = new string*[vSize.y];
	visit = new TileState*[vSize.y];

	for (int i = 0; i < vSize.y; ++i)
	{
		map[i] = new string[vSize.x];
		visit[i] = new TileState[vSize.x];

		memset(visit[i], Open, sizeof(TileState) * vSize.x);
	}

	for (int i = 0; i < vSize.y; i++)
	{
		for (int j = 0; j < vSize.x; j++)
		{
			int r = random(100);

			//if (r < 15)
			//{
			//	map[i][j] = "бс";
			//	visit[i][j] = Close;
			//}
			//else
				map[i][j] = "бр";
		}
	}

	min = vSize.x * vSize.y;
}

Map::~Map()
{
	for (int i = 0; i < vSize.y; ++i)
	{
		SAFE_DELETE_ARRAY(visit[i]);
	}
	SAFE_DELETE_ARRAY(visit);

	for (int i = 0; i < vSize.y; ++i)
	{
		SAFE_DELETE_ARRAY(map[i]);
	}
	SAFE_DELETE_ARRAY(map);
}

void Map::WayFinding(int x, int y, int l)
{
	if (x == player->pos.x && y == player->pos.y)
	{
		if (min > l) min = l;
		return;
	}

	visit[y][x] = Close;

	if (!isOver(x, y - 1) && map[y - 1][x] != "бс" && visit[y - 1][x] != Close)
	{
		path.push_back(Vector2(x, y - 1));
		WayFinding(x, y - 1, l + 1);
	}
	if (!isOver(x, y + 1) && map[y + 1][x] != "бс" && visit[y + 1][x] != Close)
	{
		path.push_back(Vector2(x, y + 1));
		WayFinding(x, y + 1, l + 1);
	}
	if (!isOver(x - 1, y) && map[y][x - 1] != "бс" && visit[y][x - 1] != Close)
	{
		path.push_back(Vector2(x - 1, y));
		WayFinding(x - 1, y, l + 1);
	}
	if (!isOver(x + 1, y) && map[y][x + 1] != "бс" && visit[y][x + 1] != Close)
	{
		path.push_back(Vector2(x + 1, y));
		WayFinding(x + 1, y, l + 1);
	}

	visit[y][x] = Open;
	if (path.back().x != player->pos.x && path.back().y != player->pos.y)
		path.pop_back();
	return;
}

bool Map::isOver(int x, int y)
{
	if (x < 0 || x >= vSize.x || y < 0 || y >= vSize.y)
		return true;
	return false;
}

