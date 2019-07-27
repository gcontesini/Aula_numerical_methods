reset
set terminal png size 1500,750
set output "Plot4a.png"
set autoscale
set title 'N vs new erfc(x)'
set xlabel 'N'
set ylabel "erfc(x)"
plot "erfout2.data" u 1:2 with l notitle
reset


