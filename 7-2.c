#include <stdio.h>

#define MAX_COL 70

int main()
{
	unsigned char c;
	int n;

	n = 0;
	while(scanf("%c", &c) != EOF){
		if((c <= 0x1f) || (c >= 0x7f)){
			printf("[%02x]", c);
			n += 4;
		}else{
			printf("%c", c);
			n++;
		}
		if(n >= 70){
			printf("\n");
			n = 0;
		}
	}
}