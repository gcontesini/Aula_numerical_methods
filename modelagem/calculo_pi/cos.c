#include"stdio.h"//biblioteca padrao;
#include"math.h"//biblioteca de funções matematicas;
#define w 5//numero de termos da expansao;

int fat(int x)//função para calcular o fatorial;
{
	if(x==0)
		return 1;
	x=x*fat(x-1);
	return x;
}

main()
{
//declaração das variaveis , foi usado double para obter uma maior precisao;
	double x,cos,pi;
	int i;
	pi=atan(1)*4;//equação para calcula o valor de Pi;
	x=2*pi;//valor de x ; ex x=90graus=Pi/2;
	cos=0.0;//valor inicial da função sin;
	for(i=0;i<w;i+=1)
		{
		cos+=pow(-1,i)*pow(x,(2*i))/fat(2*i);//somatorio do termos da serie;
		printf("%.4lf\n",cos);
		}
}
