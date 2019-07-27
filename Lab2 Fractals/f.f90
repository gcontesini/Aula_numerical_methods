program main                                                !begining of the code

  complex :: complex_c , complex_z                          !declaration of complex statements
  integer :: i , j , k                                      !declaration of integer statements
  real :: x , y                                             !declaration of real statements

  open(12,file="lab2.dat")                                  !open a file for writing the data points

  x=-2.0                                                    !initial value for x
  k=-1000                                                   !maximum value for iterations
  do j=-200,200                                             !first loop for the position x
    y=-2.0                                                  !initial value for y
    do i=-200,200                                           !second loop for the position y
      complex_c = cmplx( x , y )                            !value for complex C
      complex_z = cmplx( .0 , .0 )                          !value for complex Z
      do                                                    !Third loop

        complex_z = ( complex_z * complex_z ) + complex_c   !Equation for the Mandelbrot

        if(abs(complex_z) >= 2.0 ) then                     !first condition for 
          exit                                              !break the loop
        end if                                              !end of the condition
        if(k == 1000 ) then                                 !second condtion for
          exit                                              !break the loop
        end if                                              !end of the condition
        k=k+1                                               !increments for the number of interations
      end do                                                !end of the third loop
      write(12,*), real(complex_c) , aimag(complex_c) , k   !writing the data on the open file
      k=-1000                                               !restatment for k
      y = y + 0.01                                          !increments for position y
    end do                                                  !end of the 
    write(12,*)," "                                         !
    x = x + 0.01                                            !increments for position x
  end do                                                    !

  close(12)                                                 !

end program main                                            !end of the program
