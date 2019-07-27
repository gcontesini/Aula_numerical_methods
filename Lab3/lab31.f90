program phys381arrays

  implicit none
  integer :: N,M,L
  integer :: i,j,k
  real , allocatable , dimension(:,:,:) :: x,y,z 

  open(12, file="input.dat") 
  read(12,*) N,M,L 
  !print*,N,M,L
  allocate(x(N,M,L)) 
  allocate(y(N,M,L)) 
  allocate(z(N,M,L)) 

  do k=1, L
    do j=1, M
      do i=1, N
        x(i,j,k)=float(i)*float(j)*float(k)
        y(i,j,k)=float(i)*float(j)*float(k)
        z(i,j,k)=float(i)*float(j)*float(k)
        !print*,i,j,k
        write(6,"(f8.5,2x,f10.6,4x,f9.5,1x)") x(i,j,k), y(i,j,k), z(i,j,k) 
      end do
    end do
  end do
  deallocate(x) 
  deallocate(y) 
  deallocate(z) 

end program phys381arrays
