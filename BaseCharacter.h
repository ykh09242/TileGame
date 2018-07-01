#pragma once

class BaseCharacter
{
public:
	virtual void Initialize() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Destroy() PURE;
};

