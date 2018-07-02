#include "stdafx.h"
#include "Vector2.h"


Vector2::Vector2(int x, int y)
	: x(x), y(y)
{}

Vector2 Vector2::operator+(const Vector2 Vc)
{
	Vector2 plus;
	plus.x = x += Vc.x;
	plus.y = y += Vc.y;
	return plus;
}

Vector2 Vector2::operator-(const Vector2 Vc)
{
	Vector2 minus;
	minus.x = x -= Vc.x;
	minus.y = y -= Vc.y;
	return minus;
}

Vector2 Vector2::operator*(const Vector2 Vc)
{
	Vector2 multiplication;
	multiplication.x *= Vc.x;
	multiplication.y *= Vc.y;
	return multiplication;
}

Vector2 Vector2::operator/(const Vector2 Vc)
{
	Vector2 division;
	division.x = x /= Vc.x;
	division.y = y /= Vc.y;
	return Vector2();
}

bool Vector2::operator==(const Vector2 Vc)
{
	if(x == Vc.x && y == Vc.y)
		return true;
	return false;
}
