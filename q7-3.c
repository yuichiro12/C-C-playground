#include <stdio.h>
#include <limits.h>

int main(void)
{
  printf("この処理系のchar型は");

  if(CHAR_MIN)
    puts("符号付きで、");
  else
    puts("符号無しで、");

  printf("%d~%dを表すことができます。\n", CHAR_MIN, CHAR_MAX);

  return 0;  
}
