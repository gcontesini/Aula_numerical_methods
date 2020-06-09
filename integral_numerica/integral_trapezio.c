#include"stdio.h"
#include"math.h"

#define delta_float 0.001

float funcao( float num_float )
{
  return num_float * num_float ;
}

float analitical( float num_float )
{
  return num_float * num_float * num_float / 3 ;
}

float real_integral( float initial_float, float final_float )
{
  return analitical( final_float ) - analitical( initial_float ) ;
}

float trapezium( float initial_float, float final_float )
{
  float somatorio_float, parcel_float ;

  somatorio_float = 0 ;
  parcel_float = 0 ;

  parcel_float = delta_float * ( funcao( initial_float ) + funcao( final_float ) )/2 ;

  do{

    somatorio_float = somatorio_float + funcao( initial_float ) ;
    initial_float = initial_float + delta_float ;

  }while(initial_float < final_float );

  return parcel_float + ( somatorio_float * delta_float ) ;
}

void main()
{
  float initial_interval_float, final_interval_float ;

  initial_interval_float = 0 ;
  final_interval_float = 3 ;

  printf("Integral: %.4f\n", trapezium( initial_interval_float, final_interval_float  )) ;
  printf("Erro: %.4f\n", sqrt( pow( ( real_integral( initial_interval_float, final_interval_float )-trapezium( initial_interval_float, final_interval_float ) ) ,2 ) ) / real_integral( initial_interval_float, final_interval_float ) );

}
