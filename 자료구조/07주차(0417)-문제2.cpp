#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int elem;
	Node* next;
}Node;
void addNode(Node* head, int elem);
void printList(Node* head);
Node* unionSet(Node* A, Node* B);
Node* intersectSet(Node* A, Node* B);
int main() {
	int Asize;
	scanf("%d",&Asize);
	Node* A = (Node*)malloc(sizeof(Node));
	A->next = NULL;
	for (int i = 0; i < Asize; i++) {
		int elem;
		scanf("%d",&elem);
		addNode(A, elem);
	}

	int Bsize;
	scanf("%d", &Bsize);
	Node* B = (Node*)malloc(sizeof(Node));
	B->next = NULL;
	for (int i = 0; i < Bsize; i++) {
		int elem;
		scanf("%d", &elem);
		addNode(B, elem);
	}

	//printList(A);
	//printList(B);

	Node* uSet = unionSet(A,B);
	Node* iSet = intersectSet(A,B);

	printList(uSet);
	printList(iSet);
}

void addNode(Node* head, int elem)
{
	Node* p = head;
	while (1) {
		if (p->next == NULL) {
			break;
		}
		p = p->next;
	}
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->elem = elem;
	newnode->next = NULL;
	p->next = newnode;
}

void printList(Node* head)
{
	if (head->next == NULL) {
		printf(" 0");
	}
	for (Node* p = head->next; p != NULL; p = p->next) {
		printf(" %d",p->elem);
	}
	printf("\n");
}

Node* unionSet(Node* A, Node* B)
{
	if (A->next == NULL) {
		return B;
	}
	else if (B->next == NULL) {
		return A;
	}
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	Node* p = A->next;
	Node* q = B->next;
	while (1) {
		if (p == NULL && q == NULL) {
			break;
		}
		else if (q==NULL) {
			addNode(head, p->elem);
			p = p->next;
		}
		else if(p==NULL){
			addNode(head, q->elem);
			q = q->next;
		}
		else if (p->elem < q->elem) {
			addNode(head, p->elem);
			p = p->next;
		}
		else if (p->elem > q->elem) {
			addNode(head, q->elem);
			q = q->next;
		}
		else if (p->elem == q->elem) {
			addNode(head, q->elem);
			p = p->next;
			q = q->next;
		}
	}
	return head;
}

Node* intersectSet(Node* A, Node* B)
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	if (A->next == NULL || B->next == NULL) {
		return head;
	}

	for (Node* p = A->next; p != NULL; p = p->next) {
		for (Node* q = B->next; q != NULL; q = q->next) {
			if (p->elem == q->elem) {
				addNode(head, p->elem);
			}
		}
	}

	return head;
}
