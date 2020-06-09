// metodos da bissecao
// 0 - escolha o intervalo ponto_a e ponto_b tal que( f(ponto_a)*f(ponto_b) < 0 )
// 1 - calcular a raiz da reta
// 2 - calcular f("media")
// 3 - if( ( ponto_a - "media" ) < tolerancia ): break
// 4 - if( f("media")*F("a") < 0 ): "b" = "media" else: "a" = "media"

#include"stdio.h"  
#include"math.h"
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Main
float main()
{

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Declaracao de Variaveis
  int   interacoes_int, i_int                                                   ;
  float ponto_a_float, ponto_b_float, raiz_float, novo_ponto_float              ;
  float tolerancia_ideal_float, tolerancia_atual_float                          ;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Prototipo de Funcao
  float funcao( float num_float)                                                ;
  float raiz_da_reta( float pnt_a_float, float pnt_b_float )                    ;
  float tolerancia( float pnt_a_float, float pnt_b_float )                      ;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Input
  interacoes_int = 1000                                                         ;
  ponto_a_float = 2                                                             ;
  ponto_b_float = 3                                                             ;
  tolerancia_ideal_float = 0.00001                                              ;
  i_int = 0                                                                     ;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Logica
  do{

    if( funcao( ponto_a_float ) * funcao( ponto_b_float ) > 0 )
    {
      break                                                                     ;
    }
    else
    {
      novo_ponto_float = raiz_da_reta( ponto_a_float, ponto_b_float)            ;
      tolerancia_atual_float = tolerancia( ponto_a_float, ponto_b_float )       ;

      if( tolerancia_atual_float <= tolerancia_ideal_float )
      {
        break                                                                   ;
      }

      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Logica Principal
      if( funcao(ponto_a_float)*funcao(novo_ponto_float) < 0 )
      {
        ponto_b_float = novo_ponto_float                                        ;
      }
      else
      {
        ponto_a_float = novo_ponto_float                                        ;
      }

    }
    i_int ++                                                                    ;
  }while( i_int <= interacoes_int )                                             ;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Output
  printf("raiz:%f\n",novo_ponto_float )                                         ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Funcao
float funcao( float num_float )
{
  return ( 8-4.5*( num_float - sin( num_float ) ) )                             ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Media
float raiz_da_reta( float pnt_a_float, float pnt_b_float )
{
  return ( pnt_a_float*funcao(pnt_b_float) - pnt_b_float*funcao(pnt_a_float) ) /\
    ( funcao(pnt_b_float) - funcao(pnt_a_float) )                              ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Tolerancia
float tolerancia( float pnt_a_float, float pnt_b_float )
{
  return ( ( pnt_b_float - pnt_a_float )/2 )                                    ;
}
