program phys381erf

  integer :: count_int , n1_int , n2_int , n3_int , n4_int
  real ::  x_float 
  double precision :: erf_float

  n1_int = 3
  n2_int = 10
  n3_int = 30
  n4_int = 100
  x_float = 

  open(12,file="erfout.data")

  do count_int=-100,100
    erf_function(x_float,n_int)
    x_float = x_float + 
  end do

contains

function erf_function( var_float , n_int) result( erf_dp )

  integer :: k_int
  real , intent(in) :: var_float
  double precision :: erf_dp , pi , sum_dp
  pi = 4* atan(1)
  sum_dp = 0
  do k_int = 0 , n_int-1
    sum_dp = sum_dp + (fact(2*k_int))/(fact(k_int)*homer_alg(2*x_float,2*k_int)
  end do
  erf_dp = (e**(-( homer_alg(x_float , 2 ))))/((x_float*sqrt(pi))*sum_dp)

end function

recursive function fact(k) result (factor)

  implicit none
  integer, intent(in):: k
  double precision :: factor
  if(k == 1) then
    factor = k
  else
    factor = k * fact( k-1 )
  endif

end function

recursive function horner_alg( num_aux , exp_aux ) result ( result_aux )

  implicit none
  integer, intent(in) ::  exp_aux
  real , intent(in) :: num_aux
  double precision :: result_aux 

  if( exp_aux == 1) then
    result_aux = num_aux
  else
    result_aux = num_aux * homer_alg( num_aux , exp_aux-1)
  endif

end function

end program
