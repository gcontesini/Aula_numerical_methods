do for [t=0:50] {
  outfile = sprintf('animation/bessel%03.0f.png',t)
  set output outfile
  splot u*sin(v),u*cos(v),bessel(u,t/50.0) w pm3d ls 1
}
