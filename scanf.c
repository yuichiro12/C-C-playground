#include <stdio.h>

#define MAX 50
#define swap(a, b){float x = a; a = b; b = x;}

struct pair_data{
	float x;
	float y;
};

int main()
{
	int n, i;
	struct pair_data d[MAX];
	void data_sort(struct pair_data *, int);

	n = 0;
	while(scanf("%f, %f", &d[n].x, &d[n].y) != EOF){
		n++;
	}

	data_sort(d, n);
	for(i = 0; i < n; i++){
		printf("%f, %f\n", d[i].x, d[i].y);
	}
}

void data_sort(struct pair_data *d, int n){
	int i;
	for(n; n > 0; n--){
		for(i = 0; i < n - 1; i++){
			if(d[i].x > d[i + 1].x){
				swap(d[i].x, d[i + 1].x);
				swap(d[i].y, d[i + 1].y);
			}
		}
	}
}