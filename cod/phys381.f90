program main
  implicit none
  integer :: i
  real :: x
  call random_seed()
  open(Unit=12,File='data1.dat',action='WRITE')
  do i=1,5
    call random_number(x)
    print* , x
    write (12,*) , x
  enddo
  close (Unit=12)
end
