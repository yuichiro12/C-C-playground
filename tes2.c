#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);

int main(int argc, char *argv[])
{
    char *str0 = "hello, world";
    char str1[1024];
    char *str2 = "el";

    strcpy(str1, str0); /* 文字列リテラルは変更できないのでコピーを作る。 */
    printf("str1 : %s\n", str1);
    printf("str2 : %s\n", str2);
    squeeze(str1, str2);
    printf("%s\n", str1);

    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j, k;

    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++) {
            if (s1[i] != s2[k]) {
                s1[j++] = s1[i];
            }
        }
        s1[j] = '\0';
    }
}