#include <cstdlib>
#include <iostream>
#include <cmath>

#include "power_generator.h"

using namespace std;

power_generator::power_generator(int min, int max, double power) : 
	m_min(min), m_max(max), m_power(power) {

	srand(time(NULL));
	rand();
}

int power_generator::generate() {
	return (int) pow((1.0 * (pow(m_max, (m_power + 1)) - pow(m_min, (m_power + 1))) * 
				rand() / RAND_MAX + pow(m_min, (m_power + 1))), 1/ (m_power + 1));
}

