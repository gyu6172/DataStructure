#include <stdio.h>
int main() {
	int r1, c1;
	scanf("%d %d", &r1, &c1);
	int r2, c2;
	scanf("%d %d", &r2, &c2);
	//c1==r2로 입력된다.

	int matrix1[100][100]={0,};
	int matrix2[100][100]={0,};
	int result[100][100]={0,};

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c1; j++) {
			scanf("%d",&matrix1[i][j]);
		}
	}

	for (int i = 0; i < r2; i++) {
		for (int j = 0; j < c2; j++) {
			scanf("%d", &matrix2[i][j]);
		}
	}

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
			int rst=0;
			for (int x = 0, y=0; x < c1, y<r2; x++,y++) {
				rst += matrix1[i][x]*matrix2[y][j];
			}
			result[i][j] = rst;
		}
	}

	for (int i = 0; i < r1; i++) {
		for (int j = 0; j < c2; j++) {
			printf("%d ",result[i][j]);
		}
		printf("\n");
	}
	
}