program Gauss

implicit none
integer :: size_int
double precision ,  dimension(3,3) :: a_mtx , x_vec , b_vec 

size_int = 3

  a_mtx(1,1) = 25
  a_mtx(1,2) = 5
  a_mtx(1,3) = 1

  a_mtx(2,1) = 64
  a_mtx(2,2) = 8
  a_mtx(2,3) = 1

  a_mtx(3,1) = 144
  a_mtx(3,2) = 12
  a_mtx(3,3) = 1

  b_vec(1,1) = 106.8
  b_vec(2,1) = 177.2
  b_vec(3,1) = 279.2


  call clean_matrix(x_vec,size_int)
  call gauss_elimination( a_mtx,b_vec,size_int )
  call RegresSub(a_mtx,b_vec,x_vec,size_int)
  write(*,*) ""
  write(*,*) "Solution"
  write(*,*) ""
  call print_vector(x_vec,size_int)

!-------------------------------------------------------------------------------

contains 

!-------------------------------------------------------------------------------

subroutine gauss_elimination( a_mtx,b_vec,size_int )
  implicit none
  integer , intent(in) :: size_int
  double precision , intent(out) , dimension(size_int,size_int) :: a_mtx ,  b_vec
  integer :: i_int , j_int , k_int
  double precision :: coef_dp 

  do i_int = 1,size_int -1
  do j_int = i_int+1,size_int
    coef_dp = a_mtx(j_int,i_int)/a_mtx(i_int,i_int)
  do k_int = i_int , size_int
    a_mtx(j_int,k_int) = ( a_mtx(j_int,k_int)-a_mtx(i_int,k_int)*coef_dp  )
  end do
    b_vec(j_int,1) = ( b_vec(j_int,1)-b_vec(i_int,1)*coef_dp  )
  end do
  end do
end subroutine

!-------------------------------------------------------------------------------

subroutine RegresSub(a_mtx,b_vec,sol_vec,size_int)
  implicit none
  integer , intent(in) :: size_int
  double precision , intent(in) , dimension(size_int,size_int) :: a_mtx
  double precision , intent(in) , dimension(size_int,1) :: b_vec
  double precision , intent(out) , dimension(size_int,1) :: sol_vec
  integer :: i_int , j_int
  double precision :: sum_float
  sol_vec(size_int,1) = b_vec(size_int,1)/a_mtx(size_int,size_int)
  do i_int = size_int-1,1,-1
    sum_float = 0.
    do j_int =size_int,i_int+1,-1
      sum_float = sum_float + a_mtx(i_int,j_int )*sol_vec(j_int,1)
    end do
    sol_vec(i_int,1) = ( b_vec(i_int,1) - sum_float )/a_mtx(i_int,i_int)
  end do
end subroutine

!-------------------------------------------------------------------------------

  subroutine print_matrix(a_mtx,size_int)
    implicit none
    integer , intent(in) :: size_int 
    double precision , intent(in) , dimension(size_int,size_int) :: a_mtx
    integer :: i_int , j_int
    do i_int=1,size_int
      do j_int=1,size_int
        if(j_int==size_int) then
          write(*,"(f6.2)",advance="yes") a_mtx(i_int,j_int)
        else
          write(*,"(f6.2)",advance="no") a_mtx(i_int,j_int)
        end if
      end do
    end do 
  end subroutine

!-------------------------------------------------------------------------------

  subroutine print_vector(s_vec,size_int)
    implicit none
    integer , intent(in) :: size_int
    double precision , intent(in) , dimension(size_int,size_int) :: s_vec
    integer :: i_int
    do i_int=1,size_int
        write(*,*)s_vec(i_int,1)
    end do 
  end subroutine

!-------------------------------------------------------------------------------

subroutine clean_matrix(a_mtx,size_int)
  implicit none
  integer , intent(in) :: size_int
  double precision , intent(out) , dimension(size_int,size_int) :: a_mtx
  integer :: i_int , j_int
  do i_int = 1, size_int
    do j_int = 1,size_int
      a_mtx(i_int,j_int) = 0
    end do 
  end do
end subroutine

!-------------------------------------------------------------------------------

end program


















