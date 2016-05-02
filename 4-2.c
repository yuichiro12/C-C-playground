#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main()
{
	double atof(char []);
	char s[99];
	double d;
	scanf("%s", s);

	d = atof(s);
	printf("%f\n", d);
}

double atof(char s[])
{
	double val,  power, vale, powere, e;
	int i, sign, signe;

	for(i = 0; isspace(s[i]); i++){};

	sign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '+' || s[i] == '-'){
		i++;
	}

	for(val = 0.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
	}

	if(s[i] == '.'){
		i++;
	}

	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	if(s[i] == 'e' || s[i] == 'E'){
		i++;
	}

	signe = (s[i] == '-') ? -1 : 1;

	if(s[i] == '+' || s[i] == '-'){
		i++;
	}

	for(vale = 0.0; isdigit(s[i]); i++){
		vale = 10.0 * vale + (s[i] - '0');
	}

	if(s[i] == '.'){
		i++;
	}

	for(powere = 1.0; isdigit(s[i]); i++){
		vale = 10.0 * vale + (s[i] - '0');
		powere *= 10.0;
	}

	e = pow(10, signe * vale / powere);

	return sign * val / power * e;
}