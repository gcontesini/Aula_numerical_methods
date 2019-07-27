reset
set terminal gif animate delay 9
set output "animationgrid.gif"
set palette maxcolor 2
unset colorbox
set xrange[0:20]
set yrange[0:20]
set palette defined (0 'black', 1 'red')
m
plot 'savedgrid.txt' index 0 matrix with image notitle, \
     'savedgrid.txt' index 1 matrix with image notitle, \
     'savedgrid.txt' index 2 matrix with image notitle, \
     'savedgrid.txt' index 3 matrix with image notitle, \
     'savedgrid.txt' index 4 matrix with image notitle, \
     'savedgrid.txt' index 5 matrix with image notitle

