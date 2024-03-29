#include <stdio.h>
#include <stdlib.h>
int FolderSize;
typedef struct TreeNode{
	int size;
	struct TreeNode* left;
	struct TreeNode* right;
}treeNode;
treeNode* makeNode(int size, treeNode* leftNode, treeNode* rightNode)
{
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->size = size;
	root->left = leftNode;
	root->right = rightNode;
	return root;

}
int preorder_FolderSize(treeNode* root)
{
	if (root) {
		FolderSize += root->size;
		preorder_FolderSize(root->left);
		preorder_FolderSize(root->right);
	}
	return FolderSize;
}
int inorder_FolderSize(treeNode* root)
{
	if (root) {
		preorder_FolderSize(root->left);
		FolderSize += root->size;
		preorder_FolderSize(root->right);
	}
	return FolderSize;
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
	treeNode* F11 = makeNode(120, NULL, NULL);
	treeNode* F10 = makeNode(55, NULL, NULL);
	treeNode* F9 = makeNode(100, NULL, NULL);
	treeNode* F8 = makeNode(200, NULL, NULL);
	treeNode* F7 = makeNode(68, F10, F11);
	treeNode* F6 = makeNode(40, NULL, NULL);
	treeNode* F5 = makeNode(15, NULL, NULL);
	treeNode* F4 = makeNode(2, F8, F9);
	treeNode* F3 = makeNode(10, F6, F7);
	treeNode* F2 = makeNode(0, F4, F5);
	treeNode* F1 = makeNode(0, F2, F3);

	FolderSize = 0;
	printf("\n 내 컴퓨터 용량(전위) : %d M \n", preorder_FolderSize(F1));

	FolderSize = 0;
	printf("\n 내 컴퓨터 용량(중위) : %d M \n", inorder_FolderSize(F1));

	FolderSize = 0;
	printf("\n 내 컴퓨터 용량(후위) : %d M \n", postorder_FolderSize(F1));



}