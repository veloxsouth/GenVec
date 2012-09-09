#include "Polygon.h"

namespace GenVec
{

Polygon::Polygon(mt19937& gen)
	: m_gen(gen), 
	m_distSelect(0.0, 1.0), m_distValPlacement(-1, 1),
	m_distValColorIntensity(0, 255)
{
}

Polygon::~Polygon(void)
{
}

Polygon::Polygon(const Polygon& val)
	:m_gen(val.m_gen)
{
	*this = val;
}

Polygon& Polygon::operator=(const Polygon& val)
{

	//vertices and color
	setPoints(val.m_points, val.m_colors);

	return *this;
}

void Polygon::mutate(float mutRate)
{
	vector<float>::iterator iter;
	bool firstMutationDone = false;

	//mutate polygon points
	for (iter = m_points.begin(); iter != m_points.end(); iter++)
	{
		if (m_distSelect(m_gen) <= mutRate)
		{
			firstMutationDone = true;
			(*iter) = m_distValPlacement(m_gen);
		}
	}

	vector<unsigned char>::iterator colorIter;
	for (colorIter = m_colors.begin(); colorIter != m_colors.end(); colorIter++)
	{
		if (m_distSelect(m_gen) <= mutRate)
		{
			firstMutationDone = true;
			*colorIter = m_distValColorIntensity(m_gen);
		}
	}

	uniform_int_distribution<int> distSelectPoint(0, m_points.size() - 1);
	/* //TODO works. but temporarily commenting this to make it far easier to draw
	//only using triangles because all triangles are convex and can't self-intersect

	const float newPointRate = 0.2f;
	const float removePointRate = 0.2f;
	if (m_distSelect(*m_gen) <= newPointRate)
	{
		//make a random color
		unsigned char tempColors[4];
		for (int i = 0; i < 4; i++)
			tempColors[i] = m_distValColorIntensity(*m_gen);
		addPoint(m_distValWidth(*m_gen), m_distValHeight(*m_gen),
			tempColors, distSelectPoint(*m_gen));
	}

	if (m_distSelect(*m_gen) <= removePointRate)
	{
		removePoint(distSelectPoint(*m_gen));
	}
	*/
	if (!firstMutationDone)
	{
		m_points[distSelectPoint(m_gen)] = m_distValPlacement(m_gen);
		m_points[distSelectPoint(m_gen)] = m_distValPlacement(m_gen);
	}
}

void Polygon::addPoint(float x, float y, unsigned char colors[4], int index)
{

	if (index == -1)
	{
		m_points.push_back(x);
		m_points.push_back(y);
		m_colors.push_back(colors[0]);
		m_colors.push_back(colors[1]);
		m_colors.push_back(colors[2]);
		m_colors.push_back(colors[3]);
	}
	else
	{
		//vec2 for vertices, and vec4 for colors
		m_points.insert(m_points.begin() + 2 * index, y);
		m_points.insert(m_points.begin() + 2 * index, x);
		m_colors.insert(m_colors.begin() + 4 * index, colors[3]);
		m_colors.insert(m_colors.begin() + 4 * index, colors[2]);
		m_colors.insert(m_colors.begin() + 4 * index, colors[1]);
		m_colors.insert(m_colors.begin() + 4 * index, colors[0]);
	}
}

void Polygon::removePoint(int index)
{
	vector<float>::iterator iter = m_points.begin();
	m_points.erase(iter + 2 * index);
	m_points.erase(iter + 2 * index);
	vector<unsigned char>::iterator colorIter = m_colors.begin();
	m_colors.erase(colorIter + 4 * index);
	m_colors.erase(colorIter + 4 * index);
	m_colors.erase(colorIter + 4 * index);
	m_colors.erase(colorIter + 4 * index);
}

void Polygon::setPoints(const vector<float>& points, const vector<unsigned char>& colors)
{
	m_points.resize(points.size());
	unsigned int i;
	for (i = 0; i < points.size(); i++)
	{
		m_points[i] = points[i];
	}

	m_colors.resize(colors.size());
	for (i = 0; i < colors.size(); i++)
	{
		m_colors[i] = colors[i];
	}
}

void Polygon::addRandomPoint()
{
	float x, y;
	unsigned char colors[4];

	uniform_int_distribution<unsigned char> intDist(0, 255);
	uniform_real_distribution<float> floatDist(-1.0f, 1.0f);
	x = floatDist(m_gen);
	y = floatDist(m_gen);
	colors[0] = intDist(m_gen);
	colors[1] = intDist(m_gen);
	colors[2] = intDist(m_gen);
	colors[3] = intDist(m_gen);

	addPoint(x, y, colors);
}
}