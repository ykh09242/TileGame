#pragma once
#include "BaseScene.h"

class InGame :
	public BaseScene
{
public:
	virtual void Activate() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Deactivate() override;
};

