#pragma once
#include "Phenotype.h"
#include <list>
#include <random>

using namespace std;

namespace GenVec
{

class Individual
{
public:
	Individual(mt19937& gen);
	virtual ~Individual(void);
	Individual(const Individual& val);
	virtual Individual* copy();
	virtual void addPhenotype(Phenotype* pheno);
	virtual void removePhenotype();
	virtual void removePhenotype(int index);
	virtual void mutate(float mutRate);
	virtual void express();
protected:
	mt19937& m_gen;
	list<Phenotype*> m_phenos;
};

}