#pragma once

class Vector2
{
public:
	int x;
	int y;
	int travelCost;	

public:
	Vector2()
		: x(0), y(0)
	{}
	Vector2(int x, int y)
		: x(x), y(y)
	{}
	Vector2(int x, int y, int cost) 
		: x(x), y(y), travelCost(cost)
	{}
public:
	Vector2 & operator=(const Vector2& target)
	{
		if (*this != target)
		{
			x = target.x;
			x = target.x;
			travelCost = target.travelCost;
		}

		return *this;
	}

	bool operator==(const Vector2& target) const
	{
		return x == target.x && y == target.y;
	}

	bool operator!=(const Vector2& target) const
	{
		return !(*this == target);
	}

	bool operator<(const Vector2& target) const
	{
		return target.travelCost < travelCost;
	}
};