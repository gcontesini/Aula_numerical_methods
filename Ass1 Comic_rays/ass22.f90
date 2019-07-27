program main
  real(kind=16) :: c1, c2, e1, e2, p1, p2
  real(kind=16) :: e
  open(12,file="data7.txt",action="write")
  write(6,*),"Type the first set of parameters C1 , Eo1, p1:"
  read(*,*) c1,e1,p1 
  write(6,*),"Type the second set of parameters C2 , Eo2 , p2:"
  read(*,*) c2,e2,p2
    e = ((c2/c1)**(1/(p1-p2))) * ((e1**(p1/(p1-p2)))/(e2**(p2/(p1-p2))))
  write(12,*) e
end program





