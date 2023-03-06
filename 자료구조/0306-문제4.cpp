#include <stdio.h>
#include <string.h>
int main() {
	char str[101];
	scanf("%s",str);
	int len = strlen(str);
	int i,j;
	for (i = 0; i < len; i++) {
		printf("%s\n",str);
		char a = str[0];
		for (j = 0; j < len-1; j++) {
			str[j] = str[j+1];
		}
		str[j] = a;
	}

}