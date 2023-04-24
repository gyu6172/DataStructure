#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int elem;
	Node* prev;
	Node* next;
}Node;
void addNode(Node* head, int index, int elem);
void deleteNode(Node* head, int index);
void getNodeElement(Node* head, int index);
void printList(Node* head);
void sortList(Node* head);
Node* getMax(Node* head);
Node* getMin(Node* head);
int main() {
	int n;
	scanf("%d",&n);

	Node* list1 = (Node*)malloc(sizeof(Node));
	Node* tail = (Node*)malloc(sizeof(Node));
	list1->next = tail;
	list1->prev = NULL;

	tail->next = NULL;
	tail->prev = list1;

	for (int i = 0; i < n; i++) {
		char code;
		
		getchar();
		scanf("%c",&code);
		if (code == 'A') {
			int index;
			int elem;
			scanf("%d %d", &index, &elem);
			addNode(list1, index, elem);
		}
		else if (code == 'D') {
			int index;
			scanf("%d", &index);
			deleteNode(list1, index);
		}
		else if (code == 'G') {
			int index;
			scanf("%d", &index);
			getNodeElement(list1, index);
		}
		else if (code == 'P') {
			printList(list1);
		}
		else if (code == 'S') {
			sortList(list1);
		}
		else if (code == 'H') {
			printf("maxNum : %d\n", getMax(list1)->elem);
		}
		else if (code == 'L') {
			printf("minNum : %d\n", getMin(list1)->elem);
		}
	}
}

void addNode(Node* head, int index, int elem) {
	Node* p = head;
	for (int i = 0; i < index; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("Invalid Position!\n");
			return;
		}
	}
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->elem = elem;
	newnode->prev = p;
	newnode->next = p->next;

	p->next->prev = newnode;
	p->next = newnode;
}

void deleteNode(Node* head, int index) {
	Node* p = head;
	for (int i = 0; i <= index; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("Invalid Position!\n");
			return;
		}
	}

	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);
}

void getNodeElement(Node* head, int index) {
	Node* p = head;
	for (int i = 0; i <= index; i++) {
		p = p->next;
		if (p->next == NULL) {
			printf("Invalid Position!\n");
			return;
		}
	}

	printf("%d\n",p->elem);
}

void printList(Node* head) {
	for (Node* p = head->next; p->next != NULL; p = p->next) {
		printf("%d ",p->elem);
	}
	printf("\n");
}

void sortList(Node* head)
{
	for (Node* p = head->next; p->next != NULL; p = p->next) {
		for (Node* q = p; q->next != NULL; q = q->next) {
			if (p->elem > q->elem) {
				int tmp = p->elem;
				p->elem = q->elem;
				q->elem = tmp;
			}
		}
	}
}

Node* getMax(Node* head)
{	
	Node* p = head->next;
	Node *maxNode = p;
	for (; p->next != NULL; p = p->next) {
		if (p->elem > maxNode->elem) {
			maxNode = p;
		}
	}
	return maxNode;
}

Node* getMin(Node* head)
{
	Node* p = head->next;
	Node* minNode = p;
	for (; p->next != NULL; p = p->next) {
		if (p->elem < minNode->elem) {
			minNode = p;
		}
	}
	return minNode;
}
