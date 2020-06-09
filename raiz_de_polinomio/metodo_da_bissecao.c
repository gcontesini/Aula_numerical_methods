// metodos da bissecao
// 0 - escolha o intervalo ponto_a e ponto_b tal que ( ponto_a*ponto_b < 0 )
// 1 - calcular a media dos pontos "media"= ( ponto_a + ponto_b )*0.5
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
  float ponto_a_float, ponto_b_float, raiz_float, media_float                   ;
  float tolerancia_ideal_float, tolerancia_atual_float                          ;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Prototipo de Funcao
  float funcao( float num_float)                                                ;
  float media( float pnt_a_float, float pnt_b_float )                           ;
  float tolerancia( float pnt_a_float, float pnt_b_float )                      ;
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Input
  ponto_a_float = 1                                                             ;
  ponto_b_float = 2                                                             ;
  tolerancia_ideal_float = 0.001                                                ;
  i_int = 0                                                                     ;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Logica
  do{

    if( funcao( ponto_a_float ) * funcao( ponto_b_float ) > 0 )
    {
      break                                                                     ;
    }

    else
    {
      media_float = media( ponto_a_float, ponto_b_float)                        ;
      tolerancia_atual_float = tolerancia( ponto_a_float, ponto_b_float )       ;

      if( tolerancia_atual_float <= tolerancia_ideal_float )
      {
        break                                                                   ;
      }
      
      //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Logica Principal
      if( funcao(ponto_a_float)*funcao(media_float) < 0 )
      {
        ponto_b_float = media_float                                             ;
      }
      
      else
      {
        ponto_a_float = media_float                                             ;
      }

    }

  }while( i_int <= interacoes_int )                                             ;

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Output
  printf("raiz:%f\n",media_float )                                              ;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Funcao
float funcao( float num_float )
{

  return ( pow( num_float, 3 ) - num_float - 2 )                                 ;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Media
float media( float pnt_a_float, float pnt_b_float )
{

  return ( ( pnt_a_float + pnt_b_float ) * 0.5 )                                ;

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Tolerancia
float tolerancia( float pnt_a_float, float pnt_b_float )
{

  return ( ( pnt_b_float - pnt_a_float )/2 )                                    ;

}
