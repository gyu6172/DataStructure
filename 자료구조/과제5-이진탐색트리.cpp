#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}treeNode;
treeNode* makeRootNode(int data, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;

}

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
	treeNode* n16 = makeRootNode(16, NULL, NULL);
	treeNode* n11 = makeRootNode(11, NULL, NULL);
	treeNode* n14 = makeRootNode(14, n11, n16);
	treeNode* n10 = makeRootNode(10, NULL, n14);
	treeNode* n2 = makeRootNode(2, NULL, NULL);
	treeNode* n4 = makeRootNode(4, NULL, NULL);
	treeNode* n5 = makeRootNode(5, n4, NULL);
	treeNode* n3 = makeRootNode(3, n2, n5);
	treeNode* n8 = makeRootNode(8, n3, n10);

	printf("���� ��带 �Է��ϼ���:");
	int node_num;
	scanf("%d",&node_num);

	treeNode* st_node = findNodeByNum(n8, node_num);

	printf("���� ����� ���� ����Ʈ������ ���� ū ���� %d, ", maxNode(st_node)->data);
	printf("���� ���� Ʈ������ ���� ���� ���� %d�Դϴ�.", minNode(st_node)->data);


}