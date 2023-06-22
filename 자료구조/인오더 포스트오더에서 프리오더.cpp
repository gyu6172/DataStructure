#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int array[100000];
int brray[100000];

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* MakeTree(int a_l, int a_r, int b_l, int b_r)
{
	if (a_l > a_r) return NULL;//Ʈ���� �������� ���� ����

	int i;
	int route;

	Node* node = (Node*)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->data = brray[b_r];

	for (i = a_l; i <= a_r; i++)
	{
		if (array[i] == brray[b_r])
		{
			route = i;
			break;
		}
	}

	node->left = MakeTree(a_l, route - 1, b_l, b_l + (route - a_l) - 1);
	node->right = MakeTree(route + 1, a_r, b_l + (route - a_l), b_r - 1);//���� ����Ʈ���� ��� ������ (route - a_l -1) ���� �����Ƿ� ���� ���� �� �� �ִ�.

	return node;
}

void PreOrder(Node* cur)//pre order �Լ�
{
	if (cur == NULL) return;
	printf("%d ", cur->data);
	PreOrder(cur->left);
	PreOrder(cur->right);
}

 

int main()
{
	int i, n;
	Node* Route;

	scanf("%d", &n);
	
	for (i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", &brray[i]);
	}

	Route = MakeTree(0, n - 1, 0, n - 1);

	PreOrder(Route);

	return 0;
}
