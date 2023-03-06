#include <stdio.h>
void swap(int* p, int* q);
int main() {
	int n,i,j;
	scanf("%d",&n);

	int arr[50];

	for (i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	int a,b;
	scanf("%d %d",&a,&b);

	swap(&arr[a], &arr[b]);

	for (i = 0; i < n; i++) {
		printf(" %d",arr[i]);
	}


}

void swap(int* p, int* q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}
