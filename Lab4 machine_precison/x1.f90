program x1
implicit none

real :: x1_1 , eps_1
real*8 :: x1_2 , eps_2

eps_2 = 1e-16
open(12,file="1d-16.dat")
eps_1=eps_2
x1_1=1-(1-eps_1)**(0.5)
x1_2=1-(1-eps_2)**(0.5)

write(12,*) eps_1
write(12,*)'[4-byte]', x1_1
write(12,*)'[8-byte]', x1_2
write(12,*)'[4-byte]', eps_1/(1+(1-eps_1)**(0.5))
write(12,*)'[4-byte]', (eps_1/2)
write(12,*)'[4-byte]', (eps_1/2)+((eps_1**2)/8)
write(12,*)'[4-byte]', (eps_1/2)+((eps_1**2)/8)+((eps_1**3)/16)
write(12,*)
write(12,*)

end program
