#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	int *arr1, *arr2;
	scanf("%d",&n);

	arr1 = (int*)malloc(sizeof(int) * n);
	arr2 = (int*)malloc(sizeof(int) * n);

	int i,j;
	for (i = 0; i < n; i++) {
		scanf("%d",&arr1[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &arr2[i]);
	}
	for (i = 0; i<n; i++) {
		printf(" %d",arr1[i]+arr2[n-1-i]);
	}
}