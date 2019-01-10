#include "random_generator.h"

#ifndef _UNIFORM_GENERATOR_H_
#define _UNIFORM_GENERATOR_H_

class uniform_generator : public random_generator {
private:
	int m_min;
	int m_max;
public:
	uniform_generator(int, int);
	virtual int generate();
};

#endif
