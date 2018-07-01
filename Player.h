#pragma once
#include "BaseCharacter.h"
#include "Enemy.h"

class Enemy;

class Player
	: public BaseCharacter
{
public:
	Player();
	~Player();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Destroy() override;
};

