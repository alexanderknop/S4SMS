#include "random_generator.h"

#ifndef _COMPOSE_GENERATOR_H_
#define _COMPOSE_GENERATOR_H_

class compose_generator : public random_generator {
private:
	double m_coeff;
	random_generator* m_left_generator;
	random_generator* m_right_generator;
public:
	compose_generator(double, random_generator*, random_generator*);
	virtual int generate();
};

#endif
