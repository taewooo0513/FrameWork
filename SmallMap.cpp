#include "DXUT.h"
#include "SmallMap.h"
#include "EXObject.h"
SmallMap::SmallMap()
{
	timer = new CDXUTTimer;
	timer->Start();
	
}

SmallMap::~SmallMap()
{
}

void SmallMap::AddMap(int seed,string name)
{
	for (int i = 0; i < 21; i++)
	{
		Smooth[i] = Vec2(i* 200,MATH->SmoothNoise(seed));
	}
	for (int i = 0; i < 21; i++)
	{

		if (i != 0 && i != 20)
		{

			for (int j = 0; j < 20; j++)
			{
				D3DXVec2Hermite(&MapPos[i], &Smooth[i]
					, &(Smooth[i + 1] -  Smooth[i]) 
					, & Smooth[i + 1] 
					, &(Smooth[i + 2] - Smooth[i + 1] )
					, j * 0.05);
			}
		}
	}

	for (int i = 0; i < 4200; )
	{
		if (timer->GetTime() > 0.0001)
		{
		OBJ->AddObject(new EXObject(MapPos[i]));
		i++;
		timer->Reset();

		}
	}

}
