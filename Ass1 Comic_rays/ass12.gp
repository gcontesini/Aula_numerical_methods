reset
set terminal gif
set output "fig2.pdf"
set multiplot

set palette maxcolors 2 
unset colorbox
set palette defined (0 'blue', 1 'red')

set size 0.5,0.5
set xrange[-1:20]
set yrange[-1:20]

set origin 0.0,0.0
plot 'data2.txt' matrix with image title'(i)'
set origin 0.5,0.0
plot 'data3.txt' matrix with image title'(ii)'
set origin 0.0,0.5
plot 'data4.txt' matrix with image title'(iii)'
set origin 0.5,0.5
plot 'data5.txt' matrix with image title'(iiii)'

!convert "fig2.gif" "fig2.pdf" && rm "fig2.gif"
unset multiplot
reset
