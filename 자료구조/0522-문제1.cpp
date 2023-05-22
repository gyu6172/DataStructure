#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	struct TreeNode* left;
	int data;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeRootNode(int size, TreeNode* leftNode, TreeNode* rightNode)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = size;
	root->left = leftNode;
	root->right = rightNode;
	return root;

}

TreeNode* findNodeByNum(TreeNode* node, int rootNum, int num) {
	if(node)
	if (num > rootNum) {
		findNodeByNum(node->left, rootNum*2, num);
	}
	else if (num < rootNum) {
		findNodeByNum(node->right, rootNum*2+1, num);
	}
	else if (num == rootNum) {
		return node;
	}
}

void printNode(TreeNode* node) {
	printf("%d ",node->data);
	if (node->left != NULL) {
		printf("%d ",node->left->data);
	}
	if (node->right != NULL) {
		printf("%d ", node->right->data);
	}
}

int main() {
	TreeNode* F8 = makeRootNode(80, NULL, NULL);
	TreeNode* F7 = makeRootNode(130, NULL, NULL);
	TreeNode* F6 = makeRootNode(120, F7, F8);
	TreeNode* F5 = makeRootNode(90, NULL, NULL);
	TreeNode* F4 = makeRootNode(70, NULL, NULL);
	TreeNode* F3 = makeRootNode(50, NULL, F6);
	TreeNode* F2 = makeRootNode(30, F4, F5);
	TreeNode* F1 = makeRootNode(20, F2, F3);

	int n;
	scanf("%d",&n);

	TreeNode* rstNode = NULL;

	if (n == 1) {
		rstNode = F1;
	}
	else if (n == 2) {
		rstNode = F2;

	}
	else if (n == 3) {
		rstNode = F3;

	}
	else if (n == 4) {
		rstNode = F4;

	}
	else if (n == 5) {
		rstNode = F5;

	}
	else if (n == 6) {
		rstNode = F6;

	}
	else if (n == 7) {
		rstNode = F7;

	}
	else if (n == 8) {
		rstNode = F8;

	}

	if (rstNode == NULL) {
		printf("-1");
	}
	else {
		printNode(rstNode);
	}
}