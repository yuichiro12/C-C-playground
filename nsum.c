#include <stdio.h>

int wa(int);

int main()
{
	int n, s;

	scanf("%d", &n);
	s = wa(n);
	printf("%d\n", s);
}

int wa(int n)
{
	if(n <= 1){
		return 1;
	} else {
		return n + wa(n - 1);
	}
}