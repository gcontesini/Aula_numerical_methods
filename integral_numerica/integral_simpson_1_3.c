#include "stdio.h"
#include "math.h"

#define numero_passos_int 1000000

float funcao( x_float )
{
  return x_float  ;
}

float simpson_1_3( float intervalo_inicial_float, float intervalo_final_float )
{

  int i_int ;
  float somatorio_float ;
  float h_float ;
  
  h_float = ( intervalo_final_float - intervalo_inicial_float ) / numero_passos_int ;
  
  somatorio_float = funcao( intervalo_inicial_float ) + funcao( intervalo_final_float ) ;
  
  for( i_int=1; i_int<numero_passos_int; i_int=i_int+2 )
  {
    somatorio_float += 4*funcao( intervalo_inicial_float + ( i_int*h_float ) ) ;
  }
  
  for( i_int=2; i_int<numero_passos_int-1; i_int=i_int+2 )
  {
    somatorio_float += 2*funcao( intervalo_inicial_float + ( i_int*h_float ) ) ;
  }

  return ( h_float*(somatorio_float)/3.0 ) ;

}

void main()
{

  float initial_point_float, final_point_float ;

  initial_point_float = 0.0 ;
  final_point_float = 1.0 ;

  printf("\nintegral numerica = %.4f\n", simpson_1_3( initial_point_float, final_point_float ) ) ;

}