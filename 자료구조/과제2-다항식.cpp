#include <stdio.h>
int max(int a, int b) {
	return (a>b)?a:b;
}
int main() {
	int p1degree,p2degree;
	scanf("%d", &p1degree);

	int p1[1000]={0}, p2[1000]={0};
	int result[1000];

	for (int i = 0; i <= p1degree; i++) {
		scanf("%d", &p1[i]);
	}

	scanf("%d", &p2degree);
	for (int i = 0; i <= p2degree; i++) {
		scanf("%d", &p2[i]);
	}

	for (int i = 0, j = p1degree; i < j; i++, j--) {
		int tmp = p1[i];
		p1[i] = p1[j];
		p1[j] = tmp;
	}
	for (int i = 0, j = p2degree; i < j; i++, j--) {
		int tmp = p2[i];
		p2[i] = p2[j];
		p2[j] = tmp;
	}
	for (int i = 0; i <= max(p1degree, p2degree); i++) {
		result[i] = p1[i]+p2[i];
	}
	for (int i = max(p1degree, p2degree); i >= 0; i--) {
		printf("%d ",result[i]);
	}

	return 0;
}