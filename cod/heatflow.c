#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14159265
#define Tmax 30
#define length 100 
#define a 0.2 //condutividade


int main(){

  FILE *saida; 
  saida = fopen("heatflow.dat", "w");//cria um arquivo para ser escrito 
  
  double T[2][length]; // primeiro indice t , t+1  e  temperatura posicao i,
  double time=0, dt=0.1, dx = 0.1;
  int  x;

  //inicializa 
  for(x=0; x<length; x++){
    T[0][x] = 20*exp(-(dx*x)*(dx*x)); //5+ sin(dt*x);//5*exp(-(dx*x-5)*(dx*x-5)); //gausiana
  }


  while(time <= Tmax){
 
       x=1;
       printf("plot [-1:10][0:10] '-' w l \n"); //inicia um grafico

       while(x < length){ //calcula a difusao percorrendo a barra

            T[1][x] = T[0][x] + (dt*a*a)*(T[0][x+1] + T[0][x-1] - 2* T[0][x])/ (dx*dx) ;         

            //imprime o valor calculado
            //fprintf(saida,"%lf %lf %lf \n",time,x ,T[2][x]);

	    printf("%.3lf %.3lf \n",dx*x ,T[1][x]);
      	    x++;

       }
      if(time == 0)      printf(" e pause 1 \n");//config inicial
      else      printf(" e pause 0.7 \n");//end plot mais 1 seg pause    

      //atualiza valores
      for(x=0; x<length; x++){ // corrigir para passa pelo primeiro
	T[0][x] =  T[1][x];
      }
      time+=dt;
      
  }

  fclose(saida);  
}


