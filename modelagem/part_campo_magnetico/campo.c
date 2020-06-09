#include"stdio.h"
#include"math.h"
#include"stdlib.h"
#define q -1.602e-19
#define m 9.109e-31

void boris(double vx,double vy,double vz,double ex,double ey,double ez,double bx,double by,double bz,double deltat)
{
	double vxm,vym,vzm;
	double vxline,vyline,vzline;
	double vxp,vyp,vzp;
	double sx,sy,sz;
	double tx,ty,tz,t;
	double vxt,vyt,vzt;
	double vxs,vys,vzs;
	//----------------------------------
	tx=q/m*bx*0.5*deltat;
	ty=q/m*by*0.5*deltat;
	tz=q/m*bz*0.5*deltat;
	//----------------------------------
	t=tx*tx+ty*ty+tz*tz;
	//----------------------------------
	sx=2*tx/(1+t);
	sy=2*ty/(1+t);
	sz=2*tz/(1+t);
	//----------------------------------
	vxm=vx+q/m*ex*0.5*deltat;
	vym=vy+q/m*ey*0.5*deltat;
	vzm=vy+q/m*ez*0.5*deltat;
	//----------------------------------
	vxt=vym*tz-vzm*ty;
	vyt=-vxm*tz+vzm*tx;
	vzt=vxm*ty-vym*tx;
	//----------------------------------
	vxm=vx+q/m*ex*0.5*deltat;
	vym=vy+q/m*ey*0.5*deltat;
	vzm=vy+q/m*ez*0.5*deltat;
	//----------------------------------	
	vxline=vxm+vxt;
	vyline=vym+vyt;
	vzline=vzm+vzt;
	//----------------------------------
	vxs=vyline*sz-vzline*sy;
	vys=-vxline*sz+vzline*sx;
	vzs=vxline*sy-vyline*sx;
	//----------------------------------
	vxp=vxm+vxs;
	vyp=vym+vys;
	vzp=vzm+vzs;
	//----------------------------------
	vx=vxp+(q/m*ex*0.5*deltat);
	vy=vyp+(q/m*ey*0.5*deltat);
	vz=vzp+(q/m*ez*0.5*deltat);
}

main()
{
	double dt,t,r;
	double x,vx,ex,bx,y,vy,ey,by,z,vz,ez,bz;

	//constantes

	dt=3e-5;		//variação de tempo

	//Campo Magnetico

	bx=0.;
	by=0.;
	bz=0.1;

	//Campo Eletrico

	ex=0.;
	ey=0.;
	ez=0.;

	//posição inicial

	x=y=z=0.;		//posição inicial da particula

	//velocidades

	vx=0.;		//velocidade constante em Z
	vy=vz=1e5;		//velocidade inicial em X e em Y if(vx==vz){printf("Circulo");}else{printf("elipse");}

	//Euler posição

	x=x+vx*dt;
	y=y+vz*dt;
	z=z+vz*dt;

	//Raio de Rotação (Raio de Larmor)

	x=(m*vy)/(fabs(q*bz));

	//algoritmo de boris

	boris(vx,vy,vz,ex,ey,ez,bx,by,bz,dt);

	do{
		//algoritmo de boris

		boris(vx,vy,vz,ex,ey,ez,bx,by,bz,-0.5*dt);

		//atualização 

		x=x+vx*dt;
		y=y+vy*dt;
		z=z+vz*dt;

		t=t+dt;
		//printf("set xrange[%d:-%d]\n",abs(r),0);
		//printf("set yrange[%d:-%d]\n",abs(r),0);
		//printf("set zrange[%d:-%d]\n",abs(z),0);
		//printf("splot '-' w p ls 7 lw 8 lc 1\n");
		printf("%lf %lf %lf\n",x,y,z);
		//printf("e\n");
		//printf("Pause 0.5\n");
	}while(z<=10000.);
}
