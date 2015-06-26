#include <stdio.h>
#include <string.h>

#define MAX 50

int strend(char *, char *);

int main()
{
	char s[MAX], t[MAX];
	int n;

	strcpy(s, "This is a pen");
	strcpy(t, "pen");

	n = strend(s, t);

	if(n == 1){
		printf("found\n");
	} else {
		printf("Not found\n");
	}

	strcpy(s, "This is a pen");
	strcpy(t, "applen");

	n = strend(s, t);

	if(n == 1){
		printf("found\n");
	} else {
		printf("Not found\n");
	}
}

int strend(char *s, char *t)
{
	int i, j, k;
	i = j = 0;

	while(*(t + i) != '\0'){
		i++;
	}

	while(*(s + j) != '\0'){
		j++;
	}

	// NULL文字は比較の必要なし
	for(k = 1; k <= i; k++){
		printf("%c ", *(t + i - k));
		printf("%c\n", *(s + j - k));
		if(*(t + i - k) != *(s + j - k)){
			return 0;
		}
	}

	return 1;
}
