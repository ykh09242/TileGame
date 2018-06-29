#pragma once
#include "BaseScene.h"

class Title
	: public BaseScene
{
private:
	int x, y;

public:
	virtual void Activate() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Deactivate() override;
};

