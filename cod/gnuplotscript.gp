set terminal postscript
set output "test.eps"
f(x,y)=exp(-(x-3*y)**2)*sin(3*3.14*(x*y))
splot f(x,0)
set xrange[-4:4]
!epstopdf "test.eps" && rm "test.eps"

