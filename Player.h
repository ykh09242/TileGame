#pragma once

class Player
{
public:
	string shape;
	Vector2 pos;
	int move;

public:
	Player(string shape, Vector2 startPos, int move = 1);

public:
	void Moving(Map* map);
};

