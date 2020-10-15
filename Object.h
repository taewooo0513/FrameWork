#pragma once
	enum Tag
	{
		Block,
		Obj_End
	}; 
class Object abstract
{
private:
	RECT rt;
	bool DelObj =false;
	Vec2 Pos;
public:
	vector<Tag> CollisionWith;
	Object() {};
	virtual ~Object() {};
public:
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void UIRender() PURE;
	virtual void Collision(Object * obj) PURE;
	
public:
	Vec2 GetPos() { return Pos; }
	void SetPos(Vec2 pos) { Pos = pos; }
	void DestroyObj() { DelObj = true; }
	bool ObjDel() { return DelObj; }
	RECT GetRect() { return rt; }
	void SetRect(Texture * texturePtr,Vec2 pos) { rt = { long(pos.x - texturePtr->info.Width/2) ,long(pos.y - texturePtr->info.Height/ 2),long(pos.x + texturePtr->info.Width / 2),long(pos.y + texturePtr->info.Height / 2) }; }
};

