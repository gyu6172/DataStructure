#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	char elem;
	Node* prev;
	Node* next;
}Node;
void add(Node* list, int r, int e);
void deleteNode(Node* list, int r);
void get(Node* list, int r);
void print(Node* list);
int main() {
	int n;
	scanf("%d",&n);
	Node *head = (Node*)malloc(sizeof(Node));
	Node *tail = (Node*)malloc(sizeof(Node));
	head->next = tail;
	head->prev = NULL;
	tail->next = NULL;
	tail->prev = head;

	for (int i = 0; i < n; i++) {
		char code;
		getchar();
		scanf("%c",&code);
		if (code == 'A') {
			int r;
			char e;
			scanf("%d %c",&r,&e);
			add(head, r, e);
		}
		else if (code == 'D') {
			int r;
			scanf("%d",&r);
			deleteNode(head, r);
		}
		else if (code == 'G') {
			int r;
			scanf("%d",&r);
			get(head, r);
		}
		else if (code == 'P') {
			print(head);
		}
	}
}

void add(Node* list, int r, int e)
{	
	Node *iter = list;
	if (r == 0) {
		printf("invalid position\n");
		return;
	}
	for (int i = 0; i < r-1; i++) {
		iter = iter->next;
		if (iter->next == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->elem = e;
	newnode->next = iter->next;
	newnode->prev = iter;

	(iter->next)->prev = newnode;
	iter->next = newnode;
}

void deleteNode(Node* list, int r)
{
	Node *iter = list;
	for (int i = 0; i < r; i++) {
		iter = iter->next;
		if (iter == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	if (iter->next == NULL || iter->prev == NULL) {
		printf("invalid position\n");
	}
	else {
		//iter를 삭제하면 된다.
		(iter->next)->prev = iter->prev; 
		(iter->prev)->next = iter->next;
		free(iter);
	}
}

void get(Node* list, int r)
{
	Node *iter = list;
	for (int i = 0; i < r; i++) {
		iter = iter->next;
		if (iter == NULL) {
			printf("invalid position\n");
			return;
		}
	}
	if (iter->next == NULL || iter->prev == NULL) {
		printf("invalid position\n");
	}
	else {
		printf("%c\n", iter->elem);
	}
}

void print(Node* list)
{
	for (Node* iter = list->next; iter->next != NULL; iter = iter->next) {
		printf("%c",iter->elem);
	}
	printf("\n");
}
