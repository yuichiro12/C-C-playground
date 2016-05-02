#include <stdio.h>

#define swap(t, x, y){t i; i = x; x = y; y = i;}

int main(){
	float x = 1.12;
	float y = 10;
	printf("%f, %f\n", x, y);
	swap(float, x, y);
	printf("%f, %f\n", x, y);
}