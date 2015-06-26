#include <stdio.h>

int main()
{
	double a[3][3], b[3][3];
	int n;
	int invert(double [][3], double [][3]);

	printf("Calculate 3 * 3 invert matrix.\n");
	printf("Input 3 numbers each row deviding by space.\n");
	scanf("%lf %lf %lf", &a[0][0], &a[0][1], &a[0][2]);
	scanf("%lf %lf %lf", &a[1][0], &a[1][1], &a[1][2]);
	scanf("%lf %lf %lf", &a[2][0], &a[2][1], &a[2][2]);

	n = invert(a, b);

	if(n == -1){
		printf("No invert matrix.\n");
	}else if(n == 0){
		printf("Invert matrix of:\n");
		printf("%f %f %f\n", a[0][0], a[0][1], a[0][2]);
		printf("%f %f %f\n", a[1][0], a[1][1], a[1][2]);
		printf("%f %f %f\n", a[2][0], a[2][1], a[2][2]);
		printf("is:\n");
		printf("%f %f %f\n", b[0][0], b[0][1], b[0][2]);
		printf("%f %f %f\n", b[1][0], b[1][1], b[1][2]);
		printf("%f %f %f\n", b[2][0], b[2][1], b[2][2]);
	}
}

int invert(double a[][3], double b[][3])
{
	double d;
	int i, j;

	// サラスの方法で行列式を計算
	d = a[0][0] * a[1][1] * a[2][2] + a[0][1] * a[1][2] * a[2][0] + a[0][2] * a[1][0] * a[2][1]
		- a[0][2] * a[1][1] * a[2][0] - a[0][1] * a[1][0] * a[2][2] - a[0][0] * a[1][2] * a[2][1];
	// <行列式> == 0 なら逆行列無し
	if(d == 0){
		return -1;
	// <行列式> != 0 なら各成分の余因子から逆行列を求める
	}else{
		b[0][0] =  (a[1][1] * a[2][2] - a[1][2] * a[2][1]) / d;
		b[1][0] = -(a[1][0] * a[2][2] - a[1][2] * a[2][0]) / d;
		b[2][0] =  (a[1][0] * a[2][1] - a[1][1] * a[2][0]) / d;
		b[0][1] = -(a[0][1] * a[2][2] - a[0][2] * a[2][1]) / d;
		b[1][1] =  (a[0][0] * a[2][2] - a[0][2] * a[2][0]) / d;
		b[2][1] = -(a[0][0] * a[2][1] - a[0][1] * a[2][0]) / d;
		b[0][2] =  (a[0][1] * a[1][2] - a[0][2] * a[1][1]) / d;
		b[1][2] = -(a[0][0] * a[1][2] - a[0][2] * a[1][0]) / d;
		b[2][2] =  (a[0][0] * a[1][1] - a[0][1] * a[1][0]) / d;
	}
	// -0.0 の見栄えが悪いので修正
	for(i = 0; i <= 2; i++){
		for(j = 0; j <= 2; j++){
			if(b[i][j] == 0){
				b[i][j] = 0.0;
			}
		}
	}
	return 0;
}
