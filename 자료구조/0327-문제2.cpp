#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);

	int arr[100];

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	int cn;
	scanf("%d", &cn);

	int carr[110];

	for (i = 0; i < cn; i++) {
		scanf("%d", &carr[i]);
	}

	int n1, n2=arr[carr[0]];
	for (i = 0; i < cn-1; i++) {
		n1 = arr[carr[i+1]];
		arr[carr[i+1]] = n2;
		n2 = n1;
	}

	for (i = 0; i < n; i++) {
		printf(" %d",arr[i]);
	}
}