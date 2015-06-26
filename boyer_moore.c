#include <stdio.h>
#include <strlen.h>

#define max(a, b) (a < b) ? a : b;

int main()
{
	char T[] = "abababababc";
	char P[] = "abababababc";
	const int n = strlen(P);
	const int m = strlen(T);
	int CC(char []);
	int boyer_moore(char [], char [], int [], int [], int, int);

	int d = CC(P);
	int shift1[d];
	int shift2[m];
	int ans;

	ans = boyer_moore(T, P, shift1, shift2, n, m);
	printf("%d\n", ans);
}

int CC(char *P)
{
	int i, j;
	int count = 0;
	for(i = 0; P[i] != '\0'; i++){
		for(j = 0; j < i; j++){
			if(P[i] == P[j]){
				j = -1;
				break;
			}
		}
		if(j != -1){
			count++;
		}
	}

	return count;
}

int boyer_moore(char *T, char *P, int *shift1, int *shift2, int n, int m)
{
	int i = 0;

	while(i <= n - m){
		for(j = m - 1; j >= 0; j--){
			if(T[i + j] != P[j]){
				break;
			}
			if(j == -1){
				return i;
			}
			i = i + max(shift1[T[i + j]], shift2[P[j]]);
		}
	}
	return -1;
}