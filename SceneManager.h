#pragma once

class SceneManager
	: public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

private:
	BaseScene* activateScene;
	vector<BaseScene*> sceneArray;

public:
	void Update();
	void Render();

	void AddScene(SceneName key, BaseScene* value);
	void Activate(SceneName key);
};

