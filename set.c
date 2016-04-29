#include <stdio.h>

#define n 10

/*

実際にdefineするときはマクロを大文字で定義するようにしよう

【3項演算子】
a ? b : c は if (a == true) b else c と同じ意味

*/


/* UNION(A, B, C) 計算時間はO(n) */
void union1(int A[], int B[], int C[])
{
  int i;
  for (i = 0; i < n; i++) { 
     C[i] = (A[i] == 0) ? B[i] : A[i];
  }
}


/* INTERSECTION(A, B, C) 計算時間はO(n) */
void intersection1(int A[], int B[], int C[])
{
  int i;
  for (i = 0; i < n; i++) {
    C[i] = A[i] * B[i];
  }
}


/* DIFFERENCE(A, B, C) 計算時間はO(n) */
void difference1(int A[], int B[], int C[])
{
  int i;
  for (i = 0; i < n; i++) {
    C[i] = (B[i] == 0) ? A[i] : 0;
  }
}


/* MERGE(A, B, C) 計算時間はO(n) */
int merge1(int A[], int B[], int C[])
{
  int i;
  for (i = 0; i < n; i++) {
    if(A[i] * B[i])
      return 1;
  }
  
  for (i = 0; i < n; i++) {
    C[i] = A[i] ? A[i] : B[i];
  }

  return 0;
}


/* EMPTY(A) 計算時間はO(n) */
void empty1(int A[])
{
  int i;
  for (i = 0; i < n; i++) {
    A[i] = 0;
  }
}


/* MEMBER(x, A) 計算時間はO(1) */
int member1(int x, int A[])
{
  return A[x];
}


/* INSERT(x, A) 計算時間はO(1) */
void insert1(int x, int A[])
{
  A[x] = 1;
}

/* DELETE(x, A) 計算時間はO(1)*/
void delete1(int x, int A[])
{
  A[x] = 0;
}



/* print the initialization */
void printInit(int A[], int B[], int X[], int x1, int x2)
{
  int i;
  int m;
  
  printf("U = {");

  for (i = 0; i < n; i++) {
    printf("%d, ", i);
  }

  printf("\b\b}\n");

  printf("A = {");

  for (i = 0; i < n; i++) {
    m = 1;
    
    if (A[i] == 1) {
      printf("%d, ", i);
    }
  }

  if (m == 1) {
    printf("\b\b}\n");
  } else {
    printf("}\n");
  }

  m = 0;
  
  printf("B = {");

  for (i = 0; i < n; i++) {
    if (B[i] == 1) {
      m = 1;
      printf("%d, ", i);
    }
  }

  if (m == 1) {
    printf("\b\b}\n");
  } else {
    printf("}\n");
  }

  m = 0;

  printf("X = {");

  for (i = 0; i < n; i++) {
    if (X[i] == 1) {
      m = 1;
      printf("%d, ", i);
    }
  }

  if (m == 1) {
    printf("\b\b}\n");
  } else {
    printf("}\n");
  }

  printf("x1 = %d, x2 = %d\n", x1, x2);

  printf("\n");
  printf("[1]union\n");
  printf("[2]intersection\n");
  printf("[3]differnce\n");
  printf("[4]merge\n");
  printf("[5]empty\n");
  printf("[6]member\n");
  printf("[7]insert\n");
  printf("[8]delete\n");
  printf("\n");
  printf("Choose the number of the function: ");
}

/* print the outcome */
void printArray(int C[], char a)
{
  int i;
  int m;
  
  printf("%c = {", a);

  for (i = 0; i < n; i++) {
    if (C[i] == 1) {
      m = 1;
      printf("%d, ", i);
    }
  }
    
  if (m == 1) {
    printf("\b\b}\n");
  } else {
    printf("}\n");
  }
}



int main(void)
{
  int num;
  int i;
  int b;
  int x1 = 3;
  int x2 = 4;
  int A[n] = {1, 1, 1, 1, 0, 1, 1, 0, 0, 1};
  int B[n] = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
  int X[n] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
  int C[n];

  printInit(A, B, X, x1, x2);

  scanf("%d", &num);
  printf("\n");

  switch (num) {
    case 1:
      union1(A, B, C);
      printArray(C, 'C');
      break;
    case 2:
      intersection1(A, B, C);
      printArray(C, 'C');
      break;
    case 3:
      difference1(A, B, C);
      printArray(C, 'C');
      break;
    case 4:
      b = merge1(A, B, C);
      printf("MERGE(A, B, C):\n");
      if (b){
	printf("A ∩ B ≠ ∅\n");
      } else {
	printArray(C, 'C');
      }
      printf("\n");
      printf("MERGE(A, B, X):\n");
      b = merge1(A, X, C);
      if (b){
	printf("A ∩ B1 ≠ ∅\n");
      } else {
	printArray(C, 'C');
      }
      printf("\n");
      break;
    case 5:
      empty1(A);
      printArray(A, 'A');
      break;
    case 6:
      b = member1(x1, A);
      printf("x1 ∈ A is ");
      printf("%s", b ? "true\n" : "false\n");
      b = member1(x2, A);
      printf("x2 ∈ A is ");
      printf("%s", b ? "true\n" : "false\n");
      break;
    case 7:
      insert1(x1, A);
      printf("INSERT(x1, A):\n");
      printArray(A, 'A');
      printf("\n");
      insert1(x2, A);
      printf("INSERT(x2, A):\n");
      printArray(A, 'A');
      break;
    case 8:
      delete1(x2, A);
      printf("DELETE(x2, A):\n");
      printArray(A, 'A');
      printf("\n");
      delete1(x1, A);
      printf("DELETE(x1, A):\n");
      printArray(A, 'A');
      break;
    default:
      printf("Input error.\n");
    }

  printf("\n");

  return 0;
}
