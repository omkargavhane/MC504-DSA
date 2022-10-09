#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	int vertex;
	struct node* next;
};

struct Graph {
	int numVertices;
	struct node **adjLists;
	int* visited;
};
struct node *createNode(int vertex){
	struct node *n=(struct node*)malloc(sizeof(struct node));
	n->vertex=vertex;
	n->next=NULL;
	return(n);
}
struct Graph *createGraph(int n){
	int i;
	struct node *arr_adjlist[n];
	struct Graph *g=(struct Graph*)malloc(sizeof(struct Graph));
	g->numVertices=n;
	g->adjLists=arr_adjlist;
	for(i=0;i<n;i++){
		g->adjLists[i]=NULL;
	}
	/*for(i=0;i<n;i++){
		struct node *n=createNode(i);
		g->adjLists[i]=n;
	}*/
	return(g);
}
void addEdge(struct Graph* graph, int src, int dest){
	//printf("/0");
	int i;
	struct node *curr;
	struct node *n1;//=createNode(src);
	struct node *n2;//=createNode(dest);
	//add n2 i.e dest in list of src i.e n1
	/*for(i=0;i<graph->numVertices;i++){
		printf("\n%d",graph->adjLists[i]);
	}*/
	//printf("[1]");
	curr=graph->adjLists[src];
	printf("curr %d",curr);
	if(curr==NULL){
		printf("src null");
		curr=n2;
	}
	else{
		while(curr->next)
			curr=curr->next;
		curr->next=n2;
	}
	//add n1 i.e src in list of dest i.e n2
	//printf("[2]");
	curr=graph->adjLists[dest];
	printf("curr %d",curr);
	if(curr==NULL){
		printf("dest null");
		curr=n1;
	}
	else{
		while(curr->next)
			curr=curr->next;
		curr->next=n1;
	}
	n1=createNode(src);
	n2=createNode(dest);
	//printf("[3]");
}
void printGraph(struct Graph *graph){
	int i;
	struct node *curr;
	for(i=0;i<graph->numVertices;i++){
		printf("Node %d Adjacency list :",i);
		curr=graph->adjLists[i];
		while(curr){
			printf("%d ",curr->vertex);
			curr=curr->next;
		}
		printf("\n");
	}
}
int main(){	
	int noe,nov,i,u,v;
	char edge[10];
	printf("Enter number of vertices:");
	scanf("%d",&nov);
	struct Graph *g=createGraph(nov);
	for(i=0;i<nov;i++)
		printf("\n%d",g->adjLists[i]);
	printf("Number of Edges:");
	scanf("%d",&noe);
	for(i=0;i<noe;i++){
		printf("Enter edge:");
		scanf("%s",edge);
		u=edge[0]-'0';
		v=edge[1]-'0';
		addEdge(g,u,v);
	}
	printGraph(g);
}
	
