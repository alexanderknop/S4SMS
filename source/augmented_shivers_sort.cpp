#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

#include "augmented_shivers_sort.h"

using namespace std;

augmented_shivers_sort::augmented_shivers_sort() {
}

double augmented_shivers_sort::operator()(vector<int> array) {
	double result = 0;
	vector<int> stack;
	run z(&stack, 0);
	run y(&stack, 1);
	run x(&stack, 2);

	for (int i = 0; i < array.size(); i++) {
		stack.push_back(array[i]);

		while(!isnan(*y) && pow(2, (int) log2(*y)) <= (*z)) {
			if((*x) < (*z)) {
				result += (*x) + (*y);
	   		    merge(x, y);
			} else {
				result += (*y) + (*z);
	   		    merge(y, z);
			}
		}
	}

	while(stack.size() > 1) {
		result += (*y) + (*z);
		merge(y, z);
	}

	return result;
}
