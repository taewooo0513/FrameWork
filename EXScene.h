#pragma once
#include "Scene.h"
#include "SmallMap.h"
class SmallMap;
class EXScene : public Scene
{
private:
	SmallMap * Map;
	CDXUTTimer  * timer;
	Texture * image;
public:
	EXScene();
	virtual ~EXScene();
public:
	float fdsaf = 0;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void UIRender() override;
	virtual void Release() override;
};

