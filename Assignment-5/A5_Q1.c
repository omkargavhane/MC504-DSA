//Name : Omkar Gavhane
//Roll No : 2111MC08
#include<stdio.h>
#include<stdlib.h>
struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	};
int height(struct TreeNode* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printCurrentLevel(struct TreeNode* root, int level)
{
    if (root == NULL)
    {
     	printf("NULL ");
        return;
     }
    if (level == 1)
        printf("%d ", root->val);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int search(int arr[], int strt, int end, int value)
{
	int i;
	for (i = strt; i <= end; i++) {
		if (arr[i] == value)
			return i;
	}
}

void printLevelOrder(struct TreeNode* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

struct TreeNode* newNode(int data)
{
	struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	node->val = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


int linear_search(int lb,int ub,int *arr,int val){
	int i;
	for(i=lb;i<=ub;i++)
		if(arr[i]==val)
			return(i);
	}
struct TreeNode *construct_binary_tree(int ptr,int lb,int ub,int *pre,int *in){
	int mid;
	if(lb>ub)return NULL;
	struct TreeNode *ret=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	ret->val=pre[ptr++];
	ret->left=NULL;
	ret->right=NULL;
	if(lb==ub) return ret;
	mid=linear_search(lb,ub,in,ret->val);
	ret->left=construct_binary_tree(ptr,lb,mid-1,pre,in);
	ret->right=construct_binary_tree(ptr,mid+1,ub,pre,in);
	return(ret);
	}
struct TreeNode* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;

	if (inStrt > inEnd)
		return NULL;

	struct TreeNode* tNode = newNode(pre[preIndex++]);
       if (inStrt == inEnd)
		return tNode;

	int inIndex = search(in, inStrt, inEnd, tNode->val);
	tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
	tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
	return tNode;
}


void bfs(struct TreeNode *root,int noe){
	struct TreeNode *queue[100];
	int size=0,i,j;
	queue[0]=root;
	size=1;
	for(i=0;i<size;i++){
		if(size<1)
			break;
		struct TreeNode *curr=queue[i];
		for(j=i+1;j<size-1;j++){
			queue[j-1]=queue[j];
			size-=1;
		}
		if(curr==NULL)
			printf("NULL");
		else
			printf("%d",curr->val);
		if(curr!=NULL){
		queue[size]=curr->left;
		queue[size+1]=curr->right;
		size+=2;
		}
	}
	}

int main(){
	int pre[]={3,9,20,15,7},in[]={9,3,15,20,7},i,noe;
	/*printf("Enter No of Elements in Tree:");
	scanf("%d",&noe);
	printf("Enter Preorder traversal\n");
	for(i=0;i<noe;i++)
		scanf("%d",&pre[i]);
	printf("Enter Inorder traversal\n");
	for(i=0;i<noe;i++)
		scanf("%d",&in[i]);
	for(i=0;i<noe;i++)
		printf("\n%d %d",pre[i],in[i]);
	*/
	int len = sizeof(in) / sizeof(in[0]);
	noe=5;
	//struct TreeNode *root=construct_binary_tree(0,0,noe-1,pre,in);
	struct TreeNode* root = buildTree(in, pre, 0, len - 1);
	//bfs(root,noe);
	printLevelOrder(root);
	return(0);
}
