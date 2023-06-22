#include<stdio.h>
#include<stdlib.h>
 
typedef int element;
 
typedef struct treeNode {
  int key;
  struct treeNode* right; //������ ���� Ʈ��
  struct treeNode* left; //���� ���� Ʈ��
} treeNode;
 
treeNode* searchBST(treeNode *root, int x) {
  treeNode* p = root;
 
  while(p != NULL){
    if( x < p->key) p = p->left;
    else if(x == p->key) return p;
    else p = p->right;
  }
  printf("ã�� Ű�� �����ϴ�!");
  return p;
}
 
treeNode* insertNode(treeNode *p, int x) {
  treeNode *New;
 
  if(p == NULL) {
    New = (treeNode*)malloc(sizeof(treeNode));
    New->key = x;
    New->right=NULL;
    New->left=NULL;
    return New;
  }
 
  else if(x < p->key) p->left = insertNode(p->left,x);
  else if(x > p->key) p->right = insertNode(p->right,x);
  else printf("���� Ű ����");
 
  return p;
}
 
void deleteNode(treeNode *root, element key) {
  treeNode *parent, *p, *succ, *succ_parent;
  treeNode *child;
 
  parent = NULL;
  p = root;
 
  while ((p != NULL) && (p->key != key)) { //������ ����� ��ġ Ž��
    parent = p;
    if(key < p->key) p = p->left;
    else p = p->right;
  }
 
  //������ ��尡 ���� ���
  if(p == NULL) {
    printf("Ű�� ���� Ʈ���� ����");
    return;
  }
 
  //������ ��尡 �ܸ� ����� ���
  if((p->left == NULL) && (p->right == NULL)) {
    if(parent != NULL) {
      if( parent->left == p) parent->left = NULL;
      else parent->right = NULL;
    }
    else root = NULL;
  }
 
  //������ ��尡 �ڽ� ��带 �� �� ���� ���
  else if ((p->left == NULL) || (p->right == NULL)){
    if( p->left != NULL) child = p->left;
    else child = p->right;
 
    if (parent != NULL) {
      if(parent->left == p) parent -> left = child;
      else parent -> right = child;
    }
 
    else root=child;
  }
 
  //������ ��尡 �ڽ� ��带 �� �� ���� ���
  else {
    succ_parent = p;
    succ = p->left;
    
    //���� ���� Ʈ������ �İ��� ã��
    while(succ->right != NULL) {
      succ_parent = succ;
      succ = succ->right;
    }
    
    if (succ_parent -> left == succ) succ_parent -> left = succ->left;
    else succ_parent->right = succ->left;
 
    p->key = succ->key;
    p=succ;
  }
 
  free(p);
}


void inorderTraversal(treeNode* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
  }
}

int main() {
  treeNode* root = NULL; // BST�� ��Ʈ ���

  // ��� �߰�
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 7);
  root = insertNode(root, 2);
  root = insertNode(root, 4);
  root = insertNode(root, 6);
  root = insertNode(root, 8);

  // BST ���
  printf("BST ���: ");
  inorderTraversal(root);
  printf("\n");

  // ��� ����
  int keyToDelete = 3;
  deleteNode(root, keyToDelete);

  // ���� �� BST ���
  printf("��� %d ���� �� BST ���: ", keyToDelete);
  inorderTraversal(root);
  printf("\n");

  return 0;
}

