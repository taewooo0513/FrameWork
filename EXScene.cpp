#include "DXUT.h"
#include "EXScene.h"
#include "EXObject.h"
EXScene::EXScene()
{
}

EXScene::~EXScene()
{
}

void EXScene::Init()
{
	timer = new CDXUTTimer;
	timer->Start();
	OBJ->AddObject(new EXObject(Vec2(0,0)));
	Map = new SmallMap;
	Map->AddMap(5325,"fdas");
}

void EXScene::Update()
{
}

void EXScene::Render()
{
	if (timer->GetTime() >= 3)
	{
	fdsaf += 13;
		OBJ->AddObject(new EXObject(Vec2(fdsaf,0)));
		timer->Reset();
	}
	
}

void EXScene::UIRender()
{
}

void EXScene::Release()
{
	SAFE_DELETE(timer);

}
