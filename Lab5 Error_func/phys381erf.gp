reset
set terminal png size 1500,750
set output "Plot1a.png"
set autoscale
set title 'x vs erf(x)'
set xlabel 'x'
set ylabel "erf(x)"
set xrange[-0.1:0.1]
plot "erfout.data" u 1:2 with l notitle
reset

