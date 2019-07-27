set terminal postscript
set output "a.eps"
f(x,y)=exp(-(x-3*y)**2)*sin(3*3.14*(x*y))
set xrange[-4:4]
splot f(x,y)
!epstopdf "a.eps" && rm "a.eps"