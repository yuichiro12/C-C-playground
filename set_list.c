#include <stdio.h>
#include <stdlib.h>


typedef struct cell {
  int element;
  struct cell *next;
} cell;

/* 

構造体のメンバ変数へのアクセスはドット演算子を使うが、
構造体へのポインタを参照している場合、メンバ変数へのアクセスにはアロー演算子(->)を使う

例： pのelementに3を代入する場合

cell p;
p.element = 3;

cell *p;
p->element = 3;

*/



/* UNION(A, B, C) 計算時間はO(|A||B|) */



/* MEMBER(x, A) 計算時間はO(|A|) */
void member1(int x, cell *init)
{
  cell *p;
  p = init;

  while(p->next != NULL){
    if(p->element == x){
      printf("true\n");
      return;
    }else{
      p = p->next;
    }
  }

  printf("false\n");
}


/* INSERT(x, A) 計算時間はO(|A|) */
void insert1(int x, cell *init)
{
  cell *p;
  p = init;

  while(p->element != x){
    if(p->next == NULL){
      p->element = x;
    }else{
      p = p->next;
    }
  }

  /* セルの末尾ならnextの領域を確保する。つまり、リストの最後のセルには常に何も入っていない
     （実際は変数を入れていない状態でも何らかの値が入っているが詮索すると闇が深いので割愛） */
  p->next = (p->next == NULL) ? (cell *)malloc(sizeof(cell)) : p->next;
}


/* DELETE(x, A) 計算時間はO(|A|)*/
cell *delete1(int x, cell *init)
{
  /* 現在のセルのポインタpとその直前のセルのポインタbを保持しておく */
  cell *p, *b;
  p = init;

  /* 先頭の場合 */
  if(p->element == x){
    if(p->next != NULL){
      /* 先頭のポインタの書き換え */
      init = init->next;
      free(p);

      return init;
    }
  /* それ以外の場合 */
  }else{
    while(p->next != NULL){
      if(p->element == x){
	/* 一つ前のセルbのnextポインタを現在のセルpのnextポインタに書き換え */
	b->next = p->next;
	/* free()によってアクセスすることがなくなったメモリ領域の開放 */
	free(p);
      }else{
	b = p;
	p = p->next;
      }
    }
  }

  return init;
}



/* initialize list */
void initList(int a[], int length, cell *A)
{
  int i;

  for(i = 0; i < length; i++){
    insert1(a[i], A);
  }
}


/* print elements of the list in order */
void printList(cell *lst, char name[])
{
  cell *p;
  p = lst;
  printf("%s = {", name);

  while(p->next != NULL){
    printf("%d, ", p->element);
    p = p->next;
  }
  
  if(p == lst){
    printf("}\n");
  }else{
    printf("\b\b}\n");
  }
}



int main(void)
{
  int a[] = {0, 1, 2, 3, 5, 6, 9};
  int b[] = {0, 2, 4, 6, 8};
  int x[] = {7};
  cell *A, *B, *X, *C;
  A = (cell *)malloc(sizeof(cell));   /* EMPTY(A)と同じ */
  B = (cell *)malloc(sizeof(cell));
  X = (cell *)malloc(sizeof(cell));
  printList(A, "A");

  initList(a, sizeof(a)/sizeof(a[0]), A);
  printList(A, "A");
  initList(b, sizeof(b)/sizeof(b[0]), B);
  printList(B, "B");
  initList(x, sizeof(x)/sizeof(x[0]), X);
  printList(X, "X");

  
  member1(3, A);
  member1(100, A);

  insert1(4, A);
  printList(A, "A");

  A = delete1(5, A);
  printList(A, "A");

  A = delete1(4, A);

  A = delete1(0, A);
  printList(A, "A");

  return 0;
}
