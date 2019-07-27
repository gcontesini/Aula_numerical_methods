reset
set terminal gif animate delay 4
set output "phys381movie.gif"
n=24 #n frame
dt=2*pi/n
set xrange[0:4*pi]
set yrange[-1:1]
print pi
do for [i=0:n]{
splot sin(x+i*dt)/(1.+i/12.) lc 25 lw 2
}
