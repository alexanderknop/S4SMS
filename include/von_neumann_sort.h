#include "tail_sort.h"

#ifndef _VON_NEUMANN_SORT_H_
#define _VON_NEUMANN_SORT_H_

class von_neumann_sort : public tail_sort {
public:
	von_neumann_sort();

	virtual double operator()(std::vector<int> array);
};

#endif
