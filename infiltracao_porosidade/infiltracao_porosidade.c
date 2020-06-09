/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Programa que tem como objetivo estudar o comportamento de uma 
infiltracao
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include "stdio.h"
#include "math.h"

#define pedra_def 0
#define parede_def 1
#define liquido_def 2

#define size_x_int 50
#define size_y_int 50

#define numero_simulacao_int 1

unsigned r_uint = 6611505 ;

struct celula_psl
{
  int real_status_int ;
  int next_status_int ;
  float random_prob_float ;
} ;

float conti_random( ) ;
void new_matrix( struct celula_psl rede_matrix[size_x_int][size_y_int] ) ;
void print_matrix( struct celula_psl rede_matrix[size_x_int][size_y_int] ) ;
void infiltracao( struct celula_psl rede_matrix[size_x_int][size_y_int] ) ;
// void stats(                               \
//   int rede_matrix[size_x_int][size_y_int],\
//   int stats_vector[fogo_int]              \
// ) ;

FILE *output, *status ;



main()
{

   int i_int ; 
  struct celula_psl infiltracao_matrix[ size_x_int ][size_y_int ] ;

  status = fopen("status.txt", "w") ;
  output = fopen("infiltracao.txt", "w") ;


  if ( status == NULL )
  {
    printf("Can't open output file status.txt !\n") ;
  }

  if (output == NULL )
  {
    printf("Can't open output file forest.txt !\n") ;
  }

  new_matrix( infiltracao_matrix ) ;
  print_matrix( infiltracao_matrix ) ;
  infiltracao( infiltracao_matrix) ;

  // for(i_int=0; i_int < numero_simulacao_int; i_int++)
  // {
  
  // }

  // fclose( output ) ;
  // fcloase( status ) ;
  printf("End of program!\n") ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~RAND()

float conti_random(  )
{
  unsigned seed_uint, max_uint ;
  
  max_uint  = pow(2,32)-1 ;
  seed_uint = 1612312361 ;
  r_uint = r_uint * seed_uint ;

  return (float)(r_uint)/(float)max_uint ; 
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CRIACAO DA REDE

void new_matrix( struct celula_psl rede_matrix[size_x_int][size_y_int] )
{
  int i_int , j_int ;

  for(i_int=0 ; i_int < size_x_int ; i_int++)
  {
    for(j_int=0; j_int < size_y_int ; j_int++)
    {
      if( i_int == 0 || i_int == size_x_int-1 )
      {
        rede_matrix[i_int][j_int].random_prob_float = parede_def ;
        rede_matrix[i_int][j_int].real_status_int = parede_def ;
      }
      else if( j_int == 0 || j_int == size_y_int-1 )
      {
        rede_matrix[i_int][j_int].random_prob_float = parede_def ;
        rede_matrix[i_int][j_int].real_status_int = parede_def ;
      }
      else
      {
        rede_matrix[i_int][j_int].random_prob_float = conti_random() ;
        rede_matrix[i_int][j_int].real_status_int = pedra_def ;
        rede_matrix[i_int][j_int].next_status_int = pedra_def ;
      }
    }
  }
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~STATS

// void stats( int rede_matrix[size_x_int][size_y_int], int stats_vector[fogo_int])
// {
//   int i_int, j_int, k_int                                                      ;

//   for(i_int=0; i_int<=fogo_int; i_int++)
//   {
//     stats_vector[i_int] = 0                                                    ;
//   }

//   for( i_int=0; i_int<size_x_int; i_int++ )
//   {
//     for( j_int=0; j_int<size_y_int; j_int++ )
//     {
//       for( k_int=0; k_int<=fogo_int; k_int++ )
//       {
//         if( rede_matrix[i_int][j_int] == k_int )
//         {
//            stats_vector[k_int] ++                                              ;
//         }
//       }
//     }
//   }
//   for(i_int=0; i_int<=fogo_int; i_int++ )
//   {
//     fprintf(status, "%d\t\t  ", stats_vector[i_int] )                            ;
//   }
//   fprintf(status,"\n" )                                                        ;
// }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PRINT MATRIX

void print_matrix( struct celula_psl rede_matrix[size_x_int][size_y_int] )
{
  int i_int, j_int ;

  for( i_int=0 ; i_int < size_x_int ; i_int++ )
  {
    for( j_int=0; j_int < size_y_int ; j_int++ )
    {
      if(j_int == size_y_int-1 )
      {
        printf("%d\n",rede_matrix[i_int][j_int].real_status_int ) ;
        // printf("%lf\n",rede_matrix[i_int][j_int].random_prob_float ) ;
        // fprintf(output,"%d\n",rede_matrix[i_int][j_int].real_status_int ) ;
      }
      else
      {
        printf("%d ",rede_matrix[i_int][j_int].real_status_int ) ;
        // printf("%lf ",rede_matrix[i_int][j_int].random_prob_float ) ;
        // fprintf(output,"%d  ",rede_matrix[i_int][j_int].real_status_int ) ;
      }
    }
  }
  printf("\n");
  // fprintf(output,"\n") ;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~INFILTRACAO

void infiltracao( struct celula_psl rede_matrix[size_x_int][size_y_int] )
{
  int i_int, j_int, time_int ;

  for( j_int=1; j_int < size_y_int-1; j_int++)
  {
    rede_matrix[1][j_int].next_status_int = liquido_def ;
    rede_matrix[1][j_int].random_prob_float = 1. ;
  }
  
  // stats( rede_matrix, stats_vector ) ;
  print_matrix( rede_matrix ) ;
 
  for( time_int=0; time_int<50; time_int++ )
  {
    for( i_int=1 ; i_int < size_x_int-1; i_int++ )
    {
      for( j_int=1; j_int < size_y_int-1; j_int++ )
      {

        rede_matrix[ i_int ][ j_int ].real_status_int =\
        rede_matrix[ i_int ][ j_int ].next_status_int ;

        if( rede_matrix[i_int][j_int].real_status_int == pedra_def )
        {

          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Von Newman neighborhood

          if( rede_matrix[ i_int-1 ][ j_int ].random_prob_float       >=\
            rede_matrix[ i_int ][ j_int ].random_prob_float           &&\
            rede_matrix[i_int-1][j_int].real_status_int == liquido_def )
          {
            rede_matrix[ i_int ][ j_int ].next_status_int = liquido_def ;
          }
          // else if( rede_matrix[ i_int + 1 ][ j_int  ].random_prob_float >=\
          //  rede_matrix[ i_int ][ j_int ].random_prob_float )
          // {
          //   rede_matrix[ i_int ][ j_int ].next_status_int = liquido_def;
          // }
          else if( rede_matrix[ i_int ][ j_int - 1 ].random_prob_float  >=\
            rede_matrix[ i_int ][ j_int ].random_prob_float             &&\
            rede_matrix[i_int][j_int-1].real_status_int == liquido_def )
          {
            rede_matrix[ i_int ][ j_int ].next_status_int = liquido_def;
          }
          else if( rede_matrix[ i_int ][ j_int + 1 ].random_prob_float  >=\
            rede_matrix[ i_int ][ j_int ].random_prob_float             &&\
            rede_matrix[i_int][j_int+1].real_status_int == liquido_def )
          {
            rede_matrix[ i_int ][ j_int ].next_status_int = liquido_def;
          }

          //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~Morre neighborhood
          // if( rede_matrix[ i_int-1 ][ j_int-1 ] == fogo_int )
          // {
          //   rede_matrix[ i_int ][ j_int ] = faisca_int ;
          // }
          // else if( rede_matrix[ i_int-1 ][ j_int+1 ] == fogo_int )
          // {
          //   rede_matrix[ i_int ][ j_int ] = faisca_int ;
          // }
          // else if( rede_matrix[ i_int+1 ][ j_int-1 ] == fogo_int )
          // {
          //   rede_matrix[ i_int ][ j_int ] = faisca_int;
          // }
          // else if( rede_matrix[ i_int+1 ][ j_int+1 ] == fogo_int )
          // {
          //   rede_matrix[ i_int ][ j_int ] = faisca_int;
          // }       
        }
      }
    }
    print_matrix( rede_matrix ) ;
  }
  // stats( rede_matrix, stats_vector ) ;
}