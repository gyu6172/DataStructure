#include <stdio.h>
#include <stdlib.h>

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode * left;
	struct _bTreeNode * right;
} BTreeNode;


typedef void VisitFuncPtr(BTData data);

BTreeNode * MakeBTreeNode(BTData data)
{
	BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));

	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;

}

void PostorderTraverse(BTreeNode * bt)
{
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d\n", bt->data);
}

BTreeNode * AssignTree(BTreeNode * bt, BTData data) {
	if (bt == NULL){
		bt = MakeBTreeNode(data);
		return bt;
	}
	else if (data < bt->data)
		{
			bt->left=AssignTree(bt->left, data);
		}
	else if (data > bt->data)
		{
			bt->right=AssignTree(bt->right, data);
		}
	return bt;
}


int main(void) 
{
	int u;
	BTreeNode * bt = NULL;
	while (scanf("%d", &u) !=EOF)
	{
		bt = AssignTree(bt, u);
	}
	PostorderTraverse(bt);
}
