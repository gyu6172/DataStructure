#include <stdio.h>
#include <string.h>
void isPalindrome(char str[], char *p, char *q) {
	if (p >= q) {
		printf("�Է��� �ܾ� %s�� Palindrome �Դϴ�.",str);
	}
	else {
		if (*p != *q) {
			printf("�Է��� �ܾ� %s�� Palindrome�� �ƴմϴ�.", str);
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