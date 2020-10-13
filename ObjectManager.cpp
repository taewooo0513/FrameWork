#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

Object * ObjectManager::AddObject(Object * obj)
{
	if (obj)
	{
		L_Obj.push_back(obj);
	}
	return obj;
}

void ObjectManager::Update()
{
	RECT rt = { 0,0,0,0 };
	for (auto iter = L_Obj.begin(); iter != L_Obj.end();)
	{
		(*iter)->Update();
		if ((*iter)->GetRect().left != rt.left && (*iter)->GetRect().bottom != rt.bottom && (*iter)->GetRect().right != rt.right && (*iter)->GetRect().top != rt.top)
		{
			for (auto& _iter : L_Obj)
			{
				if (IntersectRect(&rt, &(*iter)->GetRect(), &_iter->GetRect()))
				{
					(*iter)->Collision(_iter);
				}
			}
		}
		if ((*iter)->ObjDel() == true)
		{
			delete(*iter);
			iter = L_Obj.erase(iter);
		}
		else
			iter++;
	}
}

void ObjectManager::Render()
{
	for (auto iter : L_Obj)
	{
		iter->Render();
	}
}

void ObjectManager::UIRender()
{
	for (auto iter : L_Obj)
	{
		iter->UIRender();
	}
}

void ObjectManager::Release()
{
	for (auto iter : L_Obj)
	{
		SAFE_DELETE(iter);
	}
	L_Obj.clear();
}
