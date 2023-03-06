#include <stdio.h>
int sum(int n);
int main() {
	int x;
	scanf("%d",&x);

	int i,j;
	int total=0;
	for (i = 1; i <= x; i++) {
		total += sum(i);
	}
	printf("%d",total);
}

int sum(int n)
{	
	return n*(n+1)/2;
}
