#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Element int
typedef struct Node {
	struct Node* llink;
	struct Node* rlink;
	Element elem;
}Node;
typedef struct Deque {
	Node *front;
	Node *rear;
}Deque;
void initDeque(Deque* dq) {
	dq->front = NULL;
	dq->rear = NULL;
}
int isEmpty(Deque* dq) {
	if (dq->front == NULL && dq->rear == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
void addFront(Deque* dq, Element x) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->elem = x;
	if (isEmpty(dq)) {
		node->rlink = NULL;
		node->llink = NULL;
		dq->front = node;
		dq->rear = node;
		return;
	}
	node->llink = NULL;
	node->rlink = dq->front;

	dq->front->llink = node;
	dq->front = node;
}
void addRear(Deque* dq, Element x) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->elem = x;
	if (isEmpty(dq)) {
		node->rlink = NULL;
		node->llink = NULL;
		dq->front = node;
		dq->rear = node;
		return;
	}
	node->llink = dq->rear;
	node->rlink = NULL;

	dq->rear->rlink = node;
	dq->rear = node;
}
void print(Deque* dq) {
	Node* iter = dq->front;
	while (iter != NULL) {
		printf(" %d", iter->elem);
		iter = iter->rlink;
	}
	printf("\n");
}
void deleteFront(Deque* dq) {
	if (isEmpty(dq)) {
		printf("underflow\n");
		exit(0);
	}

	Node* tmp = dq->front;
	if (tmp->rlink == NULL) {
		free(tmp);
		initDeque(dq);
		return;
	}
	dq->front = tmp->rlink;
	dq->front->llink = NULL;
	free(tmp);
}
void deleteRear(Deque* dq) {
	if (isEmpty(dq)) {
		printf("underflow\n");
		exit(0);
	}

	Node* tmp = dq->rear;
	if (tmp->llink == NULL) {
		free(tmp);
		initDeque(dq);
		return;
	}
	dq->rear = tmp->llink;
	dq->rear->rlink = NULL;
	free(tmp);
}
int main() {
	Deque dq;
	initDeque(&dq);

	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		char order[3];
		getchar();
		scanf("%s",order);
		Element elem;
		if (strcmp(order, "AF") == 0) {
			scanf("%d",&elem);
			addFront(&dq, elem);
		}
		else if (strcmp(order, "AR") == 0) {
			scanf("%d", &elem);
			addRear(&dq, elem);
		}
		else if (strcmp(order, "DF") == 0) {
			deleteFront(&dq);
		}
		else if (strcmp(order, "DR") == 0) {
			deleteRear(&dq);
		}
		else if (strcmp(order, "P") == 0) {
			print(&dq);
		}
	}
}