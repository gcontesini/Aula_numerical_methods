reset
set terminal postscript color enhanced 
set output"Hydrogen.eps" 
set multiplot 
set title 'R(r) and R(r) using the first two terms of its series expansion' 
set xlabel 'r' 
set ylabel 'R(r)' 
set xrange[0:20] 
set size 1,1
set origin 0,0

g(x)=(2.*x**2-18.*x+27.*exp(-x/3.)) 
f(x)=(2.*x**2-18.*x+27.*(1.-(x/3.)))
h(x)=(2.*x**2.-18.*x+27.*(1.-(x/3.)+(x**2./18.)-(x**3./162.)+(x**4./1944.)-(x**5./29160.)))

plot g(x) title "R(r)",\
     f(x) title "Series Expansion 2",\
     h(x) title "Series Expansion 6"

unset key
unset xlabel
unset ylabel
unset title
set xrange[0:5]
set origin 0.15,0.15
set size 0.6,0.45
replot 

!epstopdf "Hydrogen.eps" && rm "Hydrogen.eps"
reset

