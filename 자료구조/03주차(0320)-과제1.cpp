#include <stdio.h>
#include <string.h>
void isPalindrome(char str[], char *p, char *q) {
	if (p >= q) {
		printf("입력한 단어 %s는 Palindrome 입니다.",str);
	}
	else {
		if (*p != *q) {
			printf("입력한 단어 %s는 Palindrome이 아닙니다.", str);
		}
		else {
			isPalindrome(str,++p, --q);
		}
	}
}
int main() {
	char str[100];
	scanf("%s",str);
	char *p, *q;
	p=str;
	q=p+strlen(p)-1;

	isPalindrome(str, p, q);
	return 0;
}