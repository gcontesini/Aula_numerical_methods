program horner_program

  implicit none

  write (*,"(f5.1)") horner ((/7., -5., 3., 2./), 2.)

!                     or

!  real , allocatable , dimension(:) :: coef_vector
!  real :: num_float
!  integer :: k_int , size_int

!-------------------------------------------------------------------------------

!  write(*,*) "Enter the degree of the polynomial:"
!  read(*,*) size_int

!  allocate(coef_vector(size_int))

!  do k_int = 1 , size(coef_vector) , 1
!    write(*,*) "Enter a coefficients ascending order:"
!    read(*,'(f5.0)') num_float
!    coef_vector( k_int ) = num_float
!  end do

!  do k_int = 1 , size(coef_vector) , 1
!    write(*,*) coef_vector( k_int )
!  end do

!  write(*,*) "Enter the value of x: "
!  read(*,'(f5.0)') num_float

!  write(*,"(f5.0)") horner( coef_vector , num_float )

contains

  recursive function fact(k) result (factor)

    implicit none
    integer, intent(in):: k
    double precision :: factor
    if(k == 1) then
      factor = k
    else
      factor = k * fact( k-1 )
    endif

  end function fact

  function horner(coef_vector, x_float) result (result_float)

    implicit none
    real, dimension (:), intent (in) :: coef_vector
    real, intent (in) :: x_float
    real :: result_float
    integer :: i_int

    result_float = 0.0
    do i_int = size(coef_vector), 1, -1
      result_float = result_float * x_float + coef_vector(i_int)
    end do

  end function 

end program 
