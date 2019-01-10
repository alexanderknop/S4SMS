set size 0.9, 0.9
set key center above
set xlabel "number of runs"
set ylabel "normalized merge cost"
set key above width -8 vertical maxrows 4

set xrange [10:5000]
set yrange [0.99:1.07]

set terminal png
set output "plot.png"
plot "sparse_2_merge_sort_uniform_1_100_100.dat" using 1:2 title '2-stack sort' with lines,\
"sparse_2_stack_sort_uniform_1_100_100.dat" using 1:2 title '2-merge sort' with lines,\
"sparse_shivers_sort_uniform_1_100_100.dat" using 1:2 title 'Shivers sort' with lines,\
"sparse_adaptive_shivers_sort_uniform_1_100_100.dat" using 1:2 title 'adaptive Shivers sort' with lines
