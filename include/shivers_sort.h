#include "tail_sort.h"

#ifndef _SHIVERS_SORT_H_
#define _SHIVERS_SORT_H_

class shivers_sort : public tail_sort {
public:
	shivers_sort();

	virtual double operator()(std::vector<int> array);
};

#endif
