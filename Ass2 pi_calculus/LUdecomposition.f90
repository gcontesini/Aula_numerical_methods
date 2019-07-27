program LU_decomposition
  implicit none
  integer :: size_int , k_int
  double precision , dimension(2,2) :: L_mtx , U_mtx , a_mtx , b_vec , sol_vec , aux_vec
  double precision :: norm_1_dp , norm_inf_dp , norm_2_dp
  size_int = 3

  a_mtx(1,1) = 10.e(-2*k_int)
  a_mtx(1,2) = 1

  a_mtx(2,1) = 1
  a_mtx(2,2) = 1

  b_vec(1,1) = 1-10.e(-2*k_int)
  b_vec(2,1) = 2

do k_int=0,10
  call clean_matrix(L_mtx,size_int)
  call clean_matrix(U_mtx,size_int)
  call clean_matrix(sol_vec,size_int)
  call clean_matrix(aux_vec,size_int)

  call LUdecompCrout(a_mtx,L_mtx,U_mtx,size_int)
  call ProgresSub(L_mtx,b_vec,aux_vec,size_int)
  call RegresSub(U_mtx,aux_vec,sol_vec,size_int)

  write(*,*) ""
  write(*,*) "Solution"
  write(*,*) ""
  call print_vector(sol_vec,size_int)
  write(*,*) ""
!  norm_1_dp = MAXVAL(SUM(ABS(a_mtx),DIM=1))
!  norm_inf_dp = MAXVAL(SUM(ABS(a_mtx),DIM=2))
!  norm_2_dp = SQRT(SUM(a_mtx**2.0))
!  write(*,*) 'norm_1 = ', norm_1_dp
!  write(*,*) 'norm_inf = ', norm_inf_dp
!  write(*,*) 'norm_2 = ', norm_2_dp
end do
!-------------------------------------------------------------------------------
!-------------------------------------------------------------------------------

contains

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

subroutine LUdecompCrout(a_mtx,L_mtx,U_mtx,size_int) 
  implicit none
  integer , intent(in) :: size_int
  double precision , intent(in) , dimension(size_int,size_int) :: a_mtx
  double precision , intent(out) , dimension(size_int,size_int) :: L_mtx , U_mtx
  integer :: i_int , j_int , k_int
  double precision :: sum_float
  !step 1 & 2
  do i_int = 1,size_int,1
    L_mtx(i_int,1) = a_mtx(i_int,1)
    U_mtx(i_int,i_int) = 1.
  end do
  !step 3
  do j_int = 2,size_int,1
    U_mtx(1,j_int) = a_mtx(1,j_int)/L_mtx(1,1)
  end do 
  !step 4
  do i_int=2,size_int
    do j_int=2,i_int
      sum_float = 0.
      do k_int=1,j_int-1,1
        sum_float = sum_float + L_mtx(i_int,k_int)*U_mtx(k_int,j_int)
      end do
      L_mtx(i_int,j_int) = a_mtx(i_int,j_int) - sum_float
    end do
    do j_int=i_int+1,size_int,1
      sum_float = 0.
      do k_int = 1,i_int-1,1
        sum_float = sum_float + L_mtx(i_int,k_int)*U_mtx(k_int,j_int)
      end do
      U_mtx(i_int,j_int) = (a_mtx(i_int,j_int)-sum_float)/L_mtx(i_int,i_int)
    end do
  end do
end subroutine

!-------------------------------------------------------------------------------

subroutine ProgresSub(a_mtx,b_vec,aux_vec,size_int)
  implicit none
  integer , intent(in) :: size_int
  double precision , intent(in) , dimension(size_int,size_int) :: a_mtx
  double precision , intent(in) , dimension(size_int,1) :: b_vec
  double precision , intent(out) , dimension(size_int,1) :: aux_vec
  integer :: i_int , j_int
  double precision :: sum_float
  aux_vec(1,1) = b_vec(1,1)/a_mtx(1,1)
  do i_int=2,size_int
    sum_float = 0.
    do j_int = 1,i_int-1,1
      sum_float = sum_float + (a_mtx(i_int,j_int)*aux_vec(j_int,1))
    end do
    aux_vec(i_int,1) = (b_vec(i_int,1)-sum_float)/a_mtx(i_int,i_int)
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

subroutine print_matrix(s_mtx,size_int)
  implicit none
  integer , intent(in) :: size_int
  double precision , intent(in) , dimension(size_int,size_int) :: s_mtx
  integer :: i_int , j_int
  do i_int=1,size_int
    do j_int=1,size_int
      if(j_int==size_int) then
        write(*,"(f9.2)",advance="yes") s_mtx(i_int,j_int)
      else
        write(*,"(f9.2)",advance="no") s_mtx(i_int,j_int)
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

end program

