reset

set terminal png
set output 'contesini-figure2.png'

set title 'Phase transition vs. Result'
set xlabel 'Result'
set ylabel 'Phase Transition'
plot 'transitiondata.txt' index 0 u 3:2 w l notitle,'transitiondata.txt' index 1 u 3:2 w l notitle,'transitiondata.txt' index 2 u 3:2 w l notitle,'transitiondata.txt' index 3 u 3:2 w l notitle

reset
