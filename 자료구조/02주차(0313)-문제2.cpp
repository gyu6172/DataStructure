#include <stdio.h>
int mostOnes(int arr[][100], int n);
int main() {
	int n;
	scanf("%d", &n);
	int arr[100][100];

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d", mostOnes(arr, n));
}

int mostOnes(int arr[][100], int n)
{
	int lastRow = 0;
	int currentRow = 0;
	int currentCol = 0;
	while (1) {
		while (arr[currentRow][currentCol] == 1) {
			currentCol++;
			if (currentCol == n) {
				lastRow = currentRow;
				return lastRow;
			}
		}
		lastRow = currentRow;
		while (arr[currentRow][currentCol] == 0) {
			currentRow++;
			if (currentRow == n) {
				return lastRow;
			}
		}
	}
}
