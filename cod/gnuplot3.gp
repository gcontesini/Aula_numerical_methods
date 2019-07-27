set terminal postscript
set output "c.eps"
f(x,y) = exp(-(x-3*y)**2)*sin(3*3.14*(x*y))
set xrange[-6:6]
set yrange[-1:1]
splot f(x,y)
!epstopdf "c.eps" && rm "c.eps"

