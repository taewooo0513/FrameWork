#pragma once
#include "singleton.h"

class RenderManager : public singleton<RenderManager>
{
private:
	LPDIRECT3DVERTEXBUFFER9 vb;
	LPDIRECT3DINDEXBUFFER9 ib;
	D3DXMATRIXA16 matProj;
public:
	RenderManager();
	~RenderManager();
public:
	void Render(Texture * textureptr, Vec2 pos, Vec2 scale= Vec2(1,1), float rot = 0);
	
};

#define RENDER RenderManager::GetInstance()