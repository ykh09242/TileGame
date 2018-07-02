#pragma once

class Enemy
{
public:
	string shape;
	Vector2 pos;
	int move;

public:
	Enemy(string shape, Vector2 startPos, int move = 1);
};

