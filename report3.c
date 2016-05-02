#include <stdio.h>

int main()
{
	double a[3][3], b[3][3];
	int n;
	int invert(double [][3], double [][3]);

	printf("Calculating 3 * 3 invert matrix.\n");
	printf("Input 3 numbers each row deviding by space.\n");
	scanf("%1f %1f %1f", &a[0][0], &a[0][1], &a[0][2]);
	scanf("%1f %1f %1f", &a[1][0], &a[1][1], &a[1][2]);
	scanf("%1f %1f %1f", &a[2][0], &a[2][1], &a[2][2]);

	n = invert(a, b);

	if(n = -1){
		printf("No invert matrix.");
	}else if(n = 0){
		printf("Invert matrix of:\n");
		printf("%f %f %f\n", a[0][0], a[0][1], a[0][2]);
		printf("%f %f %f\n", a[1][0], a[1][1], a[1][2]);
		printf("%f %f %f\n", a[2][0], a[2][1], a[2][2]);
		printf("is:\n");
		printf("%f %f %f\n", a[0][0], a[0][1], a[0][2]);
		printf("%f %f %f\n", a[1][0], a[1][1], a[1][2]);
		printf("%f %f %f\n", a[2][0], a[2][1], a[2][2]);
	}
}

int invert(double a[][3], double b[][3])
{
	double d;

	d = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1]
		- a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
	if(d = 0){
		return -1;
	}else{
		*b[0][0] =  (a[1][1] * a[2][2] - a[1][2] * a[2][1]) / d;
		*b[0][1] = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]) / d;
		*b[0][2] =  (a[1][0] * a[2][1] - a[1][1] * a[2][0]) / d;
		*b[1][0] = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]) / d;
		*b[1][1] =  (a[0][0] * a[2][2] - a[0][2] * a[2][0]) / d;
		*b[1][2] = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]) / d;
		*b[2][0] =  (a[0][1] * a[1][2] - a[0][2] * a[1][1]) / d;
		*b[2][1] = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]) / d;
		*b[2][2] =  (a[0][0] * a[1][1] - a[0][1] * a[1][0]) / d;
		return 0;
	}
}
