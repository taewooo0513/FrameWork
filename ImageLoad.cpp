#include "DXUT.h"
#include "ImageLoad.h"

ImageLoad::ImageLoad()
{
}

ImageLoad::~ImageLoad()
{
	for (auto iter : m_Text)
	{
		iter.second->texturePtr->Release();
		SAFE_DELETE(iter.second);
	}
	m_Text.clear();
}

Texture * ImageLoad::AddImage(const string key, const string path)
{
	auto find = m_Text.find(key);
	if (find == m_Text.end())
	{
		if (D3DXCreateTextureFromFileExA(Device, path.c_str(), -2, -2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, -1, -1, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			Texture * text = new Texture(texturePtr, info);
			m_Text[key] = text;
			return text;
		}
		return nullptr;

	}
	return find->second;
}

Texture * ImageLoad::FindImage(const string key)
{
	auto find = m_Text.find(key);
	if (find == m_Text.end())
	{
		return nullptr;
	}
	return find->second;
}
