#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int elem;
	Node* next;
}Node;
int subset(Node* a, Node* b);
int main() {
	int asize;
	scanf("%d",&asize);
	Node* A=nullptr;
	for (int i = 0; i < asize; i++) {
		int n;
		scanf("%d",&n);
		if (A == nullptr) {
			Node* newnode = (Node*)malloc(sizeof(Node));
			newnode->elem = n;
			newnode->next = nullptr;
			A = newnode;
		}
		else {
			Node* p = A;
			while (1) {
				if (p->next == nullptr) {
					break;
				}
				p = p->next;
			}
			Node* newnode = (Node*)malloc(sizeof(Node));
			newnode->elem = n;
			newnode->next = nullptr;
			p->next = newnode;
		}
	}

	int bsize;
	scanf("%d", &bsize);
	Node* B=nullptr;
	for (int i = 0; i < bsize; i++) {
		int n;
		scanf("%d", &n);
		if (B == nullptr) {
			Node* newnode = (Node*)malloc(sizeof(Node));
			newnode->elem = n;
			newnode->next = nullptr;
			B = newnode;
		}
		else {
			Node* p = B;
			while (1) {
				if (p->next == nullptr) {
					break;
				}
				p = p->next;
			}
			Node* newnode = (Node*)malloc(sizeof(Node));
			newnode->elem = n;
			newnode->next = nullptr;
			p->next = newnode;
		}
	}

	printf("%d",subset(A,B));
}

int subset(Node* a, Node* b)
{
	if (a == nullptr) {
		return 0;
	}
	else {
		for (Node* p = a; p != NULL; p = p->next) {
			int flag=0;	
			for (Node* q = b; q != NULL; q = q->next) {
				if(p->elem == q->elem) {
					flag=1;
					break;
				}
			}
			if (flag == 0) {
				return p->elem;
			}
		}
		return 0;
	}
}
