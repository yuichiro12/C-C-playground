#include <stdio.h>
#include <stdlib.h>

void push(int);
int pop();

struct LIST
{
	int data;
	struct LIST *next;	
};

int main()
{
	int x;
	int p;
	printf("qwqww");
	while(scanf("%d", &p)){
		if(p == 1){
			scanf("%d", &x);
			push(x);
		}else if(p == 0){
			pop();
		}else{
			return 0;
		}
	}
}

void push(int x)
{
	struct LIST *top, *new_r;
	top = NULL;

	new_r = (struct LIST *)malloc(sizeof(struct LIST));
	new_r->data = x;
	new_r->next = top;
	top = new_r;
}

int pop()
{
	int y;
	struct LIST *top;
	top = NULL;
	y = top->data;
	top = top->next;

	return 0;
}