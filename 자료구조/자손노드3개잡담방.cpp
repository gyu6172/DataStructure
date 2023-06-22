#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
int result = 0;
typedef struct tree {
   struct tree* left;
   struct tree* right;
   int data;
}Tree;
Tree* makeNode(int data) {
   Tree* node = NULL;
   if (data == 0) {
      return node;
   }
   node = (Tree*)malloc(sizeof(Tree));
   node->data = data;
   node->left = NULL;
   node->right = NULL;

   return node;
}
Tree* insert(Tree* root, int root_d, int left_d, int right_d) {
   if (root == NULL) {
      root = makeNode(root_d);
      root->left = makeNode(left_d);
      root->right = makeNode(right_d);
   }
   else {
      if (root->data == root_d) {
         if (left_d != 0) {
            root->left = makeNode(left_d);
         }
         if (right_d != 0) {
            root->right = makeNode(right_d);
         }
      }
      else {
         root->left = root->left == NULL ? NULL : insert(root->left, root_d, left_d, right_d);
         root->right = root->right == NULL ? NULL : insert(root->right, root_d, left_d, right_d);
      }
   }

   return root;
}
int child_count(Tree* root) {
   if (root == NULL) { return 0; }

   Tree* temp = root;
   int cnt = 0;
   if (temp != NULL) {
      cnt++;
      cnt += child_count(root->left);
      cnt += child_count(root->right);
   }

   return cnt;
}

void problem(Tree* root) {
   if (root == NULL) {
      return;
   }

   Tree* temp = root;

   if (temp != NULL) {
      int child = child_count(temp) - 1;
      result += child >= 3 ? temp->data : 0;
      problem(temp->left);
      problem(temp->right);
   }
}

int main() {
   int n, s;

   Tree* root = NULL;

   scanf("%d", &n);

   for (int i = 0; i < n; i++) {
      int root_d, left_d, right_d;

      scanf("%d %d %d", &root_d, &left_d, &right_d);
      root = insert(root, root_d, left_d, right_d);
   }


   problem(root);
   printf("%d", result);
   
   return 0;
}
