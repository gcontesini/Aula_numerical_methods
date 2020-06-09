#include<stdio.h>
#include<math.h>

main()
{
  int t;
  double x, fx, sum, pi;

  pi=atan(1)*4;
  x=pi/6;
  sum=fx=x;

  for (t=1; t<100; t++)
  {
    fx*=(-1)*(x*x)/(float)((2.*t)*(2.*t+1));
    sum+=fx;
    printf("%d\t %.16e\t %.16e\n", t, sum, fx);
  }
}
