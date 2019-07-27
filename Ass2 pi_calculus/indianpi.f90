program indianpi
  implicit none
  double precision :: my_pi_dp , 
  real_pi_dp , sum_dp , pi_dp
  real :: sum_float , my_pi_float , 
pi_float
  integer :: i_int
  open(12,file="pi_error.txt",action=
"write")
  pi_dp = 3.141592653589793
  pi_float = 3.141592653589793
  sum_dp = 0.
  sum_float = 0.
  do i_int = 0,50,1
    sum_dp = (((-1.)**(i_int))/(((2.*
    i_int)+1)*(3.**i_int))) + sum_dp

    sum_float = (((-1.)**(i_int))/
    (((2.*i_int)+1)*(3.**i_int))) 
    + sum_float

    my_pi_dp = sqrt(12.)*sum_dp
    my_pi_float = sqrt(12.)*sum_float
    write(12,*)i_int , (pi_float-
    my_pi_float) , (pi_dp-my_pi_dp)
  end do
  close(12)
end program
