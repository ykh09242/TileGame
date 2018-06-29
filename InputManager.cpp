#include "stdafx.h"
#include "InputManager.h"


InputManager::InputManager()
{
	ZeroMemory(bKeyDown, KEYMAX);
	ZeroMemory(bKeyUp, KEYMAX);
}

bool InputManager::StayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		return true;
	}
	return false;
}

bool InputManager::OnceKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (bKeyDown[key] == false)
		{
			bKeyDown[key] = true;
			return true;
		}
	}
	else
	{
		bKeyDown[key] = false;
	}
	return false;
}

bool InputManager::OnceKeyUp(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		bKeyUp[key] = true;
	}
	else
	{
		if (bKeyUp[key] == true)
		{
			bKeyUp[key] = false;
			return true;
		}
	}
	return false;
}

bool InputManager::IsToggleKey(int key)
{
	if (GetAsyncKeyState(key) & 0x0001)
	{
		return true;
	}
	return false;
}
