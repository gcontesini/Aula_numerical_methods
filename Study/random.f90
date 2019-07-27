program main                                    !Begin the program.
  implicit none                                 !Requires that all variables be declared.
  integer :: i                                  !Declares variables and constants.
  real :: x                                     !Declares variables and constants.
  call random_seed()                            !Start a seed for a random number
  open(Unit=12,File='data1.dat',action='WRITE') !Open a file with the tag=12 named data1.dat for write data
  do i=1,5                                      !Start the loop at 1 until 5, 5 loos in total
    call random_number(x)                       !Call the first random number 
    print* , x                                  !Print on the screen the value of x
    write (12,*) , x                            !Write on the tag 12(file) the value of x
  enddo                                         !End of the loop
  close (Unit=12)                               !close the file under tag 12
end                                             !End program.
