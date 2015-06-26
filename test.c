#include <stdio.h>
#include <string.h>
#include <regex.h>

void print(const char *str, int so, int eo)
{
	char tmp[7];

	str += so;
	eo -= so;
	strncpy(tmp, str, eo);
	tmp[eo] = '\0';
	puts(tmp);
}

int main()
{
	regex_t regst;
	regmatch_t match[1];

	char *reg = "(a-z)+";
	char *str = "a";

	if (regcomp(&regst, reg, REG_EXTENDED)) {
		return 1;
	}
	if (!regexec(&regst, str, 1, match, 0)) {
		print(str, match[0].rm_so, match[0].rm_eo);
	} else {
		puts("not match");
	}
	regfree(&regst);
	return 0;
}