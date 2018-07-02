#pragma once
#include "BaseScene.h"

class InGame 
	: public BaseScene
{
private:
	struct Vector2
	{
		int x;
		int y;

		Vector2(int x = 0, int y = 0)
			: x(x), y(y)
		{}
	};

	struct Map
	{
		string** map;
		Vector2 size;

		Map(Vector2 size = Vector2(10, 10))
			: size(size)
		{
			map = new string*[size.y];

			for (int i = 0; i < size.y; ++i)
			{
				map[i] = new string[size.x];
			}
		}
		~Map()
		{
			for (int i = 0; i < size.y; ++i)
			{
				SAFE_DELETE_ARRAY(map[i]);
			}
			SAFE_DELETE_ARRAY(map);
		}
	};

	struct Player
	{
		string shape;
		Vector2 pos;
		int move;

		Player(string shape, Vector2 startPos, int move = 1)
			: shape(shape), pos(startPos), move(move)
		{}
	};

	struct Enemy
	{
		string shape;
		Vector2 pos;
		int move;

		Enemy(string shape, Vector2 startPos, int move = 1)
			: shape(shape), pos(startPos), move(move)
		{}
	};

private:
	Map * map;
	Player* player;
	Enemy* enemy;

public:
	virtual void Activate() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Deactivate() override;
};

