#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(string shape, Vector2 startPos, int move)
	: shape(shape), pos(startPos), move(move)
{}
