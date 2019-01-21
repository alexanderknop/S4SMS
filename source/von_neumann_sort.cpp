#include <vector>
#include <stack>
#include <iostream>

#include "von_neumann_sort.h"

using namespace std;

von_neumann_sort::von_neumann_sort() {
}

double von_neumann_sort::operator()(vector<int> array) {
	double result = 0;
	vector<int> stack;
	run z(&stack, 0);
	run y(&stack, 1);

    int n = 0;
	for (int i = 0; i < array.size(); i++) {
        n += array[i];
	}

	for (int i = 0; i < n; i++) {
		stack.push_back(1);

		while((*y) <= 2 * (*z)) {
			result += (*y) + (*z);
			merge(y, z);
		}
	}

	while(stack.size() > 1) {
		result += (*y) + (*z);
		merge(y, z);
	}

	return result;
}
