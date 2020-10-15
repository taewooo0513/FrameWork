#pragma once
class SmallMap
{
private:
	CDXUTTimer * timer;
	int Map[1200][4200];
	int Vertical = 0, Horizontal = 0;
	Vec2 Smooth[21];
	Vec2 MapPos[21][20];
public:
	SmallMap();
	~SmallMap();
public:
	void AddMap(int seed, string name);
};

