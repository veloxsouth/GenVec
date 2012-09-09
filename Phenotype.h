#pragma once

namespace GenVec
{

class Phenotype
{
public:
	Phenotype(void);
	virtual ~Phenotype(void);
	virtual Phenotype* copy() =0;
	virtual void mutate(float mutRate) =0;
	virtual void express() =0;
};

}