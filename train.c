#include <stdio.h>
#include <stdlib.h>

// 連結リスト
struct LIST {
	struct LIST *next;
	struct LIST *prev;
	int val;
};


int main()
{
	int a[] = {13, 43, 25, 34, 12, 7, 50};
	int len = sizeof a / sizeof a[0];
	int i = 0;
	int max = 0;

	struct LIST *head, *new_r, *tail;

	new_r = (struct LIST *) malloc(sizeof(struct LIST));
	new_r->val = a[0];
	new_r->next = NULL;
	head = new_r;
	tail = new_r;

	for(i = 1; i < len; i++){
		new_r = (struct LIST *) malloc(sizeof(struct LIST));
		new_r->val = a[i];
		tail->next = new_r;
		new_r->next = NULL;
		tail = new_r;
		printf("%d\n", new_r);
	}
	printf("%d\n", head->next);
	printf("%d\n", head->next->next);

	// for(i = 0; i < len; i++){

	// }
}