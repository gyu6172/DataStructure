#include <stdio.h>
//2�� n���� �����ϴ� �Լ�
int pow2(int n) {
	int rst=1;
	for (int i = 0; i < n; i++) {
		rst *= 2;
	}
	return rst;
}
int main() {
	int n;
	scanf("%d",&n);

	int pw1[100];
	int pw2[100];

	for (int i = 0; i < n; i++) {
		scanf("%d",&pw1[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &pw2[i]);
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", pw1[i] | pw2[i]);
	}








}