#include "sorting_algorithm.h"
#include "tail_sort.h"

#ifndef _ALPHA_MERGE_SORT_H_
#define _ALPHA_MERGE_SORT_H_

class alpha_merge_sort : public tail_sort {
private:
	double m_alpha;
public:
	alpha_merge_sort(double alpha);

	virtual double operator()(std::vector<int> array);
};

#endif
