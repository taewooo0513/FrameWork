#include "DXUT.h"
#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}

Object * ObjectManager::AddObject(Object * obj,int tag)
{
	if (obj)
	{
		L_Obj[tag].push_back(obj);
	}
	return obj;
}

void ObjectManager::Update()
{
	RECT rt = { 0,0,0,0 };
	Vec2 pos;
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto iter = L_Obj[Tag].begin(); iter != L_Obj[Tag].end();)
		{
			if ((*iter)->GetPos() != pos)
			{

				if ((*iter)->GetPos().x < CAM->GetCamPos().x + WINSIZEX / 2 && (*iter)->GetPos().x > CAM->GetCamPos().x - WINSIZEX / 2)
				{
					if ((*iter)->GetRect().left != rt.left && (*iter)->GetRect().bottom != rt.bottom && (*iter)->GetRect().right != rt.right && (*iter)->GetRect().top != rt.top)
					{
						for (auto& CollTag : (*iter)->CollisionWith)
						{
							for (auto& _iter : L_Obj[CollTag])
							{
								if (IntersectRect(&rt, &(*iter)->GetRect(), &_iter->GetRect()))
								{
									(*iter)->Collision(_iter);
								}
							}
						}
					}
				}
			}
			(*iter)->Update();

			if ((*iter)->ObjDel() == true)
			{
				delete(*iter);
				iter = L_Obj[Tag].erase(iter);
			}
			else
				iter++;
		}
	}
}

void ObjectManager::Render()
{
	Vec2 pos;
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto iter : L_Obj[Tag])
		{
			if (iter->GetPos() != pos)
			{

				if (iter->GetPos().x < CAM->GetCamPos().x + WINSIZEX / 2 && iter->GetPos().x > CAM->GetCamPos().x - WINSIZEX / 2)
				{
					iter->Render();
				}
			}
		}
	}
}

void ObjectManager::UIRender()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto iter : L_Obj[Tag])
		{
			iter->UIRender();
		}
	}
	UIRENDER->TextDraw(to_string(Obj_End), Vec2(500, 100), 50, true, D3DCOLOR_XRGB(255, 255, 255));

}

void ObjectManager::Release()
{
	for (int Tag = 0; Tag < Obj_End; Tag++)
	{
		for (auto iter : L_Obj[Tag])
		{
			SAFE_DELETE(iter);
		}
		L_Obj[Tag].clear();
	}
}
