#pragma once
#include "singleton.h"
class UIRenderManager : public singleton<UIRenderManager>
{
private:
	LPD3DXFONT Font = nullptr;
	LPD3DXSPRITE sprite = nullptr;
public:
	UIRenderManager();
	~UIRenderManager();
public:
	void Begin();
	void End();
	void ResetDevice();
	void LostDevice();
	void Render(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size = D3DXVECTOR2(1, 1), float rot = 0, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size = D3DXVECTOR2(1, 1), float rot = 0, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void TextDraw(string str, Vec2 pos, float size, bool center, D3DCOLOR color);
};

#define UIRENDER UIRenderManager::GetInstance()
