#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DISTANCIA 1009
#define PASSOS 1000
#define NUMERO 100

int main()
{
	srand(time(NULL));

	int casa=DISTANCIA, bebados[NUMERO], i, passo, posicaob[DISTANCIA], posicao;

	for(i=0;i<NUMERO;i++)
	{
		bebados[i]=0;
		posicaob[i]=0;
	}
	for(i=0;i<PASSOS;i++)
	{
		passo=(rand()%2);
		
		if(passo==1 && bebados[i]!=casa)
		{
			bebados[i]++;
		}else if (passo!=1 && bebados[i]!=casa) bebados[i]--;
	}
	for(i=0;i<NUMERO;i++)
	{
		posicao=bebados[i];
		posicaob[posicao]++;
	}

	for(i=0;i<DISTANCIA;i++)
	{
		printf("\nPosicao: %d, Bebados: %d", i, posicaob[i]);
	}
	printf("\n");
}
		








