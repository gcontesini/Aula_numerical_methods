program main
implicit none

real*8 :: eps1, eps2 , x1 , x2 , y1 , y2 

eps1=1.0d38
eps2=1.0e38

x1=1e38
x2=1e20
y1=1e-23
y2=1e-23

write(*,*) 1.0d0 + eps1
write(*,*) eps1-eps2
write(*,*) x1*x2
write(*,*) y1*y2


end program
