reset
set terminal postscript color enhanced 
set output "Plot5.eps"
set size 1,1
set origin 0,0
set multiplot
set title 'N vs erfc(x)f90-new erfc(x)'
set xlabel 'N'
set ylabel "erfc(x)@f90 - new erfc(x)@f90"
set xrange [2:20]

plot 'erfout2.data' u 1:($3)-($2) with l title 'erfc(x)@f90 - new erfc(x)@f90'
replot "erfout2.data" u 1:3 with l title "erfc(x)f90"

unset key
unset xlabel
unset ylabel
unset title
set xrange [17:19]
set origin 0.50,0.1
set size 0.45,0.45
replot

