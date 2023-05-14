#include <stdio.h>
#include <stdlib.h>
#define Element int
typedef struct Queue {
	int size;
	int front;
	int rear;
	Element* data;
}Queue;
void initQueue(Queue* q, int size) {
	q->size = size;
	q->front = 0;
	q->rear = 0;
	q->data = (Element*)calloc(size, sizeof(Element));
}
int isFull(Queue* q) {
	if ((q->rear + 1) % (q->size) == (q->front) % (q->size)) {
		return 1;
	}
	else {
		return 0;
	}
}
int isEmpty(Queue* q) {
	if (q->front == q->rear) {
		return 1;
	}
	else {
		return 0;
	}
}
void printQueue(Queue* q) {
	for (int i = 0; i < q->size; i++) {
		printf("%d ", q->data[i]);
	}
	printf("\n");
}
void insertElement(Queue* q, Element elem) {
	if (isFull(q)) {
		printf("overflow ");
		printQueue(q);
		return;
	}
	else {
		q->rear = (q->rear+1)%(q->size);
		q->data[q->rear] = elem;

	}
}
void deleteElement(Queue* q) {
	if (isEmpty(q)) {
		printf("underflow\n");
		return;
	}
	else {

		q->front = (q->front+1)%(q->size);
		q->data[q->front] = 0;
	}
}

int main() {
	Queue queue;
	queue.front = 0;
	queue.rear = 0;

	int q;
	scanf("%d", &q);
	initQueue(&queue, q);

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getchar();
		char code;
		scanf("%c", &code);
		int elem;
		switch (code) {
		case 'I':
			scanf("%d", &elem);
			insertElement(&queue, elem);
			break;

		case 'D':
			deleteElement(&queue);
			break;

		case 'P':
			printQueue(&queue);
			break;
		}
	}

}