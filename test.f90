program main
  integer, allocatable :: x(:)
  integer :: i , sum1 , N
  sum1=0
  read(*,*) N
  allocate(x(N))
  do i=1,N0
    x(i)= 2*i + 1
    sum1=sum1 + x(i)
  end do
  do i=1,N
    write(6,*) x(i)
  end do
  write(6,*) sum1
  deallocate(x)
end program
