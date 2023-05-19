#include <stdio.h>
#include <stdlib.h>
int FolderSize;
typedef struct TreeNode{
	int size;
	struct TreeNode* left;
	struct TreeNode* right;
}treeNode;
treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->size = size;
	root->left = leftNode;
	root->right = rightNode;
	return root;

}
int preorder_FolderSize(treeNode* root)
{
	int left_size=0, right_size=0;
	if (root == NULL) {
		return 0;
	}

	return (left_size+right_size+root->size);
	left_size = preorder_FolderSize(root->left);
	right_size = preorder_FolderSize(root->right);

}
int inorder_FolderSize(treeNode* root)
{
	int left_size = 0, right_size = 0;
	if (root == NULL) {
		return 0;
	}

	left_size = inorder_FolderSize(root->left);
	return (left_size + right_size + root->size);
	right_size = inorder_FolderSize(root->right);

}
int postorder_FolderSize(treeNode* root)
{
	if (root) {
		postorder_FolderSize(root->left);
		postorder_FolderSize(root->right);
		FolderSize += root->size;
	}
	return FolderSize;
}

int main()
{
	treeNode* F11 = makeRootNode(120, NULL, NULL);
	treeNode* F10 = makeRootNode(55, NULL, NULL);
	treeNode* F9 = makeRootNode(100, NULL, NULL);
	treeNode* F8 = makeRootNode(200, NULL, NULL);
	treeNode* F7 = makeRootNode(68, F10, F11);
	treeNode* F6 = makeRootNode(40, NULL, NULL);
	treeNode* F5 = makeRootNode(15, NULL, NULL);
	treeNode* F4 = makeRootNode(2, F8, F9);
	treeNode* F3 = makeRootNode(10, F6, F7);
	treeNode* F2 = makeRootNode(0, F4, F5);
	treeNode* F1 = makeRootNode(0, F2, F3);

	FolderSize = 0;
	printf("\n 내 컴퓨터 용량(전위) : %d M \n", preorder_FolderSize(F1));

	FolderSize = 0;
	printf("\n 내 컴퓨터 용량(중위) : %d M \n", inorder_FolderSize(F1));

	FolderSize = 0;
	printf("\n 내 컴퓨터 용량(후위) : %d M \n", postorder_FolderSize(F1));



}