set size 0.9, 0.9
set key center above
set xlabel "number of runs"
set ylabel "normalized merge cost"
set key above width -8 vertical maxrows 4

set terminal png size 1024,768
set xrange [100:5000]
set output "von_neumann_uniform.png"
plot \
"uniform/sparse_von_neumann_sort.dat" using 1:2 title 'von Neumann sort' with lines,\
"uniform/sparse_adaptive_shivers_sort.dat" using 1:2 title 'Shivers sort' with lines

set terminal png size 1024,768
set output "von_neumann_mixed.png"
plot \
"mixed/sparse_von_neumann_sort.dat" using 1:2 title 'von Neumann sort' with lines

set xrange [100:8000]
set yrange [0.99:1.07]

set terminal png size 1024,768
set output "uniform.png"
plot \
"uniform/sparse_shivers_sort.dat" using 1:2 title 'Shivers sort' with lines,\
"uniform/sparse_adaptive_shivers_sort.dat" using 1:2 title 'adaptive Shivers sort' with lines,\
"uniform/sparse_power_sort.dat" using 1:2 title 'power sort' with lines,\
"uniform/sparse_2_merge_sort.dat" using 1:2 title '2-stack sort' with lines,\
"uniform/sparse_2_stack_sort.dat" using 1:2 title '2-merge sort' with lines

set output "power.png"
plot \
"power/sparse_shivers_sort.dat" using 1:2 title 'Shivers sort' with lines,\
"power/sparse_adaptive_shivers_sort.dat" using 1:2 title 'adaptive Shivers sort' with lines,\
"power/sparse_power_sort.dat" using 1:2 title 'power sort' with lines,\
"power/sparse_2_stack_sort.dat" using 1:2 title '2-stack sort' with lines,\
"power/sparse_2_merge_sort.dat" using 1:2 title '2-merge sort' with lines


set output "mixed.png"
set yrange [0.6:0.9]
plot \
"mixed/sparse_shivers_sort.dat" using 1:2 title 'Shivers sort' with lines,\
"mixed/sparse_adaptive_shivers_sort.dat" using 1:2 title 'adaptive Shivers sort' with lines,\
"mixed/sparse_power_sort.dat" using 1:2 title 'power sort' with lines,\
"mixed/sparse_2_stack_sort.dat" using 1:2 title '2-stack sort' with lines,\
"mixed/sparse_2_merge_sort.dat" using 1:2 title '2-merge sort' with lines
