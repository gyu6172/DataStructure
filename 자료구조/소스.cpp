//head에 메모리를 할당 해줘야 한다?
//연결리스트에서 데이터를 삽입할때는 포인터가 가리키는 노드 뒤에 삽입한다.
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int elem;
	Node* link;
}Node;
typedef struct List {
	Node* head;
}List;
void addNode(List* list, int elem) {
	if (list->head == NULL) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->elem = elem;
		node->link = nullptr;
		list->head = node;
	}
	else {
		Node* p = list->head;
		while (1) {
			if (p->link == NULL) {
				break;
			}
			p = p->link;
		}
		Node* node = (Node*)malloc(sizeof(Node));
		node->elem = elem;
		node->link = NULL;
		p->link = node;
	}
}
void printList(List* list) {
	Node* p = list->head;
	while (1) {
		if (p == NULL) {
			break;
		}
		printf("%d ", p->elem);
		p = p->link;
	}
	printf("\n");
}
int intersect(List* A, List* B) {

	Node* p = A->head;
	Node* q = B->head;

	if (p == NULL || q == NULL) {
		if (p == NULL) {
			return 0;
		}
		else if (q == NULL) {
			return p->elem;
		}
	}

	while (p != NULL && q != NULL) {
		if (p->elem < q->elem) {
			return p->elem;
		}
		else if (p->elem > q->elem) {
			q = q->link;
		}
		else if (p->elem == q->elem) {
			p = p->link;
			q = q->link;
		}
	}
	if (p == NULL) {
		return 0;
	}
	else if (q == NULL) {
		return p->elem;
	}


}
int main() {
	int asize;
	scanf("%d", &asize);
	List A = { NULL };
	for (int i = 0; i < asize; i++) {
		int n;
		scanf("%d", &n);
		addNode(&A, n);
	}

	int bsize;
	scanf("%d", &bsize);
	List B = { NULL };
	for (int i = 0; i < bsize; i++) {
		int n;
		scanf("%d", &n);
		addNode(&B, n);
	}

	List C = { NULL };

	//printList(&A);
	//printList(&B);

	printf("%d", intersect(&A, &B));

}