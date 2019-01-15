#include <vector>
#include <stack>
#include <iostream>
#include <cmath>

#include "power_sort.h"

using namespace std;

power_sort::power_sort() {
}

double power_sort::node_power(int s_1, int e_1, int s_2, int e_2, int n) {
    double n_1 = e_1 - s_1 + 1;
    double n_2 = e_2 - s_2 + 1;

    double l = 0;

    double a = (s_1 + n_1 / 2 - 1) / n;
    double b = (s_2 + n_2 / 2 - 1) / n;

    while (((int) (a * pow(2, l))) == ((int) (b * pow(2, l)))) {
        l = l + 1;
    }

    return l;
}

double power_sort::operator()(vector<int> array) {
	double result = 0;

    vector<int> cstack;
	run z(&cstack, 0);
	run y(&cstack, 1);

    stack<double> pstack;

    int n = 0;
	for (int i = 0; i < array.size(); i++) {
        n += array[i];
	}


    int s_1 = 1;
    int e_1 = array[0];
    for (int i = 1; i < array.size(); i++) {
        cstack.push_back(array[i - 1]);

        int s_2 = e_1 + 1;
        int e_2 = e_1 + array[i];
        double p = node_power(s_1, e_1, s_2, e_2, n);
        while (pstack.size() > 0 && pstack.top() > p) {
            pstack.pop();

            result += (*y) + (*z);
            merge(y, z);

            s_1 = e_1 - (*z) + 1;
        }
        pstack.push(p);

        s_1 = s_2;
        e_1 = e_2;
	}
    cstack.push_back(array[array.size() - 1]);

	while(cstack.size() > 1) {
		result += (*y) + (*z);
		merge(y, z);
	}

	return result;
}
