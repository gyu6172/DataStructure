#include <stdio.h>
typedef struct Student {
	char name[10];
	int score;
}Stu;
int main() {
	Stu stus[5];
	int i,j;
	int sum=0;
	double avg;
	for (i = 0; i < 5; i++) {
		scanf("%s %d",&stus[i].name, &stus[i].score);
		sum += stus[i].score;
	}
	avg = sum / 5.0;

	for (i = 0; i < 5; i++) {
		if (stus[i].score <= avg) {
			printf("%s\n",stus[i].name);
		}
	}
}