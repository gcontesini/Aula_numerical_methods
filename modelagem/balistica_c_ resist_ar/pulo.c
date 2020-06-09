#include"stdio.h"
#include"math.h"
#define h 10e3

main()
{
	double k,dt,t,vy,y,g,G,m,r,dr,M,a;		//declaração das variaveis
	t=0.;							//tempo inicial
	vy=0.;							//velocidade inicial
	y=h;								//altura inicial
	dt=1e-3;							//variação do tempo
	m=5.9722e24;						//massa da terra	
	G=6.674287e-11;					//constante gravitcional		
	r=6371e3+h;						//raio da terra	
	dr=1e-3;							//variação da do raio da terra
	M=100;							//massa da pessoal
	do{
		g=G*m/(r*r);					//gravidade
		r-=dr;						//raio da terra
		a=(g*M-(k*vy*vy*1.84*-0.04))/M;	//aceleração do corpo
		vy=vy+a*dt;					//atualização da velocidade
		y=y-vy*dt;					//ataualização da posição
		t+=dt;						//atualização do tempo
		k=((0.085*pow(y/5000,3))+(1.675*pow(y/5000,2))-(10.99*y+24,6))/2.0;	//força de arrasto
		printf("%e\t%e\t%e\t%e\t%e\n",t,y,vy*3.6,k,g);					//impressao dos dados
	}while(y>0.);						//condição de parada
}
