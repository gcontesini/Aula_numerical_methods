reset

set xrange[-2.0:0.5]
set yrange[-1.2:1.2]

set key outside top right
set cntrparam levels auto 25
unset ztics
set key outside top right
unset surface
set isosamples 50
set view map

set contour
set ticslevel 0.8
unset colorbox


splot 'lab2.dat' u 1:2:3 w lines notitle palette

pause -1

