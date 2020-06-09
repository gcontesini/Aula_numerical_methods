#include "stdio.h"
#include "math.h"

#define numero_passos_int 10000

float funcao( x_float )
{
  return x_float ;
}

float simpson_3_8( float intervalo_inicial_float, float intervalo_final_float )
{

  int i_int ;
  float somatorio_float ;
  float h_float ;
  
  h_float = ( intervalo_final_float - intervalo_inicial_float ) / numero_passos_int ;
  
  somatorio_float = funcao( intervalo_inicial_float ) + funcao( intervalo_final_float ) ;
  
  for( i_int=1; i_int<numero_passos_int-1; i_int=i_int+3 )
  {
    somatorio_float += 3*( funcao( intervalo_inicial_float + ( i_int*h_float ) ) +\
      funcao( intervalo_inicial_float + ( ( i_int * h_float ) + 1 ) )  ) ;
  }
  
  for( i_int=4; i_int<numero_passos_int-2; i_int=i_int+3 )
  {
    somatorio_float += 2*funcao( intervalo_inicial_float + ( i_int*h_float ) ) ;
  }

  return ( 3 * h_float * somatorio_float )/8.0 ;

}

void main()
{

  float initial_point_float, final_point_float ;

  initial_point_float = 0.0 ;
  final_point_float = 1.0 ;

  printf("\nintegral numerica = %.4f\n", simpson_3_8( initial_point_float, final_point_float ) ) ;

}