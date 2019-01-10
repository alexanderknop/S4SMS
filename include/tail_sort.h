#include <vector>
#include "sorting_algorithm.h"

#ifndef _TAIL_SORT_H_
#define _TAIL_SORT_H_

class run {
private:
	std::vector<int>* m_stack;
	int m_position;
public:
	run(std::vector<int>* stack, int position);
	double operator*();


	friend void merge(run x, run y);
};


class tail_sort : public sorting_algorithm {
public:
	virtual double operator()(std::vector<int>) = 0;
};

void merge(run x, run y);

#endif
