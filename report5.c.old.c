#include <stdio.h>
#include <math.h>

#define MAX 20
// #define MARK(x, y) printf("\033[%d;%dH", y, x)
// #define GO_BOTTOM(len)	printf("\033[%dB", len); printf("\033[1K")

struct point
{
	double x, y;
};


int main()
{
	struct point pt[MAX];
	double max_x, max_y, min_x, min_y, avg, std;
	double sum1 = 0.0;
	double sum2 = 0.0;
	int i = 0;
	int j;
	void draw_graph(double, double, double, double, struct point[MAX], int);

	// 標準入力
	while(scanf("%lf %lf", &pt[i].x, &pt[i].y) != EOF){
		i++;
	}

	// xの最大値の取得
	max_x = pt[0].x;
	for(j = 1; j < i; j++){
		if(max_x < pt[j].x){
			max_x = pt[j].x;
		}
	}
	// xの最小値の取得
	min_x = pt[0].x;
	for(j = 1; j < i; j++){
		if(min_x > pt[j].x){
			min_x = pt[j].x;
		}
	}

	// yの最大値の取得
	max_y = pt[0].y;
	for(j = 1; j < i; j++){
		if(max_y < pt[j].y){
			max_y = pt[j].y;
		}
	}
	// yの最小値の取得
	min_y = pt[0].y;
	for(j = 1; j < i; j++){
		if(min_y > pt[j].y){
			min_y = pt[j].y;
		}
	}

	// グラフ描画
	draw_graph(max_x, max_y, min_x, min_y, pt, i);


	// 平均を求める
	for(j = 0; j < i; j++){
		sum1 += pt[j].y;
	}
	avg = sum1 / i;

	// 標準偏差を求める
	for(j = 0; j < i; j++){
		sum2 += (pt[j].y- avg) * (pt[j].y- avg);
	}
	std = sqrt(sum2 / i);

	// 出力
	printf("The average of y is %f.\n", avg);
	printf("The standard devidation of y is %f.\n", std);
}


// グラフ描画
void draw_graph(double max_x, double max_y,
	double min_x, double min_y, struct point pt[MAX], int i)
{
	int maxX = round(max_x);
	int maxY = round(max_y);
	int minX = round(min_x);
	int minY = round(min_y);
	int len_x = maxX - minX;
	int len_y = maxY - minY;
	int j, k;
	int loc_x, loc_y;
	int mark[len_x][len_y];


	for(j = 0; j < i; j++){
		// loc_x =  (int) 3 * (round(pt[j].x) - minX) + 7;
		// loc_y = (int) 2 * (maxY - round(pt[j].y)) + 3;
		// MARK(loc_x, loc_y);
		// GO_BOTTOM(len_y - loc_y);
		// printf("%d", j);
		mark[(round(pt[j].x)][(round(pt[j].y)] = 1;
	}

	// x方向
	printf("   +");
	for(j = 0; j <= len_x; j++){
		printf("---");
	}
	printf("--+\n");


	// y方向

	for(j = 0; j <= len_y; j++){
		printf("   |");
		for(k = 0; k <= len_x; k++){
			printf("   ");
		}
		printf("  |\n");
		printf("%3d+", (int) maxY - j);
		for(k = 0; k <= len_x; k++){
			printf("   ");
		}
		printf("  +\n");
	}
	printf("   |");
	for(k = 0; k <= len_x; k++){
		printf("   ");
	}
	printf("  |\n");

	// ここまでy方向


	// x方向

	printf("   +");
	for(j = 0; j <= len_x; j++){
		printf("--+");
	}
	printf("--+\n");

	printf("    ");
	for(j = 0; j <= len_x; j++){
		printf("%3d", (int) minX + j);
	}
	printf("\n");

	printf("%f\n", max_x);
	printf("%f\n\r", max_y);
	printf("%f\n", min_x);
	printf("%f\n", min_y);
}