#pragma once

class Vector2
{
public:
	int x;
	int y;

public:
	Vector2(int x = 0, int y = 0);

public:
	Vector2 operator+(const Vector2 Vc);
	Vector2 operator-(const Vector2 Vc);
	Vector2 operator*(const Vector2 Vc);
	Vector2 operator/(const Vector2 Vc);
	bool operator==(const Vector2 Vc);
};