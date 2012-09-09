#pragma once
#include "GeneratedForm.h"
#include "ImagePanel.h"
#include "MyOpenGLCanvas.h"
using namespace GenVec;

class CustomForm :
	public GeneratedForm
{
public:
	CustomForm();
	virtual ~CustomForm(void);
protected:
	MyOpenGLCanvas* myCanvas;
	ImagePanel* myPanel;
};

