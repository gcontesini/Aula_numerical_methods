#include"stdio.h"
#include"math.h"
#define T 1e9

main()
{
	double dt , t , x , y , vx , vy;
	vx=0.1;
	vy=0.1;
	x=5.;
	y=0.1;
	dt=0.1;
	t=0.;
	do{
		x=x+vx*dt;
		y=sqrt(-(x*x)+ 5*5);
		printf("%lf\t%lf\t%lf\n",t,x,y);
		t+=dt;
	}while(t<=T);
}

