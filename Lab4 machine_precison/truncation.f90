program main

real*8 :: pi , x , y
pi=4*atan(1.0)
write(*,*) pi

x=tan(pi/6)
y=sin(pi/6)/cos(pi/6)

write(*,*) x
write(*,*) y
write(*,*) x-y



end program 
