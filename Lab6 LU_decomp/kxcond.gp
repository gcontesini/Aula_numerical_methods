reset
set terminal postscript color enhanced 
set output "Condition_NumberxK.eps"

set title 'Condition Number(1) x K'
set xlabel 'K'
set ylabel 'Condition Number(1)'
set xrange[0:11]
set yrange[01:5]
set size 1,1
set origin 0,0
set multiplot

plot "plot.txt" u 1:2 w l linecolor rgb "black" notitle

unset key
unset xlabel
unset ylabel
unset title
set xrange[6.5:9]

set origin 0.1,0.1
set size 0.45,0.45
replot 

!epstopdf "Condition_NumberxK.eps" && rm "Condition_NumberxK.eps"
reset
