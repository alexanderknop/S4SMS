#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

#include "adaptive_shivers_sort.h"

using namespace std;

adaptive_shivers_sort::adaptive_shivers_sort() {
}

double adaptive_shivers_sort::operator()(vector<int> array) {
	double result = 0;
	vector<int> stack;
	run z(&stack, 0);
	run y(&stack, 1);
	run x(&stack, 2);

	for (int i = 0; i < array.size(); i++) {
		stack.push_back(array[i]);

		while(1) {
			if (!isnan(*y) && !isnan(*x) && (int) log2(*z) >= (int) log2(*x)) {
				result += (*x) + (*y);
				merge(x, y);
			} else if (!isnan(*y) && !isnan(*x) && (int) log2(*y) >= (int) log2(*x)) {
				result += (*x) + (*y);
                                merge(x, y);
			} else if (!isnan(*y) && (int) log2(*z) >= (int) log2(*y)) {
				result += (*y) + (*z);
                                merge(y, z);
			} else {
				break;
			}
		}
	}

	while(stack.size() > 1) {
		result += (*y) + (*z);
		merge(y, z);		
	}

	return result;
}

