set terminal postscript                     # set terminal to create a eps figure
set output "test.eps"                       # save outside gnuplot on a file
f(x,y)=exp(-(x-3*y)**2)*sin(3*(22/7)*(x*y)) # define a functions named f(x)
set xrange[-4:4]                            # define the limit of x
splot f(x,y)                                # 3D plot of f(x)
!epstopdf "test.eps" && rm "test.eps"       # convert .eps files to .pdf
