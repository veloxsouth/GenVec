#pragma once
#include "Polygon.h"

namespace GenVec
{

class PolygonGL :
	public Polygon
{
public:
	PolygonGL(mt19937& gen, GLuint position, GLuint color);
	virtual ~PolygonGL(void);
	PolygonGL(PolygonGL& val);
	virtual Polygon* copy();
	virtual void express();
protected:
	GLuint m_VboId;
	GLuint m_inPosition;
	GLuint m_inColor;
};

}