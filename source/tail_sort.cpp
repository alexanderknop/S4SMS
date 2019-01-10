#include <vector>
#include <limits>
#include <cmath>

#include "tail_sort.h"

using namespace std;

run::run(vector<int>* stack, int position) : m_stack(stack), m_position(position) {
}

double run::operator*() {
	if((int) m_stack->size() - m_position - 1 < 0) {
		return NAN;
	}
	return (*m_stack)[m_stack->size() - m_position - 1];
}

void merge(run x, run y) {
	if (x.m_stack != y.m_stack) {
		throw logic_error("Stacks of two merged runs should be the same");
	}
	if (x.m_position - y.m_position != 1) {
		throw logic_error("Runs should be consecutive");
	}

	int x_value = *x;
	int y_value = *y;

	(*x.m_stack)[x.m_stack->size() - x.m_position - 1] = x_value + y_value;
	y.m_stack->erase(y.m_stack->begin() + y.m_stack->size() - y.m_position - 1);
}
