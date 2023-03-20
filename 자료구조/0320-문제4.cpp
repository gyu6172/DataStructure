#include <stdio.h>
int max(int n, int arr[]) {
	if (n == 0) {
		if (arr[n] < arr[n + 1]) {
			return arr[n+1];
		}
		else {
			return arr[n];
		}
	}
	else if (max(n - 1, arr) < arr[n-1]) {
		return arr[n-1];
	}
	else {
		return max(n-1,arr);
	}
}
int main() {
	int n, arr[20];
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}
	printf("%d",max(n, arr));
}