#include <cstdlib>
#include <ctime>
#include <iostream>
#include "compose_generator.h"

using namespace std;

compose_generator::compose_generator(double coeff, random_generator* left_generator, random_generator* right_generator) : 
	m_coeff(coeff), m_left_generator(left_generator), m_right_generator(right_generator) {
}

int compose_generator::generate() {
	if((double) rand() / RAND_MAX < m_coeff) {
		return m_left_generator -> generate();
	} else {
		return m_right_generator -> generate();
	}
}

