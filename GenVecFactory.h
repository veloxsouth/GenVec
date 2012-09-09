#pragma once
#include "GenVecPop.h"
#include <GL\glew.h>

namespace GenVec
{

class GenVecFactory
{
public:
	GenVecFactory(int populationSize, int generationRate, float mutationRate, mt19937& gen, int polyCount);
	virtual ~GenVecFactory(void);
	GenVecPop* operator()(GLuint positionAttrib, GLuint colorAttrib);
	int m_populationSize;
	int m_generationRate;
	float m_mutationRate;
	mt19937& m_gen;
	int m_polyCount;
	const int m_vertexCount;
	GLuint m_programId;
};

}