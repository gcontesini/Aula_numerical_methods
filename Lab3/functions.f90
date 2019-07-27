module functions

  contains

  function sum_2( x, y )

    real :: x , y
    print*,"The sum of the two real numbers is:",x+y

  end function

  subroutine sum_1( a, b)

    real, intent(in) :: a , b
    print*,"The sum of the two real numbers is:",a+b

  end subroutine 

end module
