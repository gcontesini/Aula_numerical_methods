program vel
double precision :: a1 ,a2 ,a3 ,sol, t
  t=15

  a1=0.290
  a2=19.69
  a3=1.085

  sol = (a1*(t**2))+(a2*t)+(a3)
  write(*,*) sol , t
end program 
