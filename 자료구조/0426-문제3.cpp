#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	char elem;
	struct Node* prev;
	struct Node* next;
}Node;

void addFirst(struct Node* head, char e) {
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->elem = e;
	newnode->prev = head;
	newnode->next = head->next;

	head->next->prev = newnode;
	head->next = newnode;
}
void addLast(struct Node* head, char e) {
	struct Node* p = head->next;
	while (1) {
		if (p->next == NULL) {
			break;
		}
		p = p->next;
	}

	p = p->prev;

	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->elem = e;
	newnode->prev = p;
	newnode->next = p->next;

	p->next->prev = newnode;
	p->next = newnode;
}
void addBefore(struct Node* head, char e, char k) {
	struct Node* p = head->next;
	while (1) {
		if (p->next == NULL) {
			break;
		}
		if (p->elem == k) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		printf("invalid input\n");
		return;
	}

	//struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	//newnode->elem = e;
	//newnode->next = p;
	//newnode->prev = p->prev;

	//p->prev->next = newnode;
	//p->prev = newnode;

	p = p->prev;

	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->elem = e;
	newnode->prev = p;
	newnode->next = p->next;

	p->next->prev = newnode;
	p->next = newnode;
}
void delete1(struct Node* head, char k) {
	struct Node* p = head->next;
	while (1) {
		if (p->elem == k) {
			break;
		}
		p = p->next;
		if (p == NULL)break;
	}
	if (p == NULL || p->prev == head) {
		printf("invalid input\n");
		return;
	}
	p = p->prev;

	p->next->prev = p->prev;
	p->prev->next = p->next;
	free(p);

}
void deleteAll(struct Node* head, char k) {
	struct Node* p = head->next;
	while (1) {
		if (p->elem == k) {
			p->next->prev = p->prev;
			p->prev->next = p->next;
			struct Node* tmp = p;
			p = p->next;
			free(tmp);
		}
		p = p->next;
		if (p == NULL)break;
	}
}
void print(struct Node* head) {
	for (struct Node* p = head->next; p->next != NULL; p = p->next) {
		printf("%c", p->elem);
	}
	printf("\n");
}
void reversePrint(struct Node* head) {
	struct Node* p = head->next;
	for (; p->next != NULL; p = p->next) {

	}
	p = p->prev;
	while (1) {
		if (p == head) {
			break;
		}
		printf("%c", p->elem);
		p = p->prev;
	}
	printf("\n");
}


int main() {
	int n;
	scanf("%d", &n);

	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	struct Node* tail = (struct Node*)malloc(sizeof(struct Node));
	head->next = tail;
	head->prev = NULL;

	tail->next = NULL;
	tail->prev = head;

	for (int i = 0; i < n; i++) {
		char code;

		getchar();
		scanf("%c", &code);

		if (code == 'F') {
			char elem;
			getchar();
			scanf("%c", &elem);
			addFirst(head, elem);
		}
		else if (code == 'L') {
			char elem;
			getchar();
			scanf("%c", &elem);
			addLast(head, elem);
		}
		else if (code == 'A') {
			char elem, k;
			getchar();
			scanf("%c %c", &elem, &k);
			addBefore(head, elem, k);
		}
		else if (code == 'D') {
			char elem;
			getchar();
			scanf("%c", &elem);
			delete1(head, elem);
		}
		else if (code == 'E') {
			char k;
			getchar();
			scanf("%c", &k);
			deleteAll(head, k);
		}
		else if (code == 'P') {
			print(head);
		}
		else if (code == 'R') {
			reversePrint(head);
		}
	}
}


