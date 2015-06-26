#include <stdio.h>
#include <string.h>

#define MAX 50

void strcat2(char [], char []);

int main()
{
	char s[MAX], t[MAX];

	strcpy(s, "This is a pen.");
	strcpy(t, "That is an apple.");

	strcat2(s, t);
	printf("%s\n", s);
}

void strcat2(char *s, char *t)
{
	int i, j;

	i = j = 0;
	while (*(s + i) != '\0'){
		i++;
	}
	while ((*(s + i++) = *(t + j++)) != '\0');
}