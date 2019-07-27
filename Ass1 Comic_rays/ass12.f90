program matrix
  implicit none
  integer :: a , b, c, d
  a=1
  b=0
  write(6,*), "Enter the x length of the matrix:"
  read(*,*) c
  write(6,*) "Enter the y length ot the matrix:"
  read(*,*) d
  call buildmatrix(a,b,c,d)
end program

subroutine buildmatrix(a,b,c,d)
  integer, intent(in) :: a,b,c,d
  integer, dimension(c,d) :: matrix
  integer :: i,j
  open(12,file="data3.txt",action="write")
  do i=1,c
    do j=1,d
      if(i==c/2 .or. j==d/2 .or. i==(c + 2 )/2.or. j==(c + 2)/2)then
        matrix(i,j)=a
      else
        matrix(i,j)=b
      end if
      if(j==c) then 
        write(12,"(i1)",advance='yes') matrix(i,j)
      else
        write(12,"(i1,1x)",advance='no') matrix(i,j)
      end if
    end do
  end do

end subroutine
