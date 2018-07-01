#pragma once
#include "BaseCharacter.h"
#include "Player.h"

class Player;

class Enemy
	: public BaseCharacter
{
public:
	Enemy(int x = 0, int y = 0);
	~Enemy();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
};

