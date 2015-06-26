// 問題は、与えられた非負の数字列を、隣接する和が小さくなるように足していくというのと同値とみなせる

#include <stdio.h>

int main()
{
	int w[] = {13, 43, 25, 34, 12, 7, 50};
	int len = sizeof w / sizeof w[0];
	int sum[len - 1];
	int i, j;
	int k;
	int prev_sum, next_sum;

	// inititalize min, sum[0]
	int min = w[0] + w[1];
	sum[0] = min;

	// 隣接した貨車の荷物の値段の和の配列を得る
	for(i = 1; i < len; i++){
		sum[i] = w[i] + w[i + 1];
		if(sum[i] < min){
			min = sum[i];
			k = i;
		}
	}

	w[k] = sum[k];
	for(i = k + 1; i < len; i++){
		w[i] = w[i + 1];
	}
	for(i = k + 1; i < len; i++){
		w[i] = w[i + 1];
	}
	// DP的に最小の値段を計算
	// ()で囲んでOK?
	prev_sum = (k != 0) ? (w[k - 1] + w[k]) : min;
	next_sum = (k != len - 1) ? (w[k - 1] + w[k]) : min;
	min = prev_sum < min ? prev_sum : min;
	min = next_sum < min ? next_sum : min;
	len--;


}

void pushHeap(int x)
{
	int i, j;
	heap[n] = x;
	i = n;
	j = i / 2;
	for(j > 0 && x > heap[j]){
		
	}
}
