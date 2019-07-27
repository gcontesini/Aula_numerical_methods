reset                                                                       #reset all old sets
set terminal gif size 1200,600 enhanced                                     #set the terminal to plot in .gif format with 1200x600 size screen
set output "fig4.gif"                                                       #set gnuplot to save the plot on a file named fig4.gif
set xlabel"log10(E 3 × Flux/1024 )"                                         #write on the x axis "___"
set ylabel"log10(Energy(eV))"                                               #write on the y axis "___" 
set title '   Log10(E 3 × Flux/10^24 ) x Log10(energy)'                     #write on the top of the plot "___" the title
set arrow 1 from 0.46564350,17 to 0.46564350,17.655138                      #plot a arrow style 1 on graph from Yo,Yo to Xf,Yf.
set arrow 2 from  -0.0371222198,17 to -0.0371222198,19.949390               #plot a arrow style 1 on graph from Yo,Yo to Xf,Yf.
plot 'phys381-UHECR-out.data' u 5:3 w points notitle lc rgb '#000000' pt 11 #plot the data from the file using 5th column cross 3th column with points no title 'l'ine'c'olor from the rgb pallete "black" style point nº 11 
!convert "fig4.gif" "fig4.pdf" && rm "fig4.gif"                             #conver the file '.gif' to '.pdf' and remove '.gif' file
reset                                                                       #reset all old sets
