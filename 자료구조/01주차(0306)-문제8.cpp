#include <stdio.h>
#include <stdlib.h>
typedef struct student {
	char name[8];
	int kor, eng, math;
	double avg;
}Stu;
int main() {
	int n;
	scanf("%d",&n);

	Stu *stus = (Stu*)malloc(sizeof(Stu)*n);

	int i,j;
	for (i = 0; i < n; i++) {
		scanf("%s %d %d %d",&stus[i].name, &stus[i].kor, &stus[i].eng, &stus[i].math);
		int sum = stus[i].kor + stus[i].eng + stus[i].math;
		stus[i].avg = sum / 3.0;
	}

	for (i = 0; i < n; i++) {
		printf("%s %.1f",stus[i].name, stus[i].avg);
		if (stus[i].kor >= 90 || stus[i].eng >= 90 || stus[i].math >= 90) {
			printf(" GREAT");
		}
		if (stus[i].kor < 70 || stus[i].eng < 70 || stus[i].math < 70) {
			printf(" BAD");
		}
		printf("\n");
	}
}