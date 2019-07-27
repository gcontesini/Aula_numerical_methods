program ass1
  implicit none
  integer :: i, niter , case 
  real :: x,y,z
  open(12,file="ass1.dat")
  call random_seed()
  write(6,*)"Enter number of interations niter"
  read(5,*) niter
  do i=1,niter
     call random_number(x)
     call random_number(y)
     call random_number(z)
     write(12,*) x,y,z
     if(x.gt.0.5) then
!        write(12,*)
!        write(12,*)
        write(6,*) "x>0.5 What should I do?"
        read(5,*) case
        if(case.eq.1) EXIT
     end if
  end do
  close(12)
end program ass1
