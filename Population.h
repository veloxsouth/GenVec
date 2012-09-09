#pragma once
#include "Individual.h"
#include <vector>

using namespace std;

namespace GenVec
{

class Population
{
public:
	Population(int generationRate, float mutationRate, mt19937& gen);
	virtual ~Population(void);
	virtual void addIndividual(Individual* individual);
	virtual void generate();
	virtual void express();
protected:
	virtual void calcFitness() =0;
	bool fitnessSortFun(const pair<Individual*, int>& a, const pair<Individual*, int>& b);
	int m_generationRate; //how many new individuals are made per generation
							//also determines how many of the least fit are deleted
	float m_mutationRate;
	mt19937& m_gen;
	vector<pair<Individual*, int> > m_individuals;
	//clone rate is determined by the population size and generation rate
};

class FitnessSort
{
public:
	bool operator()(const pair<Individual*, int>& a, const pair<Individual*, int>& b);
};
}