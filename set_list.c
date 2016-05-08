#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int element;
  struct cell *next;
} cell;

void insert1(int x, cell *init)
{
  cell *cd = init;
  printf("%p %p %p\n", &init, &cd, &init);
  cd.element = x;
  
}

void printList(pcell lst)
{
  pcell i;
}

int main(void)
{
  cell A;
  A.element = 3;
  insert1(4, &A);

  printf("%d\n", A.element);
  return 0;
}
