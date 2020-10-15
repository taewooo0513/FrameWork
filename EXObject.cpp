#include "DXUT.h"
#include "EXObject.h"

EXObject::EXObject(Vec2 pos)
	:pos(pos)
{
	image = LOADIMAGE->FindImage("¿¹½Ã");
}

EXObject::~EXObject()
{
}

void EXObject::Update()
{
	SetPos(pos);
}

void EXObject::Render()
{
	RENDER->Render(image,GetPos(),Vec2(Sclae, Sclae));
}

void EXObject::UIRender()
{
}

void EXObject::Collision(Object * obj)
{
}
