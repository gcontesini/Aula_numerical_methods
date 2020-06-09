// metodos da bissecao
// 0 - escolha um ponto
/* 1 - enquanto( tolerancia_atual >= tolerancia_desejada ): ]
     calcule x(i+1)=x(i)-(funcao( x(i) )/(funcao'( x(i) ))) */

#include"stdio.h"  
#include"math.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Main
double main()
{

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Declaracao de Variaveis
  double ponto_inicial_double,tolerancia_double                                 ;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Prototipo de Funcao
  double funcao( double num_double )                                            ;
  double derivada( double num_double )                                          ;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Input
  ponto_inicial_double = 4                                                      ;
  tolerancia_double = 1e-8                                                      ;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Logica
  do
  {  
    ponto_inicial_double = ponto_inicial_double -(funcao(ponto_inicial_double)/ \
      derivada( ponto_inicial_double )            )                             ;
      
  }while( 
    fabs( funcao( ponto_inicial_double) ) > tolerancia_double
  )                                                                             ;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Output
  printf("raiz:%lf\n", ponto_inicial_double )                                   ;                                        
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Funcao
double funcao( double num_double )
{
  return ( num_double * num_double ) - 4                                        ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Derivada
double derivada( double num_double )
{
  return 2*num_double                                                           ;
}
