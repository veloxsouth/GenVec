#include "CustomForm.h"

CustomForm::CustomForm()
	:GeneratedForm(0)
{
	myPanel = new ImagePanel(m_panel1);
	myCanvas = new MyOpenGLCanvas(m_panel1);
	bSizer3->Add(myCanvas);
	bSizer3->Add(myPanel);
	bSizer3->Fit(m_panel1);
	this->Layout();
}

CustomForm::~CustomForm(void)
{
}