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
	return analitical( final_float ) - analitical( initial_float );
}

float integral_pnt_medio( float initial_float, float final_float )
{
	float somatorio_float ;
	somatorio_float = 0. ;
	do{

		somatorio_float = somatorio_float + funcao( (2*initial_float + delta_float )/2 ) ; 

		initial_float = initial_float + delta_float ; 

	}while( initial_float < final_float );

	return somatorio_float * delta_float ;

}

void main()
{
	float initial_interval_float, final_interval_float ;
	initial_interval_float = 0 ;
	final_interval_float = 3 ;
	printf( "Integral: %.4f\n", integral_pnt_medio( initial_interval_float, final_interval_float ) ) ;
	printf( "Erro: %.4f\n", sqrt(pow((real_integral(initial_interval_float, final_interval_float)-integral_pnt_medio( initial_interval_float, final_interval_float ) ),2))/real_integral(initial_interval_float, final_interval_float) ) ;

}
