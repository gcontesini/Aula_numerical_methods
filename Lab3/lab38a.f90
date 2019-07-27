program main

  use functions
  real :: a , b

  print*, "Enter a real number:"
  read(*,*) a
  print*, "Enter a second real number:"
  read(*,*) b
  call sum_1( a, b )
  print*, sum_2( a, b )

end program main


