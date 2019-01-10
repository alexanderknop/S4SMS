#include <vector>
#include <stack>
#include <iostream>

#include "timsort.h"

using namespace std;

timsort::timsort() {
}

double timsort::operator()(vector<int> array) {
	double result = 0;

	vector<int> stack;

	run z(&stack, 0);
	run y(&stack, 1);
	run x(&stack, 2);
	run w(&stack, 3);


	for (int i = 0; i < array.size(); i++) {
		stack.push_back(array[i]);

		while(1) {
			if((*x) <= (*y) + (*z) || (*w) <= (*x) + (*y)) {
				if((*x) < (*z)) {
					result += (*x) + (*y);
					merge(x, y);
				} else {
   					result += (*y) + (*z);
					merge(y, z);
				}
			} else if((*y) <= (*z)) {
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

