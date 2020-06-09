#include"stdio.h"
#include"math.h"

double f(double x) //função f(x);
{
	return (x*x*x*x)*sin(x);
}

double dfsec(double xc, double xb)//função derivada;
{
	return (f(xb)-f(xc))/(xb-xc);
}

main()
{
	double xb=4; //valor inicial de x2
	double xa; //metodo newton-rapshon
	double xc=3; //valor inicial de x1
	double precisao=1e-10; //precisao
	double h=1e-4; //variação infinitesimal
	do {
		xa=xb-f(xb)/dfsec(xb,xc);		
		xc=xb;		
		xb=xa;
	}while (fabs(f(xa))>precisao);
	printf("%.10e %.10e \n",xa,f(xa));	
}
