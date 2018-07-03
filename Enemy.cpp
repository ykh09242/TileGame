#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy(string shape, Vector2 startPos, int move)
	: shape(shape), pos(startPos), move(move), turnEnd(false)
{}

void Enemy::Moving(Player* player, Map* map)
{
	while (!turnEnd)
	{
		if (g_input->OnceKeyDown(VK_ESCAPE))
		{
			g_scene->Activate(sTitle);
			return;
		}

		Vector2 dirLen[D_END] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

		auto findResult = FindNext(player, map);

		map->map[pos.y][pos.x] = "��";

		pos.x += dirLen[findResult].x;
		pos.y += dirLen[findResult].y;

		map->map[pos.y][pos.x] = shape;
		turnEnd = true;
	}
	return;
}

Enemy::Dir Enemy::FindNext(Player* player, Map* maps)
{
	Vector2 dirLen[D_END] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };

	vector<vector<tile>> cost;

	for (int i = 0; i < maps->vSize.y; i++)
		cost.push_back(vector<tile>(maps->vSize.x, make_pair(9999, D_END)));

	//Ž������
	//player->pos��ó Ÿ�ϵ��� cost�� dir�� �ʱ�ȭ
	for (int i = 0; i < D_END; i++)
	{
		int xPos = player->pos.x + dirLen[i].x;
		int yPos = player->pos.y + dirLen[i].y;

		if (IsCanGoing(xPos, yPos, maps))
		{
			cost[yPos][xPos].first = 1;
			cost[yPos][xPos].second = (Dir)(i ^ 1);
		}
	}

	//�ݺ�
	while (true)
	{
		//���� ���� ���� cost�� ���� Ÿ��
		int minValue = 4999;
		int yPosTemp = -1;
		int xPosTemp = -1;
		for (int i = 0; i < maps->vSize.y; i++)
		{
			for (int j = 0; j < maps->vSize.x; j++)
			{
				if (cost[i][j].first < minValue)
				{
					yPosTemp = i;
					xPosTemp = j;
					minValue = cost[i][j].first;
				}
			}
		}

		for (int i = 0; i < D_END; i++)
		{
			int xPos = xPosTemp + dirLen[i].x;
			int yPos = yPosTemp + dirLen[i].y;

			//ã�� Ÿ���� pos�� this->pos�� ��� return;
			if (this->pos.x == xPos && this->pos.y == yPos)
			{
				return (Dir)(i ^ 1);
			}

			if (IsCanGoing(xPos, yPos, maps))
			{
				//�� �ֺ� Ÿ�ϵ��� cost�� dir�� �ʱ�ȭ
				auto& costTemp = cost[yPos][xPos];
				if (costTemp.first > cost[yPosTemp][xPosTemp].first + 1)
				{
					costTemp.first = cost[yPosTemp][xPosTemp].first + 1;
					costTemp.second = (Dir)(i ^ 1);
				}
			}
		}
		cost[yPosTemp][xPosTemp].first = 5000;
	}

	return D_END;//���� ������� ����;
}

bool Enemy::IsCanGoing(int x, int y, Map* maps)
{
	if (x < 0 || y < 0 || x >= maps->vSize.x || y >= maps->vSize.y)
		return false;

	return maps->map[y][x] == (string)"��";
}
