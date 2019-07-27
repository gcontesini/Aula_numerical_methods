reset
set terminal png size 900,1000 enhanced
set output 'contesini-figure1.png'
set multiplot
set cbrange[0:0.5]
unset colorbox
set palette maxcolor 2

set xrange[-1:20]
set yrange[-1:20]
set palette defined( 0 'black', 1 'red' )
set size 0.5,0.3333

set origin 0.5 , 0.6666
set title 'p_trans = 0.0'
plot 'savedgrid.txt' index 0 matrix with image notitle

set origin 0.5 , 0.3333
set title 'p_trans = 0.2'
plot 'savedgrid.txt' index 1 matrix with image notitle

set origin 0.5 , 0.0
set title 'p_trans = 0.4'
plot 'savedgrid.txt' index 2 matrix with image notitle

set origin 0.0, 0.0
set title 'p_trans = 0.6'
plot 'savedgrid.txt' index 3 matrix with image notitle

set origin 0.0, .3333
set title 'p_trans = 0.8'
plot 'savedgrid.txt' index 4 matrix with image notitle

set origin 0.0, .6666
set title 'p_trans = 1.0'
plot 'savedgrid.txt' index 5 matrix with image notitle

reset
