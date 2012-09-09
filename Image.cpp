#include "Image.h"
#include <GL\glew.h>
namespace GenVec
{

	//TODO m_changeBGRate needs to be set aribtrarily via constructor
Image::Image(mt19937& gen)
	:Individual(gen), m_distSelect(0.0f, 1.0f), m_distBGColor(0, 255), m_changeBGRate(0.02f)
{
	m_bgColor[0] = 0;
	m_bgColor[1] = 0;
	m_bgColor[2] = 0;
	m_bgColor[3] = 255; //alpha
}

Image::~Image()
{
	//intentionally blank
}

Image::Image(const Image& val)
	:Individual(val.m_gen)
{
	*this = val;
}

Image& Image::operator=(const Image& rhs)
{
	m_changeBGRate = rhs.m_changeBGRate;
	//don't bother copying over m_gen because it's a reference and can't be reset
	unsigned int i;
	for (i = 0; i < 4; i++)
	{
		m_bgColor[i] = rhs.m_bgColor[i];
	}

	//copy over the phenos
	//delete all the ones you already have
	list<Phenotype*>::iterator iter;
	for (iter = m_phenos.begin(); iter != m_phenos.end(); iter++)
	{
		delete *iter;
	}

	//fill with copies
	m_phenos.clear();
	list<Phenotype*>::const_iterator rhsIter;
	for (rhsIter = rhs.m_phenos.begin(); rhsIter != rhs.m_phenos.end(); rhsIter++)
	{
		m_phenos.push_back((*iter)->copy());
	}
	return *this;
}

Individual* Image::copy()
{
	return new Image(*this);
}

void Image::express()
{
	glClearColor(m_bgColor[0], m_bgColor[1], m_bgColor[2], m_bgColor[3]);
	//glClear(GL_COLOR_BUFFER_BIT);

	list<Phenotype*>::iterator iter;
	for (iter = m_phenos.begin(); iter != m_phenos.end(); iter++)
	{
		(*iter)->express();
	}
}

void Image::mutate(float mutRate)
{
	//mutate bgColor by random chance
	if (m_distSelect(m_gen) <= m_changeBGRate)
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			m_bgColor[i] = m_distBGColor(m_gen);
		}
	}

	list<Phenotype*>::iterator iter;
	for (iter = m_phenos.begin(); iter != m_phenos.end(); iter++)
	{
		(*iter)->mutate(mutRate);
	}
}

}