/*
#include"stdio.h"
#include"math.h"
main()
{
	double x=.5,y=0.1;
	do{
		x=x-(((x*x*x)-(2*x*x)+(11*x)+12)/((3*x*x)-(4*x)+11));
		y=(x*x*x)-(2*x*x)+(11*x)+12);
		printf("%e\t%e\n",x,y);
	}while(fabs(y)>10e-6);
}
*/
/*f(x)=x**3-2*x**2+11*x+12

x=-3 x=4 x=1

dom(x)=[-10,10] precisao 10**-8 passo 10**-3
((x³)-(2*x²)+(11*x)+12 x=4=1=-3
começando pra dado ponto que raiz dara?*/

#include"stdio.h"
#include"math.h"
main()
{
	double x,y=.01;
	for(x=10.;x>=-10.;x=-0.001)
	{
		do{
			x=x-(((x*x*x)-(2*x*x)-(11*x)+12)/((3*x*x)-(4*x)-11));
			y=((x*x*x)-(2*x*x)-(11*x)+12);
			printf("%e\t%e\n",x,y);
		}while(fabs(y)>10e-8);
	}
}
