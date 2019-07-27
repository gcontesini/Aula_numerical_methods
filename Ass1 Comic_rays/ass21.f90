program main
  implicit none
  integer :: i_int, l_int
  real :: x_float, y_float
  l_int=38 ! number of lines on the file
  open(unit=12,file='phys381-UHECR.data',action='read')
  open(unit=13,file="phys381-UHECR-out.data",action="write")
  do i_int=1,l_int
    read (12,*) x_float , y_float
    write(13,*) x_float, y_float, log10( x_float ), log10( y_float ), log10( x_float**3*(y_float/1e+24) )
  end do
end program

