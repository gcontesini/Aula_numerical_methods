#include"stdio.h"
#include"math.h"
main(float argc, char *argv[])
{
	double k,vx,vy,v,x,y,t,dt,o,ang,pi,g; 	//declaração das variaveis
	g=9.8;							//gravidade
	pi=4*atan(1.);						//valor de pi
	k=atof(argv[2]);					//constante de resistividade do ar
	ang=atoi(argv[1]);					//angulo em graus
	v=10.;							//velocidade inicial
	o=(pi*ang/180);					//conversão de graus para radianos
	vx=v*cos(o);						//componente vertical da velocidade inicial
	vy=v*sin(o);						//componente horizontal da velocidade inicial
	y=x=0.;
	t=0.;							//posição e tempo iniciais
	dt=1e-3;							//variação do tempo a cada passo
	do{
		vx=vx-k*vx*dt;					//calculo da velocidade horizontal 
		x=x+vx*dt;					//calculo da posição horizontal
		vy=vy-(g+k*vy)*dt;				//calculo da velocidade vertical
		y=y+vy*dt;					//calculo da posição vertical
		t+=dt;						//atualização do tempo
		printf("%lf\t%lf\t%lf\n",t,x,y,vx,vy);
	}while(y>=0);						//condição de parada do laço
}
