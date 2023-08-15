#include <stdio.h>
void hanoi(int n, char start, char end, char extra) {
	if (n == 1) {
		printf("%c %c\n",start,end);
		return;
	}
	else {
		hanoi(n - 1, start, extra, end);
		printf("%c %c\n", start, end);
		hanoi(n - 1, extra, end, start);
	}
}
int main() {
	int n;
	scanf("%d",&n);

	hanoi(n, 'A', 'C', 'B');
}