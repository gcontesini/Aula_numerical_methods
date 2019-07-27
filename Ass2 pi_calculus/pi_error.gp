reset
set terminal postscript color enhanced 
set output "ErrorofMadhavaalgorithm.eps"
set size 1,1
set origin 0,0
set multiplot
set title 'Error of Madhava algorithm'
set xlabel 'iterations'
set ylabel 'Error'
set xrange [0:50]
plot 'pi_error.txt' u 1:3 w l title 'Double Precision',\
     'pi_error.txt' u 1:2 w l title 'Single Precision'
unset key
unset xlabel
unset ylabel
unset title
set xrange [10:15]
set origin 0.50,0.1
set size 0.45,0.45
replot

!epstopdf "ErrorofMadhavaalgorithm.eps" && rm "ErrorofMadhavaalgorithm.eps"
reset
