#include "tail_sort.h"

#ifndef _TIMSORT_H_
#define _TIMSORT_H_

class timsort : public tail_sort {
public:
	timsort();

	virtual double operator()(std::vector<int> array);
};

#endif
