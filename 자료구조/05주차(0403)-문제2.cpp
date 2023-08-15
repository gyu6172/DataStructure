#include <stdio.h>
typedef struct Point {
	int x;
	int y;
}Point;
int main() {
	int n;
	scanf("%d",&n);

	int arr[100][100]={0,};

	int cnt=1;

	Point st, ed;
	st.x = 0;
	st.y = 0;
	ed.x = n-1;
	ed.y = n-1;
	int x,y;

	while (1) {
		for (x = st.x, y = st.y; x <= ed.x || y <= ed.y; x++, y++) {
			arr[y][x] = cnt++;
		}
		y = ed.y;
		for (x = ed.x - 1; x >= st.x; x--) {
			arr[y][x] = cnt++;
		}

		x = st.x;
		for (y = ed.y - 1; y >= st.y + 1; y--) {
			arr[y][x] = cnt++;
		}

		st.x += 1;
		st.y += 2;
		ed.x -= 2;
		ed.y -= 1;

		if (st.x > ed.x || st.y > ed.y) {
			break;
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}