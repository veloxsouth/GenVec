#include "MyOpenGLCanvas.h"
#include <vector>
#include <GL\GLU.h>

using namespace std;
using namespace GenVec;

MyOpenGLCanvas::MyOpenGLCanvas(wxWindow* parent)
	:wxGLCanvas(parent, wxID_ANY, NULL, wxDefaultPosition, wxSize(400, 400)), m_isInit(false),
	m_gen(2049), m_fac(3, 2, 0.0001f, m_gen, 3)
{
	m_myContext = new wxGLContext(this);
	
	Bind(wxEVT_PAINT, &MyOpenGLCanvas::OnPaint, this, wxID_ANY);

	//first the canvas must be shown
	//then the context must be current
	//then glew can init
	//then gl calls can occur
	//this order must not be changed as each depends on the previous!
}


MyOpenGLCanvas::~MyOpenGLCanvas(void)
{
	//Destroy Shaders
	if (m_isInit)
	{
		glUseProgram(0);
		glDetachShader(m_programId, m_vertexShaderId);
		glDetachShader(m_programId, m_fragmentShaderId);
		glDeleteShader(m_fragmentShaderId);
		glDeleteShader(m_vertexShaderId);
		glDeleteProgram(m_programId);
		delete m_myContext;
		//delete m_genVecPop;
	}
}

void MyOpenGLCanvas::OnPaint(wxPaintEvent& evt)
{
	if (!m_isInit)
	{
		init();
	}
	render();
}

void MyOpenGLCanvas::init()
{
	//no GLEW or GL calls can happen until it's actually current
	//can't be current until window is shown
	m_myContext->SetCurrent(*this);

	GLenum res = glewInit();
	const GLubyte* string;
	if (res != GLEW_OK) {
		string = glewGetErrorString(res);
	}

	//const GLubyte* glVers= glGetString(GL_VERSION);
	//const GLubyte* glslVers = glGetString(GL_SHADING_LANGUAGE_VERSION);
	glClearColor(1.0, 0, 0, 0.0);

	const GLchar* VertexShader =
	{
		"#version 420\n"\
 
		"in vec4 in_Position;\n"\
		"in vec4 in_Color;\n"\
		"out vec4 ex_Color;\n"\

		"void main(void)\n"\
		"{\n"\
		"   gl_Position = in_Position;\n"\
		"   ex_Color = in_Color;\n"\
		"}\n"
	};

	const GLchar* FragmentShader =
	{
		"#version 420\n"\
 
		"in vec4 ex_Color;\n"\
 
		"void main(void)\n"\
		"{\n"\
		"   gl_FragColor = ex_Color;\n"\
		"}\n"
	};
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//create shaders
	//vertex shader
	m_vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(m_vertexShaderId, 1, &VertexShader, NULL);
	glCompileShader(m_vertexShaderId);

	//fragment shader
	m_fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(m_fragmentShaderId, 1, &FragmentShader, NULL);
	glCompileShader(m_fragmentShaderId);

	m_programId = glCreateProgram();
	glAttachShader(m_programId, m_vertexShaderId);
	glAttachShader(m_programId, m_fragmentShaderId);
	glLinkProgram(m_programId);
	glUseProgram(m_programId);

	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	m_pop = m_fac(glGetAttribLocation(m_programId, "in_Position"), glGetAttribLocation(m_programId, "in_Color"));
	m_isInit = true;
	
}

void MyOpenGLCanvas::render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	m_pop->generate();
	m_pop->express();
	glFlush();
	SwapBuffers();
}