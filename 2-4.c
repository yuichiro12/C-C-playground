#include <stdio.h>
#include <string.h>

void squeeze(char [], char []);

main()
{
	char input[99];
	char input2[99];
	char s[100];
	char c[100];

	printf("文字列を入力してください> ");
	scanf("%s", &input);
	printf("除去する文字を好きなだけ入力してください> ");
	scanf("%s", &input2);

	strcpy(s, input);
	strcpy(c, input2);

	squeeze(s, c);
	printf("%sを取り除くと%sです。\n", c, s);
}

void squeeze(char s[], char c[])
{
	int i, j, k;

	for(k = 0; c[k] != '\0'; k++){
		for(i = j = 0; s[i] != '\0'; i++){
			if(s[i] != c[k]){
				s[j++] = s[i];
			}
		}
		s[j] = '\0';
	}
}