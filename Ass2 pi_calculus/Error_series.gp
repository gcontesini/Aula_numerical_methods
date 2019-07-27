reset
set terminal postscript color enhanced 
set output"Error_propagation.eps"

f(x,y)=((2*a*x/y))**(1/(x+0.5))
a=1
set title 'Error Propagation'
set xlabel 'Beta'
set ylabel 'E_m(Machine precision)'
set zlabel 'N'
set xrange[1:10]
set yrange[10.e-12:10e-7]
set logscale y

set size 1,1
set origin 0,0
set multiplot


splot f(x,y) linecolor rgb "blue" notitle

unset key
unset xlabel
unset ylabel
unset title
set xrange[-2:2]
set yrange[1e-11:1e-9]
set origin 0.5,0.5
set size 0.45,0.45
replot 

!epstopdf "Error_propagation.eps" && rm "Error_propagation.eps"
reset
