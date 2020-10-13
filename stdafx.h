#pragma once
#include <list>
#include <map>
#include <vector>
#include <string>
#include <random>
#include <math.h>
using namespace std;

const int WINSIZEX = 1920;
const int WINSIZEY = 1080;
static int GameSpeed = 1;
#define Vec2 D3DXVECTOR2
#define Vec3 D3DXVECTOR3

#define Device DXUTGetD3D9Device() 
#define DTime DXUTGetElapsedTime() * GameSpeed;
class Texture
{
public:
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;
public:
	Texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		:texturePtr(texturePtr),info(info)
	{
	}
	~Texture() 
	{
	}
};
struct VerTex
{
	Vec3 pos;
	Vec2 uv;
	inline static constexpr DWORD FVF = D3DFVF_XYZ | D3DFVF_TEX1;
};
#include "SceneManager.h"
#include "ImageLoad.h"
#include "UIRenderManager.h"
#include "RenderManager.h"
#include "CamManager.h"
#include "ObjectManager.h"
#include "Math.h"