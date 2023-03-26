#include <stdio.h>
int main() {
	int n;
	scanf("%d",&n);

	int arr[100][100];

	int i,j;
	int cnt=1;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			for (j = 0; j < n; j++) {
				arr[i][j]=cnt++;
			}
		}
		else {
			for (j = n - 1; j >= 0; j--) {
				arr[i][j]=cnt++;
			}
		}
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
}