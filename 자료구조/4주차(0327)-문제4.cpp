//#include <stdio.h>
//int main() {
//	int n,m;
//	scanf("%d %d",&n,&m);
//	static int arr[110][110];
//
//	int cnt=1;
//	int x=1,y=1,dx=1,dy=1;
//
//	while (1) {
//		for (x = x;; x += dx) {
//			arr[y][x] = cnt++;
//			if (arr[y][x + dx] != 0 || x == m || x + dx == 0) {
//				dx = dx * -1;
//				break;
//			}
//		}
//		if (cnt > n * m) {
//			break;
//		}
//		y += dy;
//		for (y = y;; y += dy) {
//			arr[y][x] = cnt++;
//			if (arr[y + dy][x] != 0 || y == n || y + dy == 0) {
//				dy = dy * -1;
//				break;
//			}
//		}
//		if (cnt > n * m) {
//			break;
//		}
//		x += dx;
//	}
//
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= m; j++) {
//			printf(" %d",arr[i][j]);
//		}
//		printf("\n");
//	}
//	
//}


//재귀함수 버전
#include <stdio.h>
int cnt=1;
int** snailArr(int **arr, int stx, int sty, int edx, int edy) {
	if (stx > edx || sty > edy) {
		return;
	}
	int i=sty, j=stx;
	for (j = stx; i <= edx; i++) {
		arr[i][j] = cnt++;
	}
	j--;
	for (i = sty; i <= edy; i++) {
		arr[i][j] = cnt++;
	}
	i--;
	for (j = j; j >= stx; j--) {
		arr[i][j] = cnt++;
	}
	for (i = i; i > sty; i--) {
		arr[i][j] = cnt++;
	}
	snailArr(arr,stx+1, sty+1, edx-1, edy-1);
}
int main() {
	int n,m;
	scanf("%d %d",&n,&m);

	int arr[100][100];

	snailArr(arr,0,0,m-1,n-1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf(" %d",arr[i][j]);
		}
		printf("\n");
	}
}