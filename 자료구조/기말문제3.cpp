#include <stdio.h>
#include <stdlib.h>
#define element int

typedef struct TreeNode {
	struct TreeNode* left;
	element data;
	struct TreeNode* right;
}TreeNode;

typedef struct TreeType {
	TreeNode* root;
}TreeType;

void initTree(TreeType* tree) {
	tree->root = NULL;
}

TreeNode* getNode(int data) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

TreeNode* findNodeByData(TreeNode* node, int data) {
	if (node == NULL) {
		return NULL;
	}
	if (node->data == data) {
		return node;
	}
	else {
		TreeNode* left_node = findNodeByData(node->left, data);
		if (left_node != NULL) {
			return left_node;
		}

		TreeNode* right_node = findNodeByData(node->right, data);
		if (right_node != NULL) {
			return right_node;
		}
	}
}

void setChildNode(TreeNode* parent, int ldata, int rdata) {
	
	parent->left = NULL;
	parent->right = NULL;
	if (ldata != 0) {
		parent->left = getNode(ldata);
	}
	if (rdata != 0) {
		parent->right = getNode(rdata);
	}
}

void setNode(TreeType* tree, int data, int ldata, int rdata) {
	if (tree->root == NULL) {
		tree->root = getNode(data);
		setChildNode(tree->root, ldata, rdata);
	}
	else {
		TreeNode* new_node = findNodeByData(tree->root, data);
		setChildNode(new_node, ldata, rdata);
	}
}

int addData(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int left = addData(root->left);
	int right = addData(root->right);
	return (left+right+root->data);
}

int rst = 0;
int inorder(TreeNode* tree) {
	if (tree != NULL) {
		inorder(tree->left);
		int left = addData(tree->left);
		int right = addData(tree->right);
		if(left < right) rst += tree->data;
		inorder(tree->right);
	}
	return rst;
}
int main() {
	int n;
	scanf("%d", &n);

	TreeType tree;
	initTree(&tree);

	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		setNode(&tree, x, y, z);
	}
	inorder(tree.root);
	printf("%d", rst);
}

