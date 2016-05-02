#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 50

void reverse(char []);
void hanten_saiki(char [], int);

int main()
{
	char s[MAX_STR_LEN];
	strcpy(s, "ABCDEF");

	reverse(s);
	printf("%s\n", s);
}

void reverse(char s[])
{
	int n;
	n = strlen(s);

	hanten_saiki(s, n);
}

void hanten_saiki(char s[], int n)
{
	char c;

	if(n >= 2){
		c = s[0];
		s[0] = s[n-1];
		s[n-1] = c;
		hanten_saiki(&s[1], n-2);
	}
}
