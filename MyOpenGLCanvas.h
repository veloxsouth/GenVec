#pragma once
#include <GL\glew.h>
#include <wx\glcanvas.h>
#include "GenVecFactory.h"
#include <random>

using namespace std;
using namespace GenVec;

class MyOpenGLCanvas : public wxGLCanvas
{
public:
	MyOpenGLCanvas(wxWindow* parent);
	virtual ~MyOpenGLCanvas(void);
	void OnPaint(wxPaintEvent& evt);
protected:
	void init();
	void render();
	bool m_isInit;
	wxGLContext* m_myContext;
	GLuint m_vertexShaderId;
	GLuint m_fragmentShaderId;
	GLuint m_programId;
	mt19937 m_gen;
	GenVecFactory m_fac;
	GenVecPop* m_pop;
};