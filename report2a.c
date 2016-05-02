#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	double x1, x2;
	int n;
	int resolve(double, double, double, double *, double *);

	printf("Resolving ax^2 + bx + c = 0.\n");
	printf("Input a, b, c divide by spaces.\n");
	scanf("%1f, %1f, %1f", a, b, c);

	n = resolve(a, b, c, &x1, &x2);

	if(n == 0){
		printf("x = %f\n", x1);
	}else if(n == 1){
		printf("x = %f, %f\n", x1, x2);
	}else if(n == -1){
		printf("x = %f ± %fi\n", x1, x2);
	}
}

int resolve(double a, double b, double c, double *x1, double *x2)
{
	double d = b * b - 4.0 * a * c;

	if(d == 0.0){
		*x1 =  -b / 2a;
		return 0;
	}else if(d > 0.0){
		*x1 = (-b + sqrt(d)) / 2a;
		*x2 = (-b - sqrt(d)) / 2a;
		return 1;
	}else if(d < 0.0){
		*x1 = -b / 2a;
		*x2 = sqrt(-d) / 2a;
		return -1;
	}
}