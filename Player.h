#pragma once

class Player
{
public:
	string shape;
	Vector2 pos;
	int move;
	bool turnEnd;

private:
	bool item;
public:
	Player(string shape, Vector2 startPos, int move = 1);

public:
	void Moving(Map* map);
};

