#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}treeNode;

treeNode* findNodeByNum(treeNode* root, int num) {
	if (root->data < num) {
		return findNodeByNum(root->right, num);
	}
	else if (root->data > num) {
		return findNodeByNum(root->left, num);
	}
	else {
		return root;
	}

}

treeNode* makeNode(int data, treeNode* root)
{
	treeNode* node = (treeNode*)malloc(sizeof(treeNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	if (root == NULL) {
		root = node;
		return root;
	}
	else {
		while (true) {
			if (root->data < data) {
				root = root->right;
			}
			else if (root->data > data) {
				root = root->left;
			}
			else {
				return root;
			}
		}
		
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
	//treeNode* n16 = makeNode(16, NULL, NULL);
	//treeNode* n11 = makeNode(11, NULL, NULL);
	//treeNode* n14 = makeNode(14, n11, n16);
	//treeNode* n10 = makeNode(10, NULL, n14);
	//treeNode* n2 = makeNode(2, NULL, NULL);
	//treeNode* n4 = makeNode(4, NULL, NULL);
	//treeNode* n5 = makeNode(5, n4, NULL);
	//treeNode* n3 = makeNode(3, n2, n5);
	//treeNode* n8 = makeNode(8, n3, n10);
	treeNode *root;
	root = makeNode(8, root);

	printf("���� ��带 �Է��ϼ���:");
	int node_num;
	scanf("%d",&node_num);

	treeNode* st_node = findNodeByNum(n8, node_num);

	printf("���� ����� ���� ����Ʈ������ ���� ū ���� %d, ", maxNode(st_node)->data);
	printf("���� ���� Ʈ������ ���� ���� ���� %d�Դϴ�.", minNode(st_node)->data);


}