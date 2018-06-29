#pragma once
#include "Singleton.h"

class InputManager :
	public Singleton<InputManager>
{
public:
	InputManager();

private:
	bool bKeyDown[KEYMAX];
	bool bKeyUp[KEYMAX];

public:
	bool StayKeyDown(int key);
	bool OnceKeyDown(int key);
	bool OnceKeyUp(int key);
	bool IsToggleKey(int key);
};

