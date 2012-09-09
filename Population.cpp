#include "Population.h"
#include <algorithm>

namespace GenVec
{

Population::Population(int generationRate, float mutationRate, mt19937& gen)
	:m_generationRate(generationRate),
	m_mutationRate(mutationRate), m_gen(gen)
{

}

Population::~Population(void)
{
	vector<pair<Individual*, int> >::iterator iter;
	for (iter = m_individuals.begin(); iter != m_individuals.end(); iter++)
	{
		delete (*iter).first;
	}
}

void Population::addIndividual(Individual* individual)
{
	//arbitrarily chose 0. fitness should be calculated before generation anyway
	m_individuals.push_back(pair<Individual*, int>(individual, 0));
}

void Population::generate()
{
	//assumes that     population size > generation rate
	calcFitness();

	//leave only the best at the front. Don't bother sorting the individuals that are going to be wiped out
	partial_sort(m_individuals.begin(), m_individuals.begin() + (m_individuals.size() - m_generationRate),
		m_individuals.end(), FitnessSort());

	//randomly select who lives into the next generation based upon their fitness
	vector<int> intervals;
	vector<int> weights;

	//set intervals
	intervals.resize(m_individuals.size() + 1);
	unsigned int i;
	for (i = 0; i < intervals.size(); i++)
	{
		intervals[i] = i;
	}

	//set weights
	weights.resize(m_individuals.size());
	for (i = 0; i < weights.size(); i++)
	{
		weights[i] = m_individuals[i].second;
	}

	piecewise_constant_distribution<int> dist(intervals.begin(), intervals.end(), weights.begin());
	vector<pair<Individual*, int> >::reverse_iterator riter;

	//can't mutate in place because overwritten individuals may yet reproduce
	vector<Individual*> temp;
	temp.resize(m_generationRate);
	for (i = 0; (signed)i < m_generationRate; i++)
	{
		temp[i] = m_individuals[dist(m_gen)].first->copy();
		temp[i]->mutate(m_mutationRate);
	}

	//delete individuals that are about to be overwritten and move new ones in their place
	riter = m_individuals.rbegin();
	while ((signed)i < m_generationRate)
	{
		delete riter->first;
		riter->first = temp[i];

		i++;
		riter++;
	}
}

bool FitnessSort::operator()(const pair<Individual*, int>& a, const pair<Individual*, int>& b)
{
	return a.second < b.second;
}

void Population::express()
{
	unsigned int i;
	for (i = 0; i < m_individuals.size(); i++)
	{
		m_individuals[i].first->express();
	}
}
}