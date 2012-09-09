#include "GenVecFactory.h"
#include "Image.h"
#include "PolygonGL.h"

namespace GenVec
{

GenVecFactory::GenVecFactory(int populationSize, int generationRate, float mutationRate, mt19937& gen, int polyCount)
	:m_populationSize(populationSize), m_generationRate(generationRate), m_mutationRate(mutationRate), m_gen(gen), m_polyCount(polyCount), m_vertexCount(3)
{
}


GenVecFactory::~GenVecFactory(void)
{
}

GenVecPop* GenVecFactory::operator()(GLuint positionAttrib, GLuint colorAttrib)
{
	GenVecPop* tempPop;
	Image* tempImage;
	PolygonGL* tempPoly;
	
	int i, j, k;
	tempPop = new GenVecPop(m_generationRate, m_mutationRate, m_gen);
	for (i = 0; i < m_populationSize; i++)
	{
		tempImage = new Image(m_gen);
		for (j = 0; j < m_polyCount; j++)
		{
			tempPoly = new PolygonGL(m_gen, positionAttrib, colorAttrib);
			for (k = 0; k < m_vertexCount; k++)
			{
				tempPoly->addRandomPoint();
			}
			tempImage->addPhenotype(tempPoly);
		}
		tempPop->addIndividual(tempImage);
	}
	return tempPop;
}
}