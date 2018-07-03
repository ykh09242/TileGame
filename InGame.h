#pragma once
#include "BaseScene.h"

class InGame 
	: public BaseScene
{
private:
	Turn turn;
	Map * map;
	Player* player;
	Enemy* enemy;

	int randX;
	int randY;
	int r;

public:
	virtual void Activate() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Deactivate() override;
};

