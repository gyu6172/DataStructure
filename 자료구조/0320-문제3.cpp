#include <stdio.h>
void reverse(int n) {
	if (n < 10) {
		printf("%d\n", n);
		return;
	}
	reverse(n % 10);
	reverse(n / 10);
}
int main() {
	int n;
	scanf("%d", &n);

	reverse(n);

}