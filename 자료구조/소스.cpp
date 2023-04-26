#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int elem;
	Node* link;
}Node;
void addNode(Node* list, int elem) {
	if (list == nullptr) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->elem = elem;
		node->link = nullptr;
		*list = *node;
	}
	else {
		Node* p = list;
		while (1) {
			if (p->link == nullptr) {
				break;
			}
			p = p->link;
		}
		Node* node = (Node*)malloc(sizeof(Node));
		node->elem = elem;
		node->link = nullptr;
		*(p->link) = *node;
	}
}
void printList(Node* list) {
	Node* p = list;
	while (1) {
		if (p == nullptr) {
			break;
		}
		printf("%d ",p->elem);
		p = p->link;
	}
}
int main() {
	int asize;
	scanf("%d",&asize);
	Node* A = nullptr;
	for (int i = 0; i < asize; i++) {
		int n;
		scanf("%d",&n);
		addNode(A,n);
	}
	printList(A);

}