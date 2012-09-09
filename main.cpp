#include <iostream>
#include <GL\glew.h>
#include "main.h"
#include "CustomForm.h"

IMPLEMENT_APP(MainApp)
	
MainApp::MainApp()
	//:m_gen(2333), m_fac(3, 2, 0.0001f, m_gen, 1)
{
}

MainApp::~MainApp()
{
	//delete m_pop;
}

bool MainApp::OnInit()
{
	////these are some stock shapes to test OpenGL rendering
	//GLfloat triangle[6];
	//GLfloat concave[8];
	//GLfloat complex[8];
	//
	////x then y
	//triangle[0] = -1;
	//triangle[1] = 0;
	//triangle[2] = 1;
	//triangle[3] = -1;
	//triangle[4] = 1;
	//triangle[5] = 1;

	//concave[0] = -1;
	//concave[1] = 0;
	//concave[2] = 1;
	//concave[3] = -1;
	//concave[4] = 0;
	//concave[5] = 0;
	//concave[6] = 1;
	//concave[7] = 1;
	//
	//self intersecting
	//complex[0] = -1;
	//complex[1] = 1;
	//complex[2] = 1;
	//complex[3] = -1;
	//complex[4] = -1;
	//complex[5] = -1;
	//complex[6] = 1;
	//complex[7] = 1;

	CustomForm* customForm = new CustomForm();
	customForm->Show();
	//m_pop = m_fac(0, 1);
	
	return true;
}