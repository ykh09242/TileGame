#include "stdafx.h"
#include "SceneManager.h"


SceneManager::SceneManager()
	: activateScene(nullptr)
{}

SceneManager::~SceneManager()
{
	for (int i = 0; i < sceneArray.size(); i++)
	{
		SAFE_DELETE(sceneArray[i]);
	}
}

void SceneManager::Update()
{
	if (activateScene)
		activateScene->Update();
}

void SceneManager::Render()
{
	if (activateScene)
		activateScene->Render();
}

void SceneManager::AddScene(SceneName key, BaseScene * value)
{
	sceneArray.push_back(value);
}

void SceneManager::Activate(SceneName key)
{
	if (activateScene)
	{
		activateScene->Deactivate();
	}

	activateScene = sceneArray[key];

	if (activateScene)
	{
		activateScene->Activate();
	}
	else
	{
		assert(!"없는 씬을 활성화하려고 했습니다.");
	}
}
