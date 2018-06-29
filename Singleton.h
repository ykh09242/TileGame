#pragma once

template <class T>
class Singleton
{
private:
	static T* __instance;

public:
	static T* GetInstance()
	{
		if (__instance == nullptr) 
			__instance = new T();
		return __instance;
	}

	static void PurgeInstance()
	{
		SAFE_DELETE(__instance);
	}
};

template <class T>
T* Singleton<T>::__instance = nullptr;