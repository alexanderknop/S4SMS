#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>
#include <cmath>
#include <cstring>
#include <algorithm>

#include "sorting_algorithm.h"
#include "alpha_stack_sort.h"
#include "alpha_merge_sort.h"
#include "timsort.h"
#include "shivers_sort.h"
#include "augmented_shivers_sort.h"
#include "adaptive_shivers_sort.h"
#include "power_sort.h"
#include "von_neumann_sort.h"
#include "random_generator.h"
#include "compose_generator.h"
#include "uniform_generator.h"
#include "power_generator.h"



using namespace std;

vector<int> generate_by_runs(int n, random_generator* generator) {
	vector<int> result;

	for(int  i = 0; i < n; i++) {
		int val = generator -> generate();
		result.push_back(val);
	}

	return result;
}

vector<int> generate_by_length(int n, int m) {
	vector<int> result;

	vector<int> positions;

	uniform_generator generator(0, n);

	for(int i = 0; i < m; i++) {
		positions.push_back(generator.generate());
	}
	positions.push_back(n);
	sort(positions.begin(), positions.end());


	int previous = -1;
	for(int  i = 0; i <= m; i++) {
		if (previous == positions[i]) {
			positions[i]++;
		}
		result.push_back(positions[i] - previous);
		previous = positions[i];
	}

	return result;
}

int parse_distribution(int pos, int argc, char** argv,
		random_generator** generator) {
	int min;
	int max;

	if (strcmp(argv[pos], "uniform") == 0) {
		if(argc < pos + 2) {
			cerr << "Missed parameter: min.\n";
			return 1;
		}
		min = atoi(argv[pos + 1]);
		if(argc < pos + 3) {
			cerr << "Missed parameter: max.\n";
			return 1;
		}
		max = atoi(argv[pos + 2]);

		*generator = new uniform_generator(min, max);
		return pos + 3;
	} else if (strcmp(argv[pos], "power") == 0) {
		if(argc < pos + 2) {
			cerr << "Missed parameter: min.\n";
			return 1;
		}
		min = atoi(argv[pos + 1]);
		if(argc < pos + 3) {
			cerr << "Missed parameter: max.\n";
			return 1;
		}
		max = atoi(argv[pos + 2]);

		if(argc < pos + 4) {
			cerr << "Missed parameter: power.\n";
			return 1;
		}
		double power = atof(argv[pos + 3]);
		*generator = new power_generator(min, max, power);
		return pos + 4;
	} else if (strcmp(argv[pos], "compose") == 0) {
		if(argc < pos + 2) {
		}
		double coef = atof(argv[pos + 1]);

		random_generator* left_generator;
		random_generator* right_generator;
		pos = parse_distribution(pos + 2, argc, argv, &left_generator);
		pos = parse_distribution(pos, argc, argv, &right_generator);

		*generator = new compose_generator(coef, left_generator, right_generator);
 		return pos;
	} else {
		cerr << "Unknown random generator " << argv[pos] << ".\n";
		exit(1);
	}
}

int main(int argc, char** argv) {
	int params = 0;
	if(argc < 2) {
		cerr << "Missing parameters.\n";
		cerr << "simulate FROM TO DISTRIBUTION SORTING_ALGORITHM NUMBER_OF_ITERATIONS\n";
		cerr << "DISTRIBUTION: \n";
		cerr << "              uniform MIN MAX\n";
		cerr << "              power MIN MAX POWER\n";
		cerr << "              compose RATIO DISTRIBUTION DISTRIBUTION\n";

		cerr << "SORTING_ALGORITHM: \n";
		cerr << "          alpha_stack_sort ALPHA\n";
		cerr << "          alpha_merge_sort ALPHA\n";
		cerr << "          timsort\n";
		cerr << "          shivers_sort\n";
		cerr << "          adaprive_shivers_sort\n";
		cerr << "          augmented_shivers_sort\n";
        cerr << "          power_sort\n";


		return 1;
	} else {
		int from = atoi(argv[1]);
		int to = atoi(argv[2]);

		random_generator* generator;
		params = parse_distribution(3, argc, argv, &generator) - 1;
		sorting_algorithm* algorithm;

		if(argc < params + 1) {
			cerr << "Missed parameter: SORTING_ALGORITHM.\n";
			return 1;
		}


		if(strcmp(argv[params + 1], "alpha_stack_sort") == 0) {
			if(argc < params + 2) {
				cerr << "Missed parameter: ALPHA.\n";
				return 1;
			}

			double alpha = atof(argv[params + 2]);

			algorithm = new alpha_stack_sort(alpha);

			params += 1;
		} else if(strcmp(argv[params + 1], "alpha_merge_sort") == 0) {
			if(argc < params + 2) {
				cerr << "Missed parameter: ALPHA.\n";
				return 1;
			}

			double alpha = atof(argv[params + 2]);

			algorithm = new alpha_merge_sort(alpha);

			params += 1;
		} else if(strcmp(argv[params + 1], "timsort") == 0) {
			algorithm = new timsort();
		} else if(strcmp(argv[params + 1], "shivers_sort") == 0) {
			algorithm = new shivers_sort();
		} else if(strcmp(argv[params + 1], "adaptive_shivers_sort") == 0) {
			algorithm = new adaptive_shivers_sort();
		} else if(strcmp(argv[params + 1], "augmented_shivers_sort") == 0) {
			algorithm = new augmented_shivers_sort();
        } else if(strcmp(argv[params + 1], "power_sort") == 0) {
			algorithm = new power_sort();
        } else if(strcmp(argv[params + 1], "von_neumann_sort") == 0) {
			algorithm = new von_neumann_sort();
		} else {
			cerr << "Unknown algorithm.\n";
			return 1;
		}
		params += 1;

		int number_of_iteration = atoi(argv[params + 1]);
		for (int length = from; length < to; length++) {
			double result = 0;
			for(int iter = 0; iter < number_of_iteration; iter++) {
				vector<int> array = generate_by_runs(length, generator);

				double sum = 0;
				for(int i = 0; i < array.size(); i++) {
					sum += array[i];
				}

				result += (*algorithm)(array) / (sum * log2(length)) / number_of_iteration;
			}

			cout << length << " " << result << "\n";

		}
	}
	return 0;
}
