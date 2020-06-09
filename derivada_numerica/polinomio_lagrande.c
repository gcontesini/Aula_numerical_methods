#include"stdio.h"
#include"math.h"
#define h_float 

/*
f->x : 2**x/2
derivadas 1 e 2 
a) x=1,8; 2; 2,2;
b) x=1,9; 2; 2,1;

erros:
derivadas em x=2 
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN

main()
{

  float x_float ;
  float erro_float, delta_float ;

  x_float = 2 ;
  delta_float = 0.01 ;

  float fatorial( float num_float ) ;
  float funcao( float x_float ) ;

  float derivada_1_progressiva( float x_float, float delta_float ) ;
  float derivada_1_regressiva( float x_float, float delta_float ) ;
  float derivada_1_central( float x_float, float delta_float ) ;

  float derivada_2_progressiva( float x_float, float delta_float ) ;
  float derivada_2_regressiva( float x_float, float delta_float ) ;
  float derivada_2_central( float x_float, float delta_float ) ;

  float taylor_progressiva( float x_float ) ;
  float taylor_regressiva( float x_float ) ;
  float taylor_central( float x_float) ;

  printf("derivada a primeira progressiva em (x = 2):%f\n",derivada_1_progressiva( x_float , delta_float ) );
  printf("derivada a primeira regressiva em (x = 2):%f\n",derivada_1_regressiva( x_float , delta_float ) );
  printf("derivada a primeira central em (x = 2):%f\n",derivada_1_central( x_float , delta_float ) );
  
  printf("derivada a segunda progressiva em (x = 2):%f\n",derivada_2_progressiva( x_float , delta_float ) );
  printf("derivada a segunda regressiva em (x = 2):%f\n",derivada_2_regressiva( x_float , delta_float ) );
  printf("derivada a segunda central em (x = 2):%f\n",derivada_2_central( x_float , delta_float ) );

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Funcao

float funcao( float x_float )
{
	return pow(2,x_float)/x_float ;
}

float fatorial( float num_float )
{
	if( num_float <= 1)
	{
		return 1 ;
	}
	else
	{
		return num_float*fatorial(num_float-1) ;
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~derivada a primeira

float derivada_1_progressiva( float x_float, float delta_float )
{
	return (-3*funcao( x_float )+4*funcao( x_float + delta_float )-funcao( x_float+2*delta_float ) )/(2*delta_float) ;
}

float derivada_1_regressiva( float x_float, float delta_float )
{
	return ( funcao(x_float-(2*delta_float))-4*funcao(x_float-delta_float)+3*funcao(x_float) )/(2*delta_float) ;
}

float derivada_1_central( float x_float, float delta_float )
{
	return ( funcao( x_float-(2*delta_float) )-8*funcao( x_float-delta_float )+8*funcao( x_float+delta_float )-funcao(x_float+(2*delta_float)) )/(12*delta_float) ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~derivadas a segunda

float derivada_2_progressiva( float x_float, float delta_float)
{
   return ( funcao(x_float)-(2*funcao(x_float+delta_float))+funcao( x_float+(2*delta_float) ) )/( pow(delta_float,2) ) ;
}

float derivada_2_regressiva( float x_float, float delta_float)
{
   return (funcao(x_float-(2*delta_float))-(2*funcao(x_float-delta_float))+funcao(x_float))/( pow(delta_float,2) ) ;
}

float derivada_2_central( float x_float, float delta_float)
{
   return (funcao(x_float-delta_float)-(2*funcao(x_float))+funcao(x_float+delta_float))/(pow(delta_float,2)) ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Taylor

float taylor_progressiva( float intervalo_inicial_float, float intervalo_final_float )
{
  int contador_int ;
  
  float pontos_float, delta_float ;
  float pontos_vector[ (int)( intervalo_inicial_float - intervalo_final_float ) ] ;
  
  pontos_float = intervalo_inicial_float ;
  contador_int = 0 ;
  
  while( contador_int <= (int)( intervalo_inicial_float - intervalo_final_float ) )
  {
	  pontos_vector[ pontos_float ] = (
		  funcao( (float)i_int ) + \
		  (
			  derrivada_1_progressiva(  , delta_float ) * \
			  delta_float/ fatorial( 1 ) 
		  ) + \
		  (
			  derrivada_2_progressiva( x_float, erro_float ) * \
			  pow( h_float , 2 )/fatorial( 2 )
		  )
	  );
	  contador++ ;
	  pontos_float = pontos_float + delta_float ;
	}
	return pontos_vector
}

/*float taylor_regressiva( float x_float, float delta_float )*/
/*{*/
/*	return funcao(x_float) + \*/
/*	derivada_1_regressiva( x_float, erro_float ) * \*/
/*	h_float/ fatorial(1) */
/*}*/

/*float taylor_central( float x_float, float delta_float )*/
/*{*/
/*	return */
/*}*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~END
