#include "DXUT.h"
#include "SmallMap.h"
#include "EXObject.h"
SmallMap::SmallMap()
{
	
	
}

SmallMap::~SmallMap()
{
}

void SmallMap::AddMap(int seed,string name)
{
	for (int i = 0; i < 21; i++)
	{
		Smooth[i] = Vec2(-1000+i* 100,MATH->SmoothNoise(seed+i));
	}
	for (int i = 0; i < 21; i++)
	{

		if (i != 0 && i != 20)
		{

			for (int j = 0; j < 20; j++)
			{
				D3DXVec2Hermite(&MapPos[i][j], &Smooth[i]
					, &(Smooth[i + 1] -  Smooth[i]) 
					, & Smooth[i + 1] 
					, &(Smooth[i + 2] - Smooth[i + 1] )
					, j * 0.05);

			}
		}
	}

	for (int i = 0; i < 21; )
	{
		for(int j = 0 ; j < 20 ; j ++)
		OBJ->AddObject(new EXObject(MapPos[i][j]),0);
		i++; //еб©Уеб©Уеб©Уеб©Уеб©Уеб©Уеб©Уеб©Уеб©Уеб©У
	}
	
}
