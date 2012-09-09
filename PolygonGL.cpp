#include "PolygonGL.h"

namespace GenVec
{

PolygonGL::PolygonGL(mt19937& gen, GLuint position, GLuint color)
	:Polygon(gen)
{
	glGenBuffers(1, &m_VboId);
	m_inPosition = position;
	m_inColor = color;
}

PolygonGL::~PolygonGL(void)
{
	glDeleteBuffers(1, &m_VboId);
}

PolygonGL::PolygonGL(PolygonGL& val)
	:Polygon(val)
{
	//intentionally blank
}

Polygon* PolygonGL::copy()
{
	return new PolygonGL(*this);
}

void PolygonGL::express()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VboId);
	glBufferData(GL_ARRAY_BUFFER, 
		sizeof(int) * m_points.size() + sizeof(unsigned char) * m_colors.size(),
		0, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(m_inPosition, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glVertexAttribPointer(m_inColor, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, (void*)( sizeof(float) * m_points.size()));
	
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * m_points.size(), &m_points[0]);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(float) * m_points.size(),
		sizeof(unsigned char) * m_colors.size(), &m_colors[0]);
	
	glEnableVertexAttribArray(m_inPosition);
	glEnableVertexAttribArray(m_inColor);

	//TODO eventually make it GL_POLYGON
	glDrawArrays(GL_TRIANGLES, 0, m_points.size());

	//cleanup
	glDisableVertexAttribArray(m_inPosition);
	glDisableVertexAttribArray(m_inColor);

}

}