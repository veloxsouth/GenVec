#include "GenVecPop.h"

namespace GenVec
{

GenVecPop::GenVecPop(int generationRate, float mutationRate, mt19937& gen)
	:Population(generationRate, mutationRate, gen)
{
}

GenVecPop::~GenVecPop(void)
{
}

void GenVecPop::calcFitness()
{
	//TODO make cuda enabled fitness function
}

}