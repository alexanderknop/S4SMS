#include <cstdlib>
#include <ctime>
#include <iostream>
#include "uniform_generator.h"

using namespace std;

uniform_generator::uniform_generator(int min, int max) : m_min(min), m_max(max) {
	srand(time(NULL));
	rand();
}

int uniform_generator::generate() {
	return (int) (((double)rand() * (double)(m_max - m_min)) / RAND_MAX) + m_min;
}

