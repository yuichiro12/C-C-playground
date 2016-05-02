#include <stdio.h>
#include <string.h>

void quicksort(int *nums, int low, int high)
{

	if(low < high){
		int pivot = low + (high - low)/2;
		int p = nums[pivot];
		int tmp = 0;
		int i = low;
		int j = high;
		while(1){
			while(nums[i] < p) i++;
			while(nums[j] > p) j--;
			if(i >= j) break;
			tmp = nums[i];
			nums[i] = nums[j];
			nums[j] = tmp;
			i++;
			j--;
		}
		quicksort(nums, low, i - 1);
		quicksort(nums, j + 1, high);
	}

	return;
}

int main()
{
	int nums[] = {10, 4, 5, 7, 9, 5, 0, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 3, 5};
	int out[21];
	quicksort(nums, 0, 20);
	int i = 0;

	for(; i < 21; i++){
		printf("%d ", nums[i]);
	}

	printf("\n");

	return 0;
}
