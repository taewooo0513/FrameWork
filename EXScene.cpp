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
	OBJ->AddObject(new EXObject(Vec2(0,0)),0);
	Map = new SmallMap;
	Map->AddMap(5325,"fdas");
}

void EXScene::Update()
{
}

void EXScene::Render()
{
	CAM->SetCamPos(Vec2(0,0));
	if (timer->GetTime() >= 3)
	{
	fdsaf += 13;
	//	OBJ->AddObject(new EXObject(Vec2(19000,0)));
		timer->Reset();
	}
	
}

void EXScene::UIRender()
{
	UIRENDER->TextDraw(to_string(DXUTGetFPS()), Vec2(500, 500), 50, true, D3DCOLOR_XRGB(255, 255, 255));

	UIRENDER->TextDraw(to_string(CAM->GetCamPos().x), Vec2(500, 200), 50, true, D3DCOLOR_XRGB(255, 255, 255));

}

void EXScene::Release()
{
	SAFE_DELETE(timer);

}
