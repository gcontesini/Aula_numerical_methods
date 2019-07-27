program guilhermecontesinigrid

  implicit none
  integer :: true_int , false_int , size_int, count_int
  integer , allocatable , dimension(:,:) :: mygrid_int
  real :: p_trans

  p_trans = 0.00

  open(12,file="savedgrid.txt",action="write")

  size_int=20

  do count_int = 0 ,101
    allocate(mygrid_int(size_int,size_int))
    call buildgrid( true_int ,false_int,size_int,p_trans ,mygrid_int)
    if(count_int==0 .or. count_int==20 .or. count_int==40) then
      call savegrid( size_int , mygrid_int )
    endif
    if(count_int==60 .or. count_int==80 .or. count_int==100) then
      call savegrid( size_int , mygrid_int )
    endif
    p_trans = p_trans + 0.01
    deallocate(mygrid_int)
  enddo

  close(12)

contains

subroutine buildgrid( true_int , false_int , size_int , p_trans ,mygrid_int )

  integer, intent(in) :: size_int
  real, intent(in) :: p_trans
  integer :: true_int , false_int , i , j
  integer, dimension(size_int,size_int) :: mygrid_int
  real :: rand 

  true_int = 1
  false_int= 0

  call random_seed()

  do i=1,size_int
    do j=1,size_int
      call random_number(rand)
      if(rand .le. p_trans) then
        mygrid_int(i,j) = true_int
      else
        mygrid_int(i,j) = false_int
      endif
    end do
  end do

end subroutine

subroutine savegrid( size_int ,mygrid_int )

  integer, intent(in) :: size_int
  integer, dimension(size_int,size_int) :: mygrid_int
  integer :: i , j
  
  do i=1,size_int
     do j=1,size_int
        if(j == size_int) then 
           write(12,"(i1)",advance='yes') mygrid_int(i,j)
        else
           write(12,"(i1,1x)",advance='no') mygrid_int(i,j)
        end if
     end do
  end do
  write(12,'(1x)',advance='yes')
  write(12,'(1x)',advance='yes')
end subroutine

end program

