#include "DXUT.h"
#include "UIRenderManager.h"

UIRenderManager::UIRenderManager()
{
	D3DXCreateSprite(Device, &sprite);
}

UIRenderManager::~UIRenderManager()
{
	sprite->Release();
}

void UIRenderManager::Begin()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void UIRenderManager::End()
{
	sprite->End();
}

void UIRenderManager::ResetDevice()
{
	sprite->OnResetDevice();
}

void UIRenderManager::LostDevice()
{
	sprite->OnLostDevice();
}

void UIRenderManager::Render(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size, float rot, D3DCOLOR color)
{
	D3DXMATRIXA16 mat;
	if (texturePtr == nullptr)
	{
		return;
	}
	else
	{
		D3DXMatrixTransformation2D(&mat, nullptr, 0, &size, nullptr, rot, &pos);
		sprite->SetTransform(&mat);
		sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void UIRenderManager::CenterRender(Texture * texturePtr, D3DXVECTOR2 pos, D3DXVECTOR2 size, float rot, D3DCOLOR color)
{
	Render(texturePtr, Vec2(pos.x - texturePtr->info.Width / 2, pos.y - texturePtr->info.Height / 2), size, rot, color);
}

void UIRenderManager::TextDraw(string str, Vec2 pos, float size, bool center, D3DCOLOR color)
{
	D3DXMATRIXA16 mat;
	if (!center)
	{
		D3DXCreateFontA(Device, size, 0, 10, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Comic Sans Ms", &Font);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else
	{
		D3DXCreateFontA(Device, size, 0, 0, 1, FALSE, DEFAULT_CHARSET, 0, 0, 0, "Comic Sans Ms", &Font);
		D3DXMatrixTranslation(&mat, pos.x - size * (str.size()*0.25), pos.y - size / 2.f, 0);
	}
	sprite->SetTransform(&mat);
	Font->DrawTextA(sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);
	SAFE_RELEASE(Font);
}
