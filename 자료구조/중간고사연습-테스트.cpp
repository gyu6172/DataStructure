#include <stdio.h>
int main() {
	//char : 1바이트 : 8비트
	//0000 0000
	//맨 앞자리는 부호를 표현하는데 쓰인다.
	//0이면 양수, 1이면 음수
	//즉, 0111 1111 : 127이 가장 큰 양의 정수
	//1000 0000 : -128이다.
	//1111 1111 : -1이다.
	char c=129;
	printf("%d",c);
}