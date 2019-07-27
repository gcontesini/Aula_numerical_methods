program phys381erf

  implicit none
  integer :: j_int 
  double precision :: num_dp , value_float
  open( 12 , file = "erfout.data")

!-------------------------------------------------------------------------------
  num_dp = -0.1
  do j_int = -1000 , 1000 , 1
    write(12,*) num_dp , erf(num_dp) ,new1_erf(num_dp) , new2_erf(num_dp) , new3_erf(num_dp) , new4_erf(num_dp)
    write(*,*) num_dp , j_int
    num_dp = num_dp + 0.0001
  end do

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

contains

  function new1_erf( x_dp ) result ( erf_dp )

    implicit none
    double precision , intent(in) :: x_dp
    integer :: k_int , n_int , i_int
    double precision :: erf_dp , pi 
    double precision , allocatable , dimension(:) :: coef_vector1 

    n_int = 2
    i_int = 0
    erf_dp = 0.
    pi= 4*atan(1.)
    allocate(coef_vector1(n_int))
    do k_int = 1 , size(coef_vector1) , 1
      coef_vector1(k_int) = (((-1)**(i_int))/(fact(i_int)*(2*i_int+1)))
      i_int = i_int + 1
    end do

    erf_dp = ((2*x_dp)/sqrt(pi)) * horner( coef_vector1 , x_dp )

    deallocate(coef_vector1)
  end function

!-------------------------------------------------------------------------------
  function new2_erf( x_dp ) result ( erf_dp )

    implicit none
    double precision , intent(in) :: x_dp
    integer :: k_int , n_int , i_int
    double precision :: erf_dp , pi 
    double precision , allocatable , dimension(:) :: coef_vector2 

    n_int = 9
    i_int = 0
    erf_dp = 0.
    pi= 4*atan(1.)
    allocate(coef_vector2(n_int))
    do k_int = 1 , size(coef_vector2) , 1
      coef_vector2(k_int) = (((-1)**(i_int))/(fact(i_int)*(2*i_int+1)))
      i_int = i_int + 1
    end do

    erf_dp = ((2*x_dp)/sqrt(pi)) * horner( coef_vector2 , x_dp )

    deallocate(coef_vector2)
  end function

!-------------------------------------------------------------------------------
  function new3_erf( x_dp ) result ( erf_dp )

    implicit none
    double precision , intent(in) :: x_dp
    integer :: k_int , n_int , i_int
    double precision :: erf_dp , pi 
    double precision , allocatable , dimension(:) :: coef_vector3 

    n_int = 29
    i_int = 0
    erf_dp = 0.
    pi= 4*atan(1.)
    allocate(coef_vector3(n_int))
    do k_int = 1 , size(coef_vector3) , 1
      coef_vector3(k_int) = (((-1)**(i_int))/(fact(i_int)*(2*i_int+1)))
      i_int = i_int + 1
    end do

    erf_dp = ((2*x_dp)/sqrt(pi)) * horner( coef_vector3 , x_dp )

    deallocate(coef_vector3)
  end function

!-------------------------------------------------------------------------------
  function new4_erf( x_dp ) result ( erf_dp )

    implicit none
    double precision , intent(in) :: x_dp
    integer :: k_int , n_int , i_int
    double precision :: erf_dp , pi 
    double precision , allocatable , dimension(:) :: coef_vector4

    n_int = 99
    i_int = 0
    erf_dp = 0.
    pi= 4*atan(1.)
    allocate(coef_vector4(n_int))
    do k_int = 1 , size(coef_vector4) , 1
      coef_vector4(k_int) = (((-1)**(i_int))/(fact(i_int)*(2*i_int+1)))
      i_int = i_int + 1
    end do

    erf_dp = ((2*x_dp)/sqrt(pi)) * horner( coef_vector4 , x_dp )

    deallocate(coef_vector4)
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
    do k_int = 1 , size(coef_aux_vector) , 1
      result_dp = result_dp + coef_aux_vector(k_int) * x_dp**(2*i_int)
      i_int = i_int + 1
    end do

  end function

!-------------------------------------------------------------------------------

end program 
