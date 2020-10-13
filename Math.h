#pragma once
#include "singleton.h"
class Math : public singleton<Math>
{
public:
	Math() {};
	~Math() {};
public:
	float Amplitude = 40;
	float WaveLength = 100;
	float Frequency = 1 / WaveLength;
	float Octave = 10;
	float Persistence = 5;
	FLOAT MapSeed(int seed)
	{
		mt19937 mt(seed);
		std::uniform_real_distribution<float>dis(0, 200);
		return dis(mt);
	}
	FLOAT SmoothNoise(FLOAT x)
	{
		return MapSeed(x) / 2 + MapSeed(x - 1) / 4 + MapSeed(x + 1) / 4;
	}

};
#define MATH Math::GetInstance()
