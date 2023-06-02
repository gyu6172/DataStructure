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
	int node_cnt;
}TreeType;

void getNode(TreeType* tree){

}

int main() {
	int n;
	scanf("%d", &n);

	TreeType tree;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);

	}
}