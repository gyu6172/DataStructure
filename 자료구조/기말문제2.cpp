#include <stdio.h>
#include <stdlib.h>
typedef struct CQueue {
	int front;
	int rear;
	int size;
	int* arr;
}CQueue;

void init(CQueue* q, int n) {
	q->front = 0;
	q->rear = 0;
	q->size = n;
	q->arr = (int*)malloc(sizeof(int)*n);
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
	q->front = (q->front + 1) % q->size;
	int rst = q->arr[q->front];
	q->arr[q->front] = 0;
	return rst;
}

void print(CQueue* q) {
	for (int i = 0; i < q->size; i++) {
		printf(" %d", q->arr[i]);
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


int main() {
	int n;
	scanf("%d",&n);

	CQueue q;
	init(&q, n+1);

	for (int i = 1; i <= n; i++) {
		enQueue(&q, i);
	}
	print(&q);
	int rst;
	while (1) {
		rst = deQueue(&q);
		if (isEmpty(&q)) {
			break;
		}
		print(&q);
		int n = deQueue(&q);
		enQueue(&q, n);
		print(&q);

	}
	printf("%d",rst);
}