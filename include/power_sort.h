#include "tail_sort.h"

#ifndef _POWER_SORT_H_
#define _POWER_SORT_H_

class power_sort : public tail_sort {
private:
    double node_power(int s_1, int e_1, int s_2, int e_2, int n);
public:
	power_sort();

	virtual double operator()(std::vector<int> array);
};

#endif
