#include <stdio.h>
#include <math.h>

struct complex{
	double r;
	double i;
};

int main()
{
	struct complex z1, z2;
	struct complex compexp(struct complex);

	z1.r = 0.0;
	z1.i = 0.0;
	scanf("%lf %lf", &z1.r, &z1.i);

	z2 = compexp(z1);

	printf("[%f, %f] exp:[%f, %f]\n", z1.r, z1.i, z2.r, z2.i);
}

struct complex compexp(struct complex z)
{
	float r = z.r;
	float i = z.i;
	z.r = exp(r) * cos(i);
	z.i = exp(r) * sin(i);

	return z;
}