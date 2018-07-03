#pragma once

class Enemy
{
public:
	string shape;
	Vector2 pos;
	int move;
	bool turnEnd;

public:
	Enemy(string shape, Vector2 startPos, int move = 1);

	void Moving(Player* player, Map* map);

private:

	enum Dir
	{
		D_L, D_R, D_T, D_B, D_END
	};

	typedef pair<int, Dir> tile;

	Dir FindNext(Player* player, Map* maps);
	bool IsCanGoing(int x, int y, Map* maps);
};

