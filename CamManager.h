#pragma once
#include "singleton.h"
class CamManager :public singleton<CamManager>
{
private:
	Vec3 CamPos;
	Vec3 CamUp;
	Vec3 CamAt;
	D3DXMATRIXA16 matView;
public:
	CamManager();
	~CamManager();
public:
	void SetCamPos(Vec2 pos);
	Vec2 GetCamPos();
};

#define CAM CamManager::GetInstance()
