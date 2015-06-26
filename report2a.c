#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c;
	double x1, x2;
	int n;
	int resolve(double, double, double, double *, double *);

	printf("Resolve ax^2 + bx + c = 0.\n");
	printf("Input a, b, c dividing by spaces.\n");
	scanf("%lf %lf %lf", &a, &b, &c);

	n = resolve(a, b, c, &x1, &x2);

	if(n == 0){
		printf("x = %f\n", x1);
	}else if(n == 1){
		printf("x = %f, %f\n", x1, x2);
	}else if(n == -1){
		printf("x = %f ± %fi\n", x1, x2);
	}else if(n == 2){
		printf("Input error, or a = 0.\n");
	}
}

int resolve(double a, double b, double c, double *x1, double *x2)
{
	// divide by 0 のエラー防止
	if(a == 0){
		return 2;
	}

	// 判別式と分岐
	double d = b * b - 4.0 * a * c;
	if(d == 0.0){
		*x1 =  -b / (2*a);
		return 0;
	}else if(d > 0.0){
		*x1 = (-b + sqrt(d)) / (2*a);
		*x2 = (-b - sqrt(d)) / (2*a);
		return 1;
	}else if(d < 0.0){
		*x1 = -b / (2*a);
		*x2 = sqrt(-d) / (2*a);
		return -1;
	}
}