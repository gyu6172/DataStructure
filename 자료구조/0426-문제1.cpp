#include <stdio.h>
int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	static int arr[110][110];

	int cnt=1;
	int x=1,y=1,dx=1,dy=1;

	int rst=0;

	while (1) {
		int flag=0;
		for (x = x;; x += dx) {
			if (flag == 0) {
				flag = 1;
				rst++;
			}
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
		flag=0;
		for (y = y;; y += dy) {
			if (flag == 0) {
				flag = 1;
				rst++;
			}
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

	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= m; j++) {
	//		printf(" %d",arr[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("%d",rst-1);
	
}