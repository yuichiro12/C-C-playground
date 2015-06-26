#include <stdio.h>

#define DIM 2
#define MAX 15

struct complex{
	double r;
	double i;
};

int main()
{
	struct complex a[DIM][DIM], b[DIM][DIM];
	void shokishori(struct complex[][DIM]);
	void matexp(struct complex[][DIM], struct complex[][DIM]);
	void shutsuryoku(struct complex[][DIM], struct complex[][DIM]);

	shokishori(a);
	matexp(a, b);
	shutsuryoku(a, b);
}

// 入力
void shokishori(struct complex a[][DIM])
{
	printf("Input 2 pairs of complexes(real part and imaginary part) for each row deviding by spaces.\n");
	scanf("%lf %lf %lf %lf", &a[0][0].r, &a[0][0].i, &a[0][1].r, &a[0][1].i);
	scanf("%lf %lf %lf %lf", &a[1][0].r, &a[1][0].i, &a[1][1].r, &a[1][1].i);
}

// 出力
void shutsuryoku(struct complex a[][DIM], struct complex b[][DIM])
{
	printf("Exp of\n");
	printf("[%f, %f] [%f, %f]\n", a[0][0].r, a[0][0].i, a[0][1].r, a[0][1].i);
	printf("[%f, %f] [%f, %f]\n", a[1][0].r, a[1][0].i, a[1][1].r, a[1][1].i);
	printf("is\n");
	printf("[%f, %f] [%f, %f]\n", b[0][0].r, b[0][0].i, b[0][1].r, b[0][1].i);
	printf("[%f, %f] [%f, %f]\n", b[1][0].r, b[1][0].i, b[1][1].r, b[1][1].i);
}

// aのexpを計算、bにセットして返る
void matexp(struct complex a[][DIM], struct complex b[][DIM])
{
	int n;
	struct complex dummy[DIM][DIM];
	void setone(struct complex[][DIM]);
	void nkome(struct complex[][DIM], struct complex[][DIM], int);
	void mattasu(struct complex[][DIM], struct complex[][DIM]);

	// bを単位行列にする
	setone(b);
	for(n = 1; n <= MAX; n++){
		nkome(a, dummy, n);
		mattasu(b, dummy);
	}
}

void setone(struct complex a[][DIM])
{
	// aを単位行列にして返る
	a[0][0].r = 1;
	a[0][0].i = 0;
	a[0][1].r = 0;
	a[0][1].i = 0;
	a[1][0].r = 0;
	a[1][0].i = 0;
	a[1][1].r = 1;
	a[1][1].i = 0;
}

void mattasu(struct complex a[][DIM], struct complex b[][DIM])
{
	// a = a + b を計算して返る
	a[0][0].r += b[0][0].r;
	a[0][0].i += b[0][0].i;
	a[0][1].r += b[0][1].r;
	a[0][1].i += b[0][1].i;
	a[1][0].r += b[1][0].r;
	a[1][0].i += b[1][0].i;
	a[1][1].r += b[1][1].r;
	a[1][1].i += b[1][1].i;
}

void nkome(struct complex a[][DIM], struct complex kotae[][DIM], int n)
{
	int i, j;
	double k;
	struct complex temp[DIM][DIM];
	void matkakeru(struct complex [][DIM], struct complex [][DIM], struct complex [][DIM]);
	void matcopy(struct complex [][DIM], struct complex [][DIM]);
	unsigned long int kaijo(int);

	// kotae に a をそのままコピー
	matcopy(kotae, a);
	if(n == 1){
		return;
	}
	for(i = 2; i <= n; i++){
		// kotae * a を temp に代入
		matkakeru(kotae, a, temp);
		matcopy(kotae, temp);
	}

	k = (double) kaijo(n);
	for(i = 0; i < DIM; i++){
		for(j = 0; j < DIM; j++){
			kotae[i][j].r /= k;
			kotae[i][j].i /= k;
		}
	}
}

unsigned long int kaijo(int n)
{
	int i;
	unsigned long int k;
	k = 1;
	for(i = 1; i <= n; i++){
		k *= (unsigned long int) i;
	}

	return k;
}

void matcopy(struct complex a[][2], struct complex b[][2])
{
	// aにbをコピーして返る
	int i, j;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			a[i][j] = b[i][j];
		}
	}
}

// 2行2列の複素行列の掛け算のルーチン。a * b を c に代入
void matkakeru(struct complex a[][2], struct complex b[][2], struct complex c[][2])
{
	struct complex temp1, temp2, temp3;
	struct complex ckakeru(struct complex, struct complex);
	struct complex ctasu(struct complex, struct complex);

	temp1 = ckakeru(a[0][0], b[0][0]);
	temp2 = ckakeru(a[0][1], b[1][0]);
	c[0][0] = ctasu(temp1, temp2);
	temp1 = ckakeru(a[0][0], b[0][1]);
	temp2 = ckakeru(a[0][1], b[1][1]);
	c[0][1] = ctasu(temp1, temp2);
	temp1 = ckakeru(a[1][0], b[0][0]);
	temp2 = ckakeru(a[1][1], b[1][0]);
	c[1][0] = ctasu(temp1, temp2);
	temp1 = ckakeru(a[1][0], b[0][1]);
	temp2 = ckakeru(a[1][1], b[1][1]);
	c[1][1] = ctasu(temp1, temp2);
}

// 複素数と複素数の掛け算のルーチン。x * y を戻り値として返す
struct complex ckakeru(struct complex x, struct complex y)
{
	struct complex z;
	z.r = x.r * y.r - x.i * y.i;
	z.i = x.r * y.i + x.i * y.r;
	return z;
}

// 複素数と複素数の足し算のルーチン。x + y を戻り値として返す
struct complex ctasu(struct complex x, struct complex y)
{
	struct complex z;
	z.r = x.r + y.r;
	z.i = x.i + y.i;
	return z;
}
