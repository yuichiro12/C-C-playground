#include <stdio.h>

int main()
{
	unsigned long int Fibonacci(int);
	int n;
	unsigned long int ans;

	scanf("%u", &n);
	ans = Fibonacci(n);
	printf("%lu\n", ans);
}

unsigned long int Fibonacci(int n)
{
	unsigned long int a = 1;
	unsigned long int b = 1;
	int i;

	switch(n){
		case 0:
			return 0;
		case 1:
		case 2:
			return 1;
		default:
			for(i = 3; i <= n; i++){
				b += a;
				a = b - a;
			}
			return b;
	}
}