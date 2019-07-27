program main
  implicit none
  real :: a,b
  print*, "Enter a real number:"
  read(*,*) a
  print*, "Enter a second real number:"
  read(*,*) b
  call sumtworeal(a, b)
end program main

subroutine sumtworeal(a,b)
  real, intent(in) :: a,b
  write(6,*),"The sum of the two real numbers is:",a+b
end subroutine sumtworeal
