set terminal postscript
set output "b.eps"
set multiplot

f(x,y) = exp(-(x-3*y)**2)*sin(3*3.14*(x*y))

set size 0.5,0.5
set xrange[-6:6]

set origin 0.5 , 0.0
splot f(x,-1)
set origin 0.5 , 0.5
splot f(x,0)
set origin 0.0 , 0.5
splot f(x,1)

!epstopdf "b.eps" && rm "b.eps"
unset multiplot
reset