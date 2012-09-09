#pragma once
#include "phenotype.h"
#include <list>
#include <Windows.h>
#include <GL\glew.h>
#include <random>

using namespace std;

namespace GenVec
{

class Polygon : public Phenotype
{
public:
	Polygon(mt19937& gen);
	~Polygon(void);
	Polygon(const Polygon& val);
	Polygon& operator=(const Polygon& val);
	virtual Polygon* copy() =0;
	virtual void mutate(float mutRate);
	virtual void express() =0;
	void addPoint(float x, float y, unsigned char colors[4], int index = -1);
	void addRandomPoint();
	void removePoint(int index =-1);
	void setPoints(const vector<float>& points, const vector<unsigned char>& colors);
protected:
	//held in width major order
	vector<float> m_points; // ranges >>>> point count [3, 15],  point vals [0, boundingbox)
	vector<unsigned char> m_colors;
	mt19937& m_gen;
	uniform_real_distribution<float> m_distSelect;
	uniform_int_distribution<float> m_distValPlacement;
	uniform_real_distribution<unsigned char> m_distValColorIntensity;
};

}