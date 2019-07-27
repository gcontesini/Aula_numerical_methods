reset                                     # erase all previously commands
set terminal gif animate delay 4          # delay on the animation
set output "animation.gif"                # name of the output
n=24                                      # nº frame
dt=2*pi/n                                 # interval of time
set xrange[0:4*pi]                        # define the limit of x
set yrange[-1:1]                          # define the limit of y
print pi                                  # pi
do for [i=0:n]                            # loop beginning on zero to n
  {
  splot sin(x+i*dt)/(1.+i/12.) lc 25 lw 2 # 3D plot a function 'l'ine'c'olor 25 'l'ine'w'idth 2
  }
