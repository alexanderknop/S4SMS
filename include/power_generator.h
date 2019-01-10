#include "random_generator.h"

#ifndef _POWER_GENERATOR_H_
#define _POWER_GENERATOR_H_

class power_generator : public random_generator {
private:
	int m_min;
	int m_max;
	int m_power;
public:
	power_generator(int, int, double);
	virtual int generate();
};

#endif
