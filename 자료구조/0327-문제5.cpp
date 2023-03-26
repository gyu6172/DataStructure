#include <stdio.h>
int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	int arr[110][110];

	int cnt = 1;

	int x = 0, y = 0, dy = 0, dx=1;
	int i=y, j=x;

	while (1) {
		arr[i++][j--] = cnt++;
		if (j < 0 || i==n) {
			if (x == m - 1) {
				dx=0;
				dy=1;
			}
			x+=dx;
			y+=dy;
			i = y;
			j = x;
		}
		if (cnt > n * m) {
			break;
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j <m; j++) {
			printf(" %d", arr[i][j]);
		}
		printf("\n");
	}

}