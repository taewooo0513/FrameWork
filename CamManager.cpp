#include "DXUT.h"
#include "CamManager.h"

CamManager::CamManager()
{
}

CamManager::~CamManager()
{
}

void CamManager::SetCamPos(Vec2 pos)
{
	CamUp = Vec3(0.f,1.f,0.f);
	CamPos = Vec3(pos.x,pos.y , -100);
	CamAt = Vec3(pos.x,pos.y,0.f);
	D3DXMatrixLookAtLH(&matView, &CamPos, &CamAt, &CamUp);
	Device->SetTransform(D3DTS_VIEW, &matView);
}

Vec2 CamManager::GetCamPos()
{
	return Vec2(CamPos.x,CamPos.y);
}
