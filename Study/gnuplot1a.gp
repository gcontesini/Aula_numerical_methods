reset
set terminal png size 1200,600 enhanced
set output "1a.png"
set multiplot
set size 0.5,0.5
set autoscale

set origin 0.0,0.0
set title "Temperature Anomaly versus year"
set xlabel"Temperature Anomaly (ºC)"
set ylabel"Year"
plot "table1.dat" u 3:1 w p notitle lc rgb '#FF0000' pt 9

set origin 0.0,0.5
set title 'CO2 concentration(in ppm) versus year'
set xlabel"CO2 concentration(ppm)"
set ylabel"Year"
plot "table1.dat" u 2:1 w p notitle lc rgb '#0000FF' pt 11

set origin 0.5,0.0
set title "Temperature Anomaly versus CO2 concentration "
set xlabel"Temperature Anomaly (ºC)"
set ylabel"CO2 concentration (ppm)"
plot "table1.dat" u 3:2 w p notitle lc rgb '#000000' pt 13

reset
