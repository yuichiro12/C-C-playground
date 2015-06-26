// Knuth-Morris-Platt algorithm

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int j;
	int next[50];
	const char P[] = "aaaabbbba";
	const char T[] = "abababa5babc";
	int m = strlen(P);
	int n = strlen(T);
	int ans;
	void init(const char[], int [], int);
	int kmp(const char[], const char[], int [], int, int);

	init(P, next, m);
	ans = kmp(T, P, next, m, n);
	printf("%d\n", ans);
}

void init(const char P[], int next[], int m){
	int i;
	int j = -1;
	for(i = 0; i < m; i++){
		next[i] = j;
		printf("next[%d]: %d\n", i, next[i]);
		while((j >= 0) && (P[i] != P[j])){
			j = next[j];
		}
		j++;
	}
}

int kmp(const char T[], const char P[], int next[], int m, int n){
	int i;
	int j = 0;
	for(i = 0; i < n; i++){
		usleep(500000);
		printf("i: %d j: %d\n", i, j);
		while((j >= 0) && (T[i] != P[j])){
			j = next[j];
		}
		if(j == m - 1){
			return i - m + 1;
		}
		j++;
	};
	return -1;
}