#include <stdio.h>
#include <stdlib.h>
typedef struct CQueue {
	int front;
	int rear;
	int size;
	int arr[200];
}CQueue;

void init(CQueue* q, int n) {
	q->front = 0;
	q->rear = 0;
	q->size = n;
	for (int i = 0; i < n; i++) {
		q->arr[i] = 0;
	}
}

int isFull(CQueue* q) {
	if ((q->rear + 1) % q->size == q->front) {
		return 1;
	}
	else return 0;
}

int isEmpty(CQueue* q) {
	if (q->rear == q->front) {
		return 1;
	}
	else return 0;
}



int deQueue(CQueue* q) {
	if (isEmpty(q)) {
		exit(0);
	}
	q->front = (q->front+1)%q->size;
	int rst = q->arr[q->front];
	q->arr[q->front] = 0;
	return rst;
}

void print(CQueue* q) {
	for (int i = 0; i < q->size; i++) {
		printf(" %d",q->arr[i]);
	}
	printf("\n");
}
void enQueue(CQueue* q, int n) {
	if (isFull(q)) {
		printf("overflow");
		print(q);
	}
	q->rear = (q->rear + 1) % q->size;
	q->arr[q->rear] = n;
}

void M(CQueue* q) {
	int iter = (q->front+1)%q->size;
	while (!isFull(q)) {
		enQueue(q, q->arr[iter]);
		iter = (iter+1)%q->size;
	}
}

int main() {
	int n;
	scanf("%d",&n);

	CQueue q;
	init(&q, n);

	int m;
	scanf("%d",&m);

	for (int i = 0; i < m; i++) {
		char code;
		getchar();
		scanf("%c",&code);

		if (code == 'I') {
			int e;
			scanf("%d",&e);
			enQueue(&q, e);
		}
		else if (code == 'D') {
			deQueue(&q);
		}
		else if (code == 'P') {
			print(&q);
		}
		else if (code == 'M') {
			M(&q);
		}
	}
}