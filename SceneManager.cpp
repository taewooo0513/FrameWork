#include "DXUT.h"
#include "SceneManager.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}

Scene * SceneManager::AddScene(string key, Scene * scene)
{
	if (!scene)
		return nullptr;
	if (m_Scene.find(key) != m_Scene.end())
		return nullptr;
	m_Scene[key] = scene;
	return scene;
}

void SceneManager::ChangeScene(string key)
{
	auto find = m_Scene.find(key);
	if (find == m_Scene.end())
		return;
	NextScene = find->second;
}

void SceneManager::Update()
{
	if (NextScene)
	{
		if (NowScene)
		{
			NowScene->Release();
		}
		NowScene = NextScene;
		NextScene = nullptr;
		NowScene->Init();
	}
	if (NowScene)
	{
		NowScene->Update();
	}
}

void SceneManager::Render()
{
	if (NowScene)
		NowScene->Render();
}

void SceneManager::UIRender()
{
	if (NowScene)
		NowScene->UIRender();
}

void SceneManager::Release()
{
	if (NowScene)
	{
		NowScene->Release();
	}
	for (auto iter : m_Scene)
	{
		SAFE_DELETE(iter.second);
	}
	m_Scene.clear();
}
