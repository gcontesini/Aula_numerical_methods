set terminal postscript
set output
f(x,y)=exp(-(x-3*y)**2)*sin(3*(22/7)*(x*y))
set xrange[-4:4]
splot f(x,y)
!epstopdf "test.eps" && rm "test.eps"