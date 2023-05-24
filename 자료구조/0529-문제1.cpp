#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	struct TreeNode* left;
	int id;
	int data;
	struct TreeNode* right;
}TreeNode;

TreeNode* makeRootNode(int id, int size, TreeNode* leftNode, TreeNode* rightNode)
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = size;
	root->id = id;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

TreeNode* findNodeById(TreeNode* root, int id) {
	if (root == NULL) {
		return NULL;
	}
	if(root->id==id){return root;}

	TreeNode* left_root = findNodeById(root->left, id);
	if (left_root != NULL) {
		return left_root;
	}

	TreeNode* right_root = findNodeById(root->right, id);
	if (right_root != NULL) {
		return right_root;
	}
}


void printNodeByPreorder(TreeNode* root) {
	if (root) {
		printf(" %d",root->data);
		printNodeByPreorder(root->left);
		printNodeByPreorder(root->right);
	}
}

void printNodeByInorder(TreeNode* root) {
	if (root) {
		printNodeByInorder(root->left);
		printf(" %d", root->data);
		printNodeByInorder(root->right);
	}
}

void printNodeByPostorder(TreeNode* root) {
	if (root) {
		printNodeByPostorder(root->left);
		printNodeByPostorder(root->right);
		printf(" %d", root->data);
	}
}

int main() {
	TreeNode* F8 = makeRootNode(8, 80, NULL, NULL);
	TreeNode* F7 = makeRootNode(7, 130, NULL, NULL);
	TreeNode* F6 = makeRootNode(6, 120, F7, F8);
	TreeNode* F5 = makeRootNode(5, 90, NULL, NULL);
	TreeNode* F4 = makeRootNode(4, 70, NULL, NULL);
	TreeNode* F3 = makeRootNode(3, 50, NULL, F6);
	TreeNode* F2 = makeRootNode(2, 30, F4, F5);
	TreeNode* root = makeRootNode(1, 20, F2, F3);

	int m, id;
	scanf("%d %d",&m, &id);

	TreeNode* start_node = findNodeById(root, id);
	
	if (start_node == NULL) {
		printf("-1");
		return 0;
	}

	if (m == 1) {
		printNodeByPreorder(start_node);
	}
	else if (m == 2) {
		printNodeByInorder(start_node);
	}
	else if (m == 3) {
		printNodeByPostorder(start_node);
	}


}