#include <stdio.h>
#include <string.h>
int checkStr(char str[], char c, int n) {
	if (n == strlen(str)) {
		return 0;
	}
	else if (str[n] == c) {
		return 1+checkStr(str, c, n+1);
	}
	else {
		return checkStr(str, c, n + 1);
	}
}
int main() {
	char str[101];
	scanf("%s",str);
	getchar();
	char c;
	scanf("%c",&c);
	
	printf("%d", checkStr(str, c, 0));

}