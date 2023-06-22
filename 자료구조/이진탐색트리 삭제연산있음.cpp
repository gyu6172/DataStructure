#include<stdio.h>
#include<stdlib.h>
 
typedef int element;
 
typedef struct treeNode {
  int key;
  struct treeNode* right; //오른쪽 서브 트리
  struct treeNode* left; //왼쪽 서브 트리
} treeNode;
 
treeNode* searchBST(treeNode *root, int x) {
  treeNode* p = root;
 
  while(p != NULL){
    if( x < p->key) p = p->left;
    else if(x == p->key) return p;
    else p = p->right;
  }
  printf("찾는 키가 없습니다!");
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
  else printf("같은 키 존재");
 
  return p;
}
 
void deleteNode(treeNode *root, element key) {
  treeNode *parent, *p, *succ, *succ_parent;
  treeNode *child;
 
  parent = NULL;
  p = root;
 
  while ((p != NULL) && (p->key != key)) { //삭제할 노드의 위치 탐색
    parent = p;
    if(key < p->key) p = p->left;
    else p = p->right;
  }
 
  //삭제할 노드가 없는 경우
  if(p == NULL) {
    printf("키가 이진 트리에 없음");
    return;
  }
 
  //삭제할 노드가 단말 노드인 경우
  if((p->left == NULL) && (p->right == NULL)) {
    if(parent != NULL) {
      if( parent->left == p) parent->left = NULL;
      else parent->right = NULL;
    }
    else root = NULL;
  }
 
  //삭제할 노드가 자식 노드를 한 개 가진 경우
  else if ((p->left == NULL) || (p->right == NULL)){
    if( p->left != NULL) child = p->left;
    else child = p->right;
 
    if (parent != NULL) {
      if(parent->left == p) parent -> left = child;
      else parent -> right = child;
    }
 
    else root=child;
  }
 
  //삭제할 노드가 자식 노드를 두 개 가진 경우
  else {
    succ_parent = p;
    succ = p->left;
    
    //왼쪽 서브 트리에서 후계자 찾기
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
  treeNode* root = NULL; // BST의 루트 노드

  // 노드 추가
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 7);
  root = insertNode(root, 2);
  root = insertNode(root, 4);
  root = insertNode(root, 6);
  root = insertNode(root, 8);

  // BST 출력
  printf("BST 출력: ");
  inorderTraversal(root);
  printf("\n");

  // 노드 삭제
  int keyToDelete = 3;
  deleteNode(root, keyToDelete);

  // 삭제 후 BST 출력
  printf("노드 %d 삭제 후 BST 출력: ", keyToDelete);
  inorderTraversal(root);
  printf("\n");

  return 0;
}

