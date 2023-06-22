#include <stdio.h>
int isPallindrome(char str[], int n) {
	int flag=0;
	for (int i = 0, j = n - 1; i < j; i++, j--) {
		if (str[i] != str[j]) {
			flag = 1;
		}
	}
	if (flag == 1) return 0;
	else return 1;
}
int main() {
	int n;
	scanf("%d",&n);
	getchar();
	char str[100];
	for (int i = 0; i < n; i++) {
		scanf("%c",&str[i]);
	}

	if (isPallindrome(str, n)) {
		printf("1");
	}
	else {
		char str2[202];
		int iter=0;
		for (int i = 0; i < n; i++) {
			str2[iter++] = str[i];
		}
		for (int i = n - 1; i >= 0; i--) {
			str2[iter++] = str[i];
		}
		str2[iter++] = NULL;
		printf("%s",str2);
	}

}