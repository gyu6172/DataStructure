#include <stdio.h>
#include <stdlib.h>
int* prefixAverages1(int arr[], int n);
int* prefixAverages2(int arr[], int n);
int main() {
	int n;
	scanf("%d",&n);

	int *X = (int*)malloc(sizeof(int)*n);
	int *A = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d",&X[i]);
	}

	A = prefixAverages1(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
	A = prefixAverages2(X, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", A[i]);
	}

	free(X);
	free(A);
}

int* prefixAverages1(int arr[], int n)
{
	int *rst = (int*)malloc(sizeof(int)*n);
	int rstIter=0;
	int i,j;
	for (i = 0; i < n; i++) {
		double sum=0.0;
		for (j = 0; j <= i; j++) {
			sum += arr[j];
		}
		rst[rstIter++] = (int)(sum/(i+1)+0.5);
	}

	return rst;
}

int* prefixAverages2(int arr[], int n)
{
	int* rst = (int*)malloc(sizeof(int) * n);
	int rstIter = 0;
	int i, j;
	double sum = 0.0;
	for (i = 0; i < n; i++) {
		sum += arr[i];
		rst[rstIter++] = (int)(sum / (i + 1) + 0.5);
	}

	return rst;
}
