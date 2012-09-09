#pragma once
#include "Population.h"

namespace GenVec
{

class GenVecPop :
	public Population
{
public:
	GenVecPop(int generationRate, float mutationRate, mt19937& gen);
	virtual ~GenVecPop(void);
protected:
	void calcFitness();
};

}