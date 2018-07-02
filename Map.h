#pragma once

class Player;
class Enemy;

class Map
{
public:
	string** map;
	Vector2 vSize;
	list<Vector2> path;
	int min;

private:
	Player* player;
	TileState** visit;

public:
	Map(Player* player, Enemy* enemy, Vector2 size = Vector2(10, 10));
	~Map();

public:
	void WayFinding(int x, int y, int l);

private:
	bool isOver(int x, int y);
};

