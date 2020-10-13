#pragma once
#include "Object.h"
class EXObject :public Object
{
private:
	Texture * image;
	Vec2 pos;
	float Sclae = 1;
public:
	EXObject(Vec2 pos);
	virtual ~EXObject();
public:
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Collision(Object * obj) override;
};

