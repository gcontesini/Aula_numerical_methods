#include"stdio.h"//Biblioteca padrao;
#define p 20//numeros de termos da serie;
#define d 2.718281828
main ()
{
	float x,s,e;
	int i;
	e=1;//Valor inicial de e(x);
	s=1;//constante;
	x=1;//Variavel x;
	for(i=1;i<p;i++)
	{
		s=(x/i)*s;//expressao geral de cada termo;
		e=e+s;//somatorio;
		printf("%d\t%f\t%e\n",i,e,d-e);
	}
}
