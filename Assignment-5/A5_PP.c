// Omkar Gavhane
// Roll No : 2111MC08

#include <stdio.h>
#include <stdlib.h>
struct node {
  	int key;
  	struct node *left, *right;
};
// Create a node
struct node *newNode(int item) {
  	struct node *temp = (struct node *)malloc(sizeof(struct node));
  	temp->key = item;
  	temp->left = temp->right = NULL;
  	return temp;
}
void inorder(struct node *root) {
  	if (root != NULL) {
  	inorder(root->left);
  	printf("%d ", root->key);
  	inorder(root->right);
 	}
}
struct node *insert(struct node *node, int key) {
	if (node == NULL) return newNode(key);
	if (key < node->key)
    	node->left = insert(node->left, key);
  	else
    	node->right = insert(node->right, key);
	return node;
}
struct node *minValueNode(struct node *node) {
	struct node *current = node;
 	while (current && current->left != NULL)
 	current = current->left;
	return current;
}
struct node *deleteNode(struct node *root, int key) {
	if (root == NULL) return root;
  	if (key < root->key)
    	root->left = deleteNode(root->left, key);
  	else if (key > root->key)
    	root->right = deleteNode(root->right, key);
	else{
  	if (root->left == NULL) {
      	struct node *temp = root->right;
      	free(root);
      	return temp;
    	} else if (root->right == NULL) {
      	struct node *temp = root->left;
      	free(root);
      	return temp;
    	}
    	struct node *temp = minValueNode(root->right);
    	root->key = temp->key;
    	root->right = deleteNode(root->right, temp->key);
  	}
  	return root;
}
// main code
int main() {
  	struct node *root = NULL;
 	int temp1;
 	int temp2;
  	while(1)
  	{
   		printf("1.Insert new Node\n2.delete node\n3.print inorder traversal of BST\n4.Exit\n\n");
   		int n;
  		scanf("%d",&n);
  	switch(n)
  	{
  	case 1:
  		
  		printf("Enter value to insert in BST\n\n");
  		scanf("%d",&temp1);
  		root = insert(root, temp1);
  		break;
  	case 2:
  		
  		printf("Enter value to delete in BST\n\n");
  		scanf("%d",&temp2);
  		root = deleteNode(root, temp2);
  		break;
  	case 3:
  		printf("Inorder traversal of BST: ");
  		inorder(root);
  		printf("\n\n");
  		break;
  	case 4:
  		exit(0);
  	default:
  		printf("Please enter valid choice\n\n");
  		break;
  		
  }
  

  }
  	printf("\n");
	return 0;
}
