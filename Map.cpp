#include "stdafx.h"
#include "Map.h"


Map::Map(Vector2 size)
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

			if (r < 10)
				map[i][j] = "бс";
			else
				map[i][j] = "бр";
		}
	}
}


Map::~Map()
{
	for (int i = 0; i < vSize.y; ++i)
	{
		SAFE_DELETE_ARRAY(map[i]);
	}
	SAFE_DELETE_ARRAY(map);
}