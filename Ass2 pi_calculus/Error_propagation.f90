program error_propagation
  double precision :: n_dp , beta_dp , alpha_dp , e_m_dp
  integer :: i_int
  open(12,file = "Error_data.txt",action="write")
  alpha_dp = 1.
  e_m_dp = 1.e-6
  beta_dp = 1.
  do i_int = 1 , 10
    n_dp = ((2*alpha_dp*beta_dp/e_m_dp))**(1/(beta_dp+0.5))
    write(12,*) n_dp , beta_dp , e_m_dp
    beta_dp = beta_dp + 1.
    e_m_dp = e_m_dp * 10.**(-0.5)
  enddo
end program
