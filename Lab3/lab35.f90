program main
  implicit none
  real :: a , b
  real :: sum_2
  print*, "Enter a real number:"
  read(*,*) a
  print*, "Enter a second real number:"
  read(*,*) b
  call sum_1( a, b )
  print*,sum_2( a, b )
end program main

subroutine  sum_2( x, y )
  real :: x , y
  print*,"The sum of the two real numbers is:",x+y
end subroutine

