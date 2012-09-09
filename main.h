#include <wx/wx.h>
#include <random>
#include "GenVecFactory.h"
using namespace std;
using namespace GenVec;

class MainApp : public wxApp
{
public:
	MainApp();
	~MainApp();
	bool OnInit();
	//mt19937 m_gen;
	//GenVecFactory m_fac;
	//GenVecPop* m_pop;

};
