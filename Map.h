#pragma once

class Map
{
public:
	string** map;
	Vector2 vSize;

public:
	Map(Vector2 size = Vector2(10, 10));
	~Map();
};

