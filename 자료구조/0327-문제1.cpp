#include <stdio.h>
int main() {
	int n;
	scanf("%d",&n);

	int arr[100];

	int i;
	for (i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
	}

	int rn;
	scanf("%d",&rn);

	int *p,*q;
	
	for (i = 0; i < rn; i++) {
		int st,ed;
		scanf("%d %d",&st,&ed);

		for (p=&arr[st], q=&arr[ed]; p<q; p++,q--) {
			int tmp = *p;
			*p = *q;
			*q = tmp;
		}
	}

	for (i = 0; i < n; i++) {
		printf(" %d",arr[i]);
	}
}