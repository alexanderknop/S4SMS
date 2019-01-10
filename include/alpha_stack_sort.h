#include "tail_sort.h"

#ifndef _ALPHA_STACK_SORT_H_
#define _ALPHA_STACK_SORT_H_

class alpha_stack_sort : public tail_sort {
private:
	double m_alpha;
public:
	alpha_stack_sort(double alpha);

	virtual double operator()(std::vector<int> array);
};

#endif
