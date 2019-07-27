reset                                           #reset all previously
set terminal gif                                #set the terminal to plot in .gif format
set output "fig1.gif"                           #set the terminal to save the plot on a file named fig1.gif
set palette maxcolors 2                         #set the max nº of colors to be used
unset colorbox                                  #do not show the colorbox
set palette defined (0 'blue', 1 'red')         #set the palette as if 0 use blue if 1 use red
plot "data1.txt" matrix with image notitle      #plot from data1.txt a matrix format w noo title
!convert "fig1.gif" "fig1.pdf" && rm "fig1.gif" #convert fig1 from .gif to .dpf and remove .gif

