/*sec(x)=derivada=(f(x1)-f(x2))/(x1-x2)

xn=xn-1-(f(xn-1)((xn-2)-(xn-1)))/(f(xn-2)-f(xn-1))*/

#include"stdio.h"
#include"math.h"

double f(double x) //função f(x);
{
	return x*x-5;
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


/*

casa;

x⁴.sin(x)=0
x⁴=sin(x)
tanh(beta.x)=x	beta=1,5,10
z³=1 z(complexo)
ex:
z=x[0]+i*[1]
z1+z2=x1[1]+x2[1]+x1i[1]+x2i[1]
