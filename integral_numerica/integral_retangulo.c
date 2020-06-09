#include "stdio.h"
#include "math.h"

#define pi acos(-1.)

main()
{

	float inicio_float, final_float ;
	float raio_maior_float, raio_menor_float ;
	float perimetro_float, integral_float, teta_float, k_float, delta_float ;
	int i_int ;

	inicio_float = 0.0001 ;
	final_float = 2*pi ;
	raio_maior_float = 5. ;
	raio_menor_float = 2. ;
	perimetro_float = 0. ;
	delta_float = 0.001;

	k_float = sqrt(pow(raio_maior_float,2)-pow(raio_menor_float,2))/raio_maior_float ;
	
	integral_float = 0. ;
	teta_float = inicio_float ; 

	while( teta_float<= final_float )
	{
		integral_float = integral_float + sqrt(1-(pow(k_float,2)*sin(teta_float)*sin(teta_float)));
		teta_float = teta_float + delta_float ;
	}	

	perimetro_float = raio_maior_float * delta_float * integral_float ;

	//printf("%lf\n",pi);
	//printf("%lf\n",k_float);
	printf("%lf\n",perimetro_float);
}

