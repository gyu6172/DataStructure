#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int FolderSize;
int Sum=0;
 typedef struct treeNode{
 	int size;
 	int num;
 	int descendant_count;
 	struct treeNode* left;
 	struct treeNode* right;
 }treeNode;

treeNode* insertNode(treeNode *p, int x,int o){
	
	treeNode* newnode;
	if(p==NULL){
		treeNode* newnode = (treeNode *)malloc(sizeof(treeNode));
  		newnode->num=0;
  		newnode->descendant_count=0;
  		newnode->size = x;
  		newnode->left = NULL;
  		newnode->right = NULL;
  		return newnode;
  		
		
	}
	if(o==1){
		p->left=insertNode(p->left,x,1);
		
	}
	else if(o==2){
		p->right=insertNode(p->right,x,2);
	}
	return p;
}

/*treeNode* searchNode(treeNode* root,int key)
{
	treeNode* p=root;
  
  while(p!=NULL){
  	if(key<p->size) p=p->left;
  	
  	else if(key>p->size) p=p->right;
  	else return p;
  }
  
  printf("No exist key\n");
  return NULL;
  
}
*/
//좌측에서 큰거  
treeNode* maxNode(treeNode* node)
{
    if (node->left == NULL){
    	
	
     printf("No exist left node\n");
        return NULL;}
        
    else{
	
	node=node->left;
    while (node->right != NULL)
        node = node->right;

    return node;
	}
}

// 우측에서 작은거  
treeNode* minNode(treeNode* node)
{
    if (node->right == NULL){
	
    printf("No exist right node\n");
        return NULL;}
        
    else{
	
	
	node=node->right;
    while (node->left != NULL)
    {
	
        node = node->left;
    }

    return node;
	}
}
int postorder_FolderSize(treeNode* root)
{
  if(root){ 
  postorder_FolderSize(root->left); 
  postorder_FolderSize(root->right);
  printf("%d %d ",root->size,root->descendant_count);
  if(root->descendant_count>=3) Sum+=root->size;
  }
  return FolderSize;
}

void updateDescendantCount(treeNode* root){
    if (root == NULL){
        return;
    }
    
    if (root->left != NULL){
        updateDescendantCount(root->left);
        root->descendant_count += root->left->descendant_count + 1;  // 왼쪽 자식 노드의 자손 노드 개수와 자기 자신을 더함
    }
    
    if (root->right != NULL){
        updateDescendantCount(root->right);
        root->descendant_count += root->right->descendant_count + 1;  // 오른쪽 자식 노드의 자손 노드 개수와 자기 자신을 더함
    }
}

treeNode* searchNode(treeNode* root, int key) {
	if (root == NULL || root->size == key) {
		return root;
	}
	
	treeNode* result = searchNode(root->left, key);
	if (result != NULL) {
		return result;
	}
	
	return searchNode(root->right, key);
}


int main()
{
	
	treeNode* root=NULL;
	int n;
	scanf("%d",&n);
	
	int m,l,r;
	
	
	scanf("%d %d %d",&m,&l,&r);
	root=insertNode(root,m,0);
	
	insertNode(root,l,1);
	insertNode(root,r,2);

	for(int i=0; i<n-1; i++){
		int M,R,L;
		scanf("%d %d %d",&M,&L,&R);
		
	treeNode* parent = searchNode(root, M);	
			
	if(L!=0)parent->left=insertNode(parent->left,L,1);
	if(R!=0)parent->right=insertNode(parent->right,R,2);
	
	
		
	}

  updateDescendantCount(root);
  postorder_FolderSize(root);
  printf("%\n");
  printf("%d",Sum);
  int N;
  scanf("%d",&N);
  
  
  for(int i=0; i<N; i++){
  	char input[100];
  	scanf("%s",&input);
  	getchar();
  	treeNode *start=root;
  	printf("%d ",root->size);
  	
  	for(int j=0; j<strlen(input);j++){
  		
  		if(input[j]=='L'){
  			
  			printf("%d ",start->left->size);
  			start=start->left;
  			
  			
		  }
		else if(input[j]=='R'){
			
			printf("%d ",start->right->size);
			start=start->right;
			
		}
	  }
  	
  	
  	
  }
}






