#pragma once
#include "singleton.h"
class ImageLoad : public singleton<ImageLoad>
{
private:
	map <string, Texture *> m_Text;
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;
public:
	ImageLoad();
	~ImageLoad();
public:
	Texture * AddImage(const string key, const string path);
	Texture * FindImage(const string key);
};

#define LOADIMAGE ImageLoad::GetInstance()