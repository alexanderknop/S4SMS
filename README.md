# S4SMS
Source files for the experiments from "Strategies for Stable Merge Sorting" of
Sam Buss and Alexander Knop.

The test sequences use the following model. Since only merge costs were
measured, the inputs to the sorts are sequences of run lengths (not arrays to
be sorted).  Let $\mu$ be a distribution over integers. A sequence of $m$ run
lengths is chosen by choosing each of the $m$ lengths independently according
to the distribution $\mu$. We consider two types of distributions:

- The uniform distribution over numbers between $1$ and $100$,
- The power low distribution over numbers between $1$ and $100$ with the
    exponent $0.5$,
- A mixture of the uniform distribution over integers between $1$ and
    $100$ and the uniform distribution over integers between $10000$ and
    $100000$, with mixture weights $0.95$ and $0.05$. This distribution was
    specially tailored to work better with $3$-aware algorithms while still
    being formulated in a general way that avoids favoring any
    particular algorithm.

In the directory example one may find the generated merge-costs with the run
lengths according to these distributions.
To regenerate "YOUR_SORT_distribution_1_100_100.dat" you need to run
``./simulate 100 5000 DISTRIBUTION YOUR_SORT 100 >> DISTRIBUTION/YOUR_SORT.dat``
After that you need to sparse the file using sparse.py by running
``python sparsify.py DISTRIBUTION/YOUR_SORT.dat > DISTRIBUTION/sparse_YOUR_SORT.dat``. Finally, you may regenerate the plots using the command
``gnuplot plot.gp``.

!["Uniform distribution form 1 to 100"](https://github.com/aaknop/S4SMS/raw/master/example/uniform.png)
