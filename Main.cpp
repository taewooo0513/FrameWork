#include "DXUT.h"
#include "Main.h"
#include "EXScene.h"
Main::Main()
{
}

Main::~Main()
{
}

void Main::Init()
{
	// 씬만들기
	SCENE->AddScene("예시",new EXScene);
	//이미지 만들기 
	LOADIMAGE->AddImage("예시","./resource/Dirt/Tile1.png");

	SCENE->ChangeScene("예시");
}

void Main::Update()
{
	SCENE->Update();
	OBJ->Update();
}

void Main::Render()
{
	SCENE->Render();
	OBJ->Render();
	UIRENDER->Begin();
	SCENE->UIRender();
	OBJ->UIRender();
	UIRENDER->End();
}

void Main::Release()
{
	SceneManager::ReleaseInstance();
	ImageLoad::ReleaseInstance();
	RenderManager::ReleaseInstance();
	UIRenderManager::ReleaseInstance();
	CamManager::ReleaseInstance();
	ObjectManager::ReleaseInstance();
}

void Main::ResetDevice()
{
	UIRENDER->ResetDevice();
}

void Main::LostDevice()
{
	UIRENDER->LostDevice();
}
