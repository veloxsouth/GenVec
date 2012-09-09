#include "Individual.h"
#include "PolygonGL.h"
#include <random>

using namespace std;

namespace GenVec
{

class Image : public Individual
{
public:
	//TODO make it so back ground is arbitrary color on construction
	Image(mt19937& gen);
	virtual ~Image();
	Image(const Image& val);
	virtual Individual* copy();
	virtual Image& operator=(const Image& rhs);
	virtual void express();
	virtual void mutate(float mutRate);
protected:
	unsigned char m_bgColor[4];
	uniform_real_distribution<float> m_distSelect;
	uniform_int_distribution<unsigned char> m_distBGColor;
	float m_changeBGRate;
};
}