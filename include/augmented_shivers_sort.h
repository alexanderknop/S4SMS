#include "tail_sort.h"

#ifndef _AUGMENTED_SHIVERS_SORT_H_
#define _AUGMENTED_SHIVERS_SORT_H_

class augmented_shivers_sort : public tail_sort {
public:
	augmented_shivers_sort();

	virtual double operator()(std::vector<int> array);
};

#endif
