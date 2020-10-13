#pragma once
#include "singleton.h"
#include "Scene.h"

class Scene;
class SceneManager : public singleton<SceneManager>
{
private:
	map < string, Scene*> m_Scene;
	Scene * NowScene = nullptr, *NextScene = nullptr;
public:
	SceneManager();
	~SceneManager();
public:
	Scene * AddScene(string key, Scene* scene);
	void ChangeScene(string key);
	void Update();
	void Render();
	void UIRender();
	void Release();
};

#define SCENE SceneManager::GetInstance()