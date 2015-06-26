#include <stdio.h>
#include <math.h>

#define MAX 20

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
	printf("   The average of y is %f.\n", avg);
	printf("   The standard devidation of y is %f.\n\n", std);
}


// グラフ描画
void draw_graph(double max_x, double max_y,
	double min_x, double min_y, struct point pt[MAX], int i)
{
	const int maxX = round(max_x);
	const int maxY = round(max_y);
	const int minX = round(min_x);
	const int minY = round(min_y);
	const int len_x = maxX - minX;
	const int len_y = maxY - minY;
	int j, k;
	int loc_x, loc_y;
	int mark[len_x + 1][len_y + 1];

	// 配列の初期化
	for(j = 0; j < len_y + 1; j++){
		for(k = 0; k < len_x + 1; k++){
			mark[k][j] = 0;
		}
	}

	// 座標の情報入力
	for(j = 0; j < i; j++){
		loc_x = (int) round(pt[j].x) - minX;
		loc_y = maxY - (int) round(pt[j].y);
		if(pt[j].y <= round(pt[j].y) - 0.25){
			mark[loc_x][loc_y + 1] = -1;
		}else if(pt[j].y >= round(pt[j].y) + 0.25){
			mark[loc_x][loc_y] = -1;
		}else{
			mark[loc_x][loc_y] = 1;
		}
	}

	// x方向
	printf("\n   +");
	for(j = 0; j <= len_x; j++){
		printf("---");
	}
	printf("--+\n");


	// y方向、打点
	for(j = 0; j <= len_y; j++){
		printf("   |");
		for(k = 0; k <= len_x; k++){
			// 打点
			if(mark[k][j] == -1){
				printf("  *");
			} else {
				printf("   ");
			}
		}
		printf("  |\n");
		printf("%3d+", maxY - j);
		for(k = 0; k <= len_x; k++){
			// 打点
			if(mark[k][j] == 1){
				printf("  *");
			} else {
				printf("   ");
			}
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
		printf("%3d", minX + j);
	}
	printf("\n\n");
}
