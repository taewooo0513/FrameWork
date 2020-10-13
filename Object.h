#pragma once
class Object abstract
{
private:
	string tag = "None";
	RECT rt;
	bool DelObj =false;
public:
	Object() {};
	virtual ~Object() {};
public:
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void UIRender() PURE;
	virtual void Collision(Object * obj) PURE;
	
public:
	void DestroyObj() { DelObj = true; }
	bool ObjDel() { return DelObj; }
	RECT GetRect() { return rt; }
	void SetRect(Texture * texturePtr,Vec2 pos) { rt = { long(pos.x - texturePtr->info.Width/2) ,long(pos.y - texturePtr->info.Height/ 2),long(pos.x + texturePtr->info.Width / 2),long(pos.y + texturePtr->info.Height / 2) }; }
};

