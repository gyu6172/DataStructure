#include <stdio.h>
typedef struct time {
	int h,m,s;
}Time;

int main() {
	Time t1, t2;
	scanf("%d %d %d",&t1.h, &t1.m, &t1.s);
	scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

	int t1s = t1.h*3600 + t1.m*60 + t1.s;
	int t2s = t2.h * 3600 + t2.m * 60 + t2.s;

	int d = t2s-t1s;

	printf("%d %d %d",d/3600,d%3600/60,d%60);
}