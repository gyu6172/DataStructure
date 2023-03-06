#include <stdio.h>
void ABC(int arr[], int k);
int main() {
	int i,j;
	int arr[10];
	for (i = 0; i < 10; i++) {
		scanf("%d",&arr[i]);
	}
	for (i = 0; i < 10; i++) {
		ABC(arr,i);
	}
	for (i = 0; i < 10; i++) {
		printf(" %d",arr[i]);
	}
}

void ABC(int arr[], int k)
{
	int i,j;
	int maxPos=k;
	for (i = k; i < 10; i++) {
		if (arr[maxPos] < arr[i]) {
			maxPos = i;
		}
	}
	int tmp = arr[k];
	arr[k] = arr[maxPos];
	arr[maxPos] = tmp;
}
