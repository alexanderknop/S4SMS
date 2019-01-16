# S4SMS
Source files for the simulations from "Strategies for Stable Merge Sorting" of
Sam Buss and Alexander Knop

In the directory example one may find the generated merge-costs with the run
length uniformly random from 1 to 100. To regenerate
"YOUR_SORT_uniform_1_100_100.dat" you need to run
``./simulate 100 5000 uniform 1 100 YOUR_SORT 100 >> YOUR_SORT_uniform_1_100_100.dat``
After that you need to sparse the file using sparse.py by running
``python sparsify.py YOUR_SORT_uniform_1_100_100.dat > sparse_YOUR_SORT_uniform_
1_100_100.dat``. Finally, you may regenerate the plot using the command
``gnuplot plot.gp``.

!["Uniform distribution form 1 to 100"](https://github.com/aaknop/S4SMS/raw/master/example/uniform.png)
