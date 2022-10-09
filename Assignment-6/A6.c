//NAME : Omkar Gavhane
//Roll No : 2111MC08
#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int numVertices;
  int* visited;

  // We need int** to store a two dimensional array.
  // Similary, we need struct node** to store an array of Linked lists
  struct node** adjLists;
};

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n head ", v);
    while (temp) {
      printf("-> %d ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

void enqueue(int *queue,int *rear,int val){
	queue[*rear]=val;
	*rear=*rear+1;
}
int dequeue(int *queue,int *rear){
	int i,ret=queue[0];
	for(i=1;i<(*rear);i++)
		queue[i-1]=queue[i];
	rear-=1;
	return(ret);
}
int bfs(struct Graph *graph,int src,int dest){
	int queue[100],front=0,rear=0,i,ret;
	struct node *curr;
	enqueue(queue,&rear,src);
	while(1){
		for(i=0;i<rear;i++){
			ret=dequeue(queue,&rear);
			if(ret==dest){
				printf("Found");
				return(1);
			}
			curr=graph->adjLists[ret];
			while(curr){
				enqueue(queue,&rear,curr->vertex);
				curr=curr->next;
			}
		}
	}
	return(0);
}

int main() {
  struct Graph* graph = createGraph(5);
  int n,x,y,src,dest;
  while(1){
      printf("Enter the choice :\n1.Create graph\n2.Add edge\n3.Print\n4.BFS\n5.Exit\n\n");
      int choice;
  	scanf("%d",&choice);
    switch(choice){
        
        case 1:
            printf("Enter number of nodes in graph");
            scanf("%d",&n);
            struct Graph* graph = createGraph(n);
            printf("\n");
            break;
  	    case 2:
  		    printf("Enter source and destination node : ");
  		    scanf("%d %d",&x,&y);
  		    addEdge(graph, x, y);
  		    printf("\n");
  		    break;
  	    case 3:
  		    printf("Graph using Adjacency list : ");
  		    printGraph(graph);
  	    	printf("\n");
  		    break;
  	    case 4:
		    printf("enter source node:");
		    scanf("%d",&src);
		    printf("enter dest node:");
		    scanf("%d",&dest);
		    bfs(graph,src,dest);
  		    //printf("path: ");
  		    printf("\n\n");
  		    break;
  	    case 5:
  		    exit(0);
    	default:
  		    printf("Enter valid choice : ");
  		    printf("\n");
  		    break;
  		}
  }
  return 0;
}
