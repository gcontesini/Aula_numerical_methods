reset
set terminal gif size 1200,600 enhanced
set output "fig3.gif"
set multiplot

set size 0.5,0.5

set autoscale

set origin 0.0,0.0
set title 'Flux x Energy'
set xlabel"Flux(nº particles per m^2)"
set ylabel"Energy(eV)"
plot 'phys381-UHECR-out.data' u log(2):1 w points notitle lc rgb '#FF0000' pt 5

set origin 0.5,0.0
set xlabel"log10(Flux)"
set ylabel"log10(Energy)"
set title 'Log10(flux) x Log10(energy)'
plot 'phys381-UHECR-out.data' u 4:3 w points notitle lc rgb '#0000FF' pt 9

set origin 0.3,0.5
set xlabel"log10(E 3 × Flux/1024 )"
set ylabel"log10(Energy)"
set title '   Log10(E 3 × Flux/10^24 ) x Log10(energy)'
plot 'phys381-UHECR-out.data' u 5:3 w points notitle lc rgb '#000000' pt 7

!convert "fig3.gif" "fig3.pdf" && rm "fig3.gif"
unset multiplot
reset
