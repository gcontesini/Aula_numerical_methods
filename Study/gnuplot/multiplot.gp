set terminal postscript                     # set terminal to produce a '.eps' file

set output "abcd.eps"                       # save the plot outside gnuplot on a file named abcd

set multiplot                               # set trminal to plot on the same screen differents plots

f(x,y)= exp(-(x-3*y)**2)*sin(3*(22/7)*(x*y))# set the functions f(x)

set size 0.5,0.5                            # set the size of the main screen

set xrange[-6:6]                            # set the interval for x for each plot

set origin 0.5,0.0                          # give to gnuplot the coordenates where the first plot will be

splot f(x,-1)                               # 3D plot of f(x,-1) where -1 is y=-1

set origin 0.5,0.5                          # give to gnuplot the coordenates where the first plot will be

splot f(x,0)                                # 3D plot of f(x,-1) where -1 is y=-1

set origin 0.0,0.5                          # give to gnuplot the coordenates where the first plot will be

splot f(x,1)                                # 3D plot of f(x,-1) where -1 is y=-1

!epstopdf "abcd.eps" && rm "abcd.eps"       # convert a .eps file to .pdf file

unset multiplot                             # unset multiplot 

reset                                       # reset all previously sets
