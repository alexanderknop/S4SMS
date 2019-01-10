#include "tail_sort.h"

#ifndef _ADAPTIVE_SHIVERS_SORT_H_
#define _ADAPTIVE_SHIVERS_SORT_H_

class adaptive_shivers_sort : public tail_sort {
public:
	adaptive_shivers_sort();

	virtual double operator()(std::vector<int> array);
};

#endif
