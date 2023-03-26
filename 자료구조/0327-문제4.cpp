#include <stdio.h>
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	static int arr[110][110];

	int cnt=1;
	int x=1,y=1,dx=1,dy=1;

	while (1) {
		for (x = x;; x += dx) {
			arr[y][x] = cnt++;
			if (arr[y][x + dx] != 0 || x == m || x + dx == 0) {
				dx = dx * -1;
				break;
			}
		}
		if (cnt > n * m) {
			break;
		}
		y += dy;
		for (y = y;; y += dy) {
			arr[y][x] = cnt++;
			if (arr[y + dy][x] != 0 || y == n || y + dy == 0) {
				dy = dy * -1;
				break;
			}
		}
		if (cnt > n * m) {
			break;
		}
		x += dx;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
	
}