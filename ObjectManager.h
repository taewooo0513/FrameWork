#pragma once
#include "singleton.h"
#include "Object.h"
class Object;
class ObjectManager : public singleton<ObjectManager>
{
public:
	
	list<Object *> L_Obj[Obj_End];
public:
	ObjectManager();
	~ObjectManager();
public:
	Object * AddObject(Object * obj, int tag);
	void Update();
	void Render();
	void UIRender();
	void Release();
};

#define OBJ ObjectManager::GetInstance()