#include <stdio.h>

int htoi (char *s)
{
	int n;
	if ( *s != '0' || !(*(s + 1) != 'x' || *(s + 1) != 'X') ) {
		return -1;
	}

	for(n = 0, s += 2; *s; s++){
		if (*s >= '0' && *s <= '9') {
			n = 16 * n + (*s - '0');
		}
		else if (*s >= 'a' && *s <= 'f') {
			n = 16 * n + ((*s - 'a') + 10);
		}
		else if (*s >= 'A' && *s <= 'F') {
			n = 16 * n + ((*s - 'A') + 10);
		}
		else {
			return -1;
		}
	}
	return n;
}

main()
{
	char s[50];
	printf("16進数値を入力してください> ");
	scanf("%s", &s);
	printf("%d\n", htoi(s));
	return 0;
}