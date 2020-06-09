#include <stdio.h>
#include <math.h>
#define MAX 10


main()
{
  unsigned i, semente, R, y, x, maxnum;  // unsigned = somentes numeros positivos
  float num, fx, x1, y1, g, mi, PI;  

  semente = 8123197;
  R = 7312345;
  maxnum = pow(2,32) - 1;
  mi = 0.;
  PI = acos(-1);
 
  x = 7312345;
  y = 8569742;
/*
  printf("\tSEM INTERVALO \n");
  for(i=0; i<5; i++)
   {
 		 R = R*semente;
	   printf("%u \n", R);
   }
*/
///////////////////////////////////////////////////////////////////////////

 // printf("\tINTERVALO [0,1] \n");
/*  for(i=0; i<1000000; i++)     //// se varrer todo o espaço, nos diz q os numeros ESTAO de fato aleatorios e nao estao tendendo a nenhum numero 
   {
 		 R = R*semente;
		 num = (float)R / maxnum;
	   printf("%f \t", num);
  
     R = R*semente;
		 num = (float)R / maxnum;
	   printf("%f \n", num);
   }
*/
//////////////////////////////////////////////////////////////////////////

/*
  for(i=0; i<10000; i++)     
   {
 		 x = x*semente;
		 x1 = (float)x / maxnum;

     y = y*semente;
		 y1 = (float)y / maxnum;

     fx = pow(x1,2);

     if(y1 <= fx)
	       printf("%f\t%f \n", MAX*x1,MAX*y1);   /// quando eu quero aumentar o intervalo [0:100] multiplica por esse maior numero
   }
*/
//////////////////////////////////////////////////////////////////////////

  for(i=0; i<100; i++)     
   {
 		 x = x*semente;
		 x1 = (float)x / maxnum;

     y = y*semente;
		 y1 = (float)y / maxnum;

     fx = (1./sqrt(0.2)*sqrt(2.*PI))*exp((-x1*x1)/2.*0.2);
 
     if(y1 <= fx)
	       printf("%f\t%f \n", x1,y1);  
   }

/// refazer o de cima


















}
