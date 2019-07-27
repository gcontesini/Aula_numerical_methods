program stability

  implicit none
  real :: x
  integer :: i

  open(12, file="data.txt") 
  x=-0.01
  do i=-10000,10000
    write(12,*) sin(x)**2/x**2 , (1.0-cos(x)**2)/x**2 , x
    x=x+0.0001
  end do

end program
