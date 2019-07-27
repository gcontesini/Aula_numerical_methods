reset
set terminal png size 1700,1500
set output "Plota.png"
set size 0.5,0.5
set origin 0,0
set multiplot
set autoscale
plot 'erfout.data' u 1:($3-$2) with l notitle
unset key
unset xlabel
unset ylabel
unset title
set xrange [4:8]
set origin 0.15,0.15
set size 0.45,0.45
replot

