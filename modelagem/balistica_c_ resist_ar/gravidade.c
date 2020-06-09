#include"stdio.h"
#define h 10e3
double gravidade()
{
	double a,G,m,r,dr;

	do{
		a=G*m/(r*r);
		r-=dr;
		printf("%lf\t%lf\n",r-6371e3,a);
	}while(r>=6371e3);
}
