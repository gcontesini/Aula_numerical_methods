#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void PushParticle(double x[],double v[],double dt)
{
	x[0] += v[0]*dt; //atualização na posição x
	x[1] += v[1]*dt; //posição y
	x[2] += v[2]*dt; //posição z
}
void VelocityBoris(double v[], double q[], double m[], double E[], double B[],double dt)
{
	double vminus[3]; // Vdouble
	double vprime[3]; // V' , perpendicular ao campo magnético e a V- e V+
	double vplus[3]; // V+
	double vprimexs[3]; //Produto vetorial V'xS
	double vminusxt[3]; //Produto vetorial V-xt
	double t[3]; //vetor t, vetor do campo magnético
	double s[3]; //vetor s, vetor para manter o módulo do campo magnético constante
	double t_mag2; //módulo do vetor t
	int dim; //dimensão
	/*t vetor*/
	for(dim=0;dim<3;dim++)
		t[dim] = q[0]/m[0]*B[dim]*0.5*dt;//calcula as três componentes do vetor "campo magnético"
	/*módulo de t, ao quadrado*/
	t_mag2 = t[0]*t[0] + t[1]*t[1] + t[2]*t[2]; //módulo do campo magnético
	/*s vetor*/
	for(dim=0;dim<3;dim++)
		s[dim] = 2*t[dim]/(1+t_mag2); //calcula componentes do vetor s
	/*v minus*/
	for(dim=0;dim<3;dim++)
		vminus[dim] = v[dim] + q[0]/m[0]*E[dim]*0.5*dt;
	/*v prime*/
	//double vminusxt[] = CrossProduct(vminus, t); //calcula V', vetor velocidade de rotação antes
	vminusxt[0] = vminus[1]*t[2]-vminus[2]*t[1];
	vminusxt[1] = -vminus[0]*t[2]+vminus[2]*t[0];
	vminusxt[2] = vminus[0]*t[1]-vminus[1]*t[0];
	//
	for(dim=0;dim<3;dim++)
		vprime[dim] = vminus[dim] + vminusxt[dim];
	/*v prime*/
	//double vprimexs[] = CrossProduct(vprime, s); //calcula o vetor velocidade após a rotação
	vprimexs[0] = vprime[1]*s[2]-vprime[2]*s[1];
	vprimexs[1] = -vprime[0]*s[2]+vprime[2]*s[0];
	vprimexs[2] = vprime[0]*s[1]-vprime[1]*s[0];
	for(dim=0;dim<3;dim++)
		vplus[dim] = vminus[dim] + vprimexs[dim];
	/*v t+dt/2*/
	for(dim=0;dim<3;dim++) //calcula as componentes do vetor velocidade V(t+dt/2)
		v[dim] = vplus[dim] + q[0]/m[0]*E[dim]*0.5*dt;
}
main()
{
	double E[3],B[3], x[3], v[3], m[1], q[1], dt=3e-5, rL;
	int it;
	q[0] = -1.602e-19; //carga do elétron
	m[0] = 9.109e-31; //massa do elétron
	x[0] = 0; //posição inicial x
	x[1] = 0; //y
	x[2] = 0; //z
	v[0] = 0; //velocidade inicial Vx
	v[1] = 1e5; //Vy
	v[2] = 1e5; //Vz
	E[0] = 0;//Campo elétrico Ex
	E[1] = 0;//Ey
	E[2] = 0;//Ez
	B[0] = 0;//Campo Magnético Bx
	B[1] = 0;//By
	B[2] = 0.01; //Bz
	/*Cálculo do Raio de Larmor*/
	rL = m[0]*v[1]/(fabs(q[0])*B[2]);
	x[0] = rL;
	/*Calcula V(t-dt/2)*/
	VelocityBoris(v,q,m,E,B,-0.5*dt);
	for (it=0;it<100000;it++)
	{
		VelocityBoris(v,q,m,E,B,-0.5*dt);
		PushParticle(x,v,dt);
		/*A cada 2 passos*/
		if (it%2==0)
			printf("%d %lf %lf %lf %lf %lf %lf %lf\n",it,it*dt,x[0],x[1],x[2],v[0],v[1],v[2]);
	}
}
