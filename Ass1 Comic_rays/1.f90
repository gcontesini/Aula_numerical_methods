program buildmatrix

integer matrix_int(20,20)
integer :: i,j,a,b

open(12,file="buildmatrix")
a=0
b=1

do i=1,20
  do j=1,20
    matrix_int(i,j)=1
    write(12,*) 

end
