#pragma once

class Player;
class Enemy;

class Map
{
private:
	int vertex, edge, startNum;

public:
	string** map;
	Vector2 vSize;

public:
	Map(Player* player, Enemy* enemy, Vector2 size = Vector2(10, 10));
	~Map();

public:
	void WayFinding(Player* player, Enemy* enemy);

private:
	bool isOver(int x, int y);
};

