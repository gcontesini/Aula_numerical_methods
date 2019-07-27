program phys381erfpart2

  implicit none
  integer :: j_int 
  double precision :: num_dp , value_float
  open( 12 , file = "erfout2.data")

!-------------------------------------------------------------------------------
  num_dp = 2.5

  do j_int = 2 , 20 , 1
    write(12,*) j_int , erfc(num_dp) ,new_erf(num_dp , j_int )
  end do

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

contains

  function new_erfc( x_dp ) result ( erf_dp )

    implicit none
    double precision , intent(in) :: x_dp
    integer :: k_int , n_int 
    double precision :: erf_dp , pi , i_int
    double precision , allocatable , dimension(:) :: coef_vector 

    n_int = 19
    i_int = 0
    erf_dp = 0.
    pi= 4*atan(1.)
    allocate(coef_vector(n_int))
    do k_int = 1 , size(coef_vector) , 1
      coef_vector(k_int) = ((-1**i_int)*fact(fact(2*i_int-1)))
      i_int = i_int + 1
    end do

    erf_dp = ( exp(((-1*x_dp)**2 )) / ((x_dp)*(sqrt(pi) ))) * horner( coef_vector , (2*x_dp)**(-1) )

    deallocate(coef_vector)
  end function

!-------------------------------------------------------------------------------

  recursive function fact( k ) result ( factor )

    implicit none
    integer, intent(in):: k
    double precision :: factor

    if(k == 0) then
      factor = 1
    else
      factor = k * fact( k-1 )
    endif

  end function

!-------------------------------------------------------------------------------

  function horner(coef_aux_vector, x_dp) result (result_dp)

    implicit none
    double precision , dimension (:) , intent (in) :: coef_aux_vector
    double precision , intent (in) :: x_dp
    real :: result_dp
    integer :: i_int , k_int

    result_dp = 0.0
    i_int = 0
    do k_int = 1 , size(coef_aux_vector)-1 , 1
      result_dp = result_dp + coef_aux_vector(k_int) * x_dp**(2*i_int)
      i_int = i_int + 1
    end do

  end function

!-------------------------------------------------------------------------------

end program 
