#include <stdio.h>

struct LIST{
	int val;
	int ord;
};

int main()
{
	int array = {12, 34, 21, 65, 32}
	int len = sizeof array;
	int max = 0;
	int sum = 0;
	int i = 0;

	struct LIST train[len];

	train[0]->val = array[0];
	train[0]->ord = 0;
	for(i = 1; i < len; i++){
		train[i]->val = array[i];
		train[i]->ord = i;
		sum = train[i - 1]->val + train[i]->val;
		if(max < sum){
			max = sum;
		}
	}

}