program phys381passarray
  integer, parameter :: N=3,M=3 !! Is an attribute of the variable, this permit that you declare and associate the integer variable as a numeber in the same line !!"
  real, dimension(N,M) :: x, y, z
  real, dimension(N) :: W
  x(1:,1:) = 2.0 
  y(1:,1:) = 3.0
  z(1:,1:) = 4.0
  W(1:) = 5.0 
  call PassInfo(N,M,x,y,z,W)
  contains
  subroutine PassInfo(ismax,jsmax,xi,yi,zi,Wi)
    integer, intent(in) :: ismax,jsmax !! The intent(in) attribute of argument ismax and jsmax means that both cannot be changed inside the function !!
    real, dimension(1:ismax,1:jsmax) :: xi, yi, zi
    real, dimension(1:ismax):: Wi
    write(6,*) xi(1:2,1:1)
    write(6,*) yi(1:2,1:3)
    do i=1, ismax
      write(14,*) xi(i,:) !! Write on the screen by default the elements of the x array !!"
    end do
    close(14)
  end subroutine PassInfo
end program phys381passarray

