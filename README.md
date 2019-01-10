# S4SMS
Source files for the simulations from "Strategies for Stable Merge Sorting" of Sam Buss and Alexander Knop

In the directory example one may find the generated merge-costs with the run
length uniformly random from 1 to 100. To regenerate
"2_merge_sort_uniform_1_100_100.dat" you need to run
``../simulate 100 5000 uniform 1 100 alpha_merge_sort 2 100 >> 2_merge_sort_uniform_1_100_100.dat``
After that you need to sparse the file using sparse.py by running
``python sparsify.py 2_merge_sort_uniform_1_100_10.dat > sparse_2_merge_sort_uniform_
1_100_10.dat``. Similarly it is possible to generate the files for other sorting algorithms.

!["Uniform distribution form 1 to 100"](https://github.com/aaknop/S4SMS/raw/master/example/plot.png)
