#include "Individual.h"


namespace GenVec
{

Individual::Individual(mt19937& gen)
	:m_gen(gen)
{
}

Individual::~Individual(void)
{
	list<Phenotype*>::iterator iter;
	for (iter = m_phenos.begin(); iter != m_phenos.end(); iter++)
	{
		delete *iter;
	}
}

Individual::Individual(const Individual& val)
	:m_gen(val.m_gen)
{
	list<Phenotype*>::const_iterator iter;
	
	for (iter = val.m_phenos.begin(); iter != val.m_phenos.end(); iter++)
	{
		addPhenotype(*iter);
	}
}

Individual* Individual::copy()
{
	return new Individual(*this);
}

void Individual::addPhenotype(Phenotype* pheno)
{
	m_phenos.push_back(pheno);
}

void Individual::removePhenotype()
{
	uniform_int_distribution<int> distSelect(0, m_phenos.size() -1);
	removePhenotype(distSelect(m_gen));
}

void Individual::removePhenotype(int index)
{
	if ((unsigned)index >= m_phenos.size() || index < 0)
	{
		delete m_phenos.back();
		m_phenos.pop_back();
	}
	else
	{
		//TODO make it less naive and start iterating from the closer end
		//not currently taking advantage of double linkage
		list<Phenotype*>::iterator iter;
		int i;
		for (i = 0; i < index; i++)
		{
			iter++;
		}
		delete *iter;
		m_phenos.erase(iter);
	}
}

void Individual::mutate(float mutRate)
{
	list<Phenotype*>::iterator iter;
	for (iter = m_phenos.begin(); iter != m_phenos.end(); iter++)
	{
		(*iter)->mutate(mutRate);
	}
}

void Individual::express()
{
	list<Phenotype*>::iterator iter;
	for (iter = m_phenos.begin(); iter != m_phenos.end(); iter++)
	{
		(*iter)->express();
	}
}

}