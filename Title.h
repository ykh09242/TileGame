#pragma once
#include "BaseScene.h"

class Title
	: public BaseScene
{
public:
	Title();
	~Title();

private:
	int x, y;

public:
	virtual void Update() override;
	virtual void Render() override;

	virtual void Activate() override;
	virtual void Deactivate() override;
};

