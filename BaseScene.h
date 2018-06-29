#pragma once

class BaseScene
{
public:
	virtual void Update() PURE;
	virtual void Render() PURE;

	virtual void Activate() PURE;
	virtual void Deactivate() PURE;
};