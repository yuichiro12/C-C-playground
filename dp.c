// 課題 1.

#include <stdio.h>

int main()
{
	char a[] = "chicken";
	char b[] = "kitchen";

	int i;
	int j;
	int row = sizeof a / sizeof a[0];
	int col = sizeof b / sizeof b[0];
	int matrix[row][col];
	int ist = 0;
	int del = 0;
	int pmt = 0;
	int min;

	for(i = 0; i < row; i++){
		matrix[i][0] = i * 2;
	}
	for(j = 0; j < col; j++){
		matrix[0][j] = j * 2;
	}

	for(i = 1; i < row; i++){
		for(j = 1; j < col; j++){
			// insert
			ist = matrix[i][j - 1] + 2;
			// delete
			del = matrix[i - 1][j] + 2;
			// permute
			if(a[i - 1] == b[j - 1]){
				pmt = matrix[i - 1][j - 1];
			} else {
				pmt = matrix[i - 1][j - 1] + 3;
			}
			min = ist;
			min = (min > del) ? del : min;
			min = (min > pmt) ? pmt : min;
			matrix[i][j] = min;
			printf("%c, %c, %3d %3d %3d  %3d\n", a[i - 1], b[j - 1], ist, del, pmt, min);
		}
	}

	for(i = 0; i < row; i++){
		for(j = 0; j < col; j++){
			printf("%3d ", matrix[i][j]);
		}
		printf("\n");
	}
}
