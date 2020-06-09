/*
Sequências
	Poupança
		xt=xo(1+p)^n
			p=10%
		x1=xo(1+0.1)
		x2=x1(1+0.1)=xo(1+0.1)^2

#include<stdio.h>

main()
{
	int t, i;
	double x, p;
	
	p=0.1;
	x=1;
	for(t=1; t<60; t++)
	{
		x=x*(1+p);
		printf("%d %f\n", t, x);
	}
}


S(x)=e^x=somatório de x=0 até n de (x^n)/n!= somatório de x=0 até infinito de f^n (x)
f^n (x) = x^(n-1)/(n-1)! . x/n

#include<stdio.h>

main()
{
  int i;
  double x=1., n=1.;
  for (i=1; i<=100; i++)
  {
    x=x*1./i;
    n=n+x;
    printf("%.16e\n", n);
  }
}

graficos(poupança, e^x, sin(x))

a)pi=atan(1)*4 x->n

b)cos(x), 6 interações, xe[0, pi/2, 0.01] 

cos(x)-cos^6it(x)

*/

#include<stdio.h>
#include<math.h>

main()
{
  int t;
  double x, fx, sum, suma, x0, pi, meio;
  
  pi=atan(1)*4;
  x=x0=pi/6;
  suma=sum=fx=x;
  meio=5e-1;
  
  for (t=1; t<40; t++)
  {
    fx*=(-1)*(x*x)/(float)((2.*t)*(2.*t+1));
    sum+=fx;
    printf("%d\t %.16e\t %.16e\n", t, sum, fx);
  }
}
