#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}treeNode;

treeNode* newNode(int data)
{
	treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;

}

treeNode* insertNode(treeNode* node, int data) {
	if (node == NULL) {
		return newNode(data);
	}
	if (data < node->data) {
		node->left = insertNode(node->left, data);
	}
	else if (data > node->data) {
		node->right = insertNode(node->right, data);
	}

	return node;
}

treeNode* searchNode(treeNode* root, int num) {
	if (root == NULL) {
		return NULL;
	}
	if (root->data < num) {
		return searchNode(root->right, num);
	}
	else if (root->data > num) {
		return searchNode(root->left, num);
	}
	else {
		return root;
	}

}

treeNode* maxNode(treeNode* node) {
	treeNode* p = node;
	p = p->left;
	treeNode* q = p;
	while (p != NULL) {
		q = p;
		p = p->right;
	}
	return q;
}

treeNode* minNode(treeNode* node) {
	treeNode* p = node;
	p = p->right;
	treeNode* q = p;
	while (p != NULL) {
		q = p;
		p = p->left;
	}
	return q;
}

int main()
{

	treeNode* root = NULL;
	root = insertNode(root, 8);
	root = insertNode(root, 3);
	root = insertNode(root, 10);
	root = insertNode(root, 2);
	root = insertNode(root, 5);
	root = insertNode(root, 14);
	root = insertNode(root, 4);
	root = insertNode(root, 11);
	root = insertNode(root, 16);

	printf("기준 노드를 입력하세요:");
	int node_num;
	scanf("%d", &node_num);

	treeNode* st_node = searchNode(root, node_num);

	printf("기준 노드의 ");
	if (maxNode(st_node) != NULL) {
		printf("좌측 서브트리에서 가장 큰 노드는 %d, ", maxNode(st_node)->data);
	}
	if (minNode(st_node) != NULL) {
		printf("우측 서브 트리에서 가장 작은 노드는 %d입니다.", minNode(st_node)->data);
	}


}