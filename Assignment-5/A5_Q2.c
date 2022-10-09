// Omkar Gavhane
// Roll No : 2111MC08

#include <stdio.h>
#include <stdlib.h>

struct node{
 	int key;
  	struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  	struct node *temp = (struct node *)malloc(sizeof(struct node));
  	temp->key = item;
  	temp->left = NULL;
	temp->right = NULL;
  	return temp;
}


void inorder(struct node *root) {
	if (root != NULL) {
  	inorder(root->left);
    	printf("%d ", root->key);
    	inorder(root->right);
  }
}

struct node *insert(struct node *node, int key){
 	if(node == NULL) 
		return newNode(key);
	if(key < node->key)
    		node->left = insert(node->left, key);
  	else
  		node->right = insert(node->right, key);
	return node;
}



// main code
int main(){
  	struct node *root = NULL;
  	int n;
  	printf("Enter Number of element to insert:");
  	scanf("%d",&n);
  	printf("\n");
  	for(int i=0;i<n;i++)
  	{
  		int temp;
  		scanf("%d",&temp);
  		root = insert(root, temp);
  	}
  	printf("Inorder traversal of BST: ");
  	inorder(root);
  	printf("\n");
	return(0);
}
