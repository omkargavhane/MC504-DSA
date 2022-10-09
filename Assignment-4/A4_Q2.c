//Name:Omkar Santosh Gavhane
//Roll No:2111Mc08
//Assignment-4-Q2
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define strMax 20
typedef struct node{
	char data[strMax];
	struct node *next;
}queueNode;
typedef struct {
	queueNode *head;
	queueNode *tail;
}stringQueue;

void initializeQueue(stringQueue *queue){
	queue->head=NULL;
	queue->tail=NULL;
}
int empty(stringQueue *queue){
	if(queue->head==NULL && queue->tail==NULL)
		return(1);
	return(0);
}
int enqueue(stringQueue *queue,char *item){
	queueNode *node=malloc(sizeof(queueNode));
	strcpy(node->data,item);
	node->next=NULL;
	if(empty(queue))
		queue->head=node;
	else
		queue->tail->next=node;
	queue->tail=node;
	return(strlen(queue->tail->data));
}
char *dequeue(stringQueue *queue){
	char *ret=malloc(sizeof(char)*strMax);
	if(queue->head==NULL)
		printf("[Dequeue Failed]Queue is empty!!!");
	else{
	strcpy(ret,queue->head->data);
	queueNode *tmp=queue->head;
	queue->head=queue->head->next;
	free(tmp);}
	return(ret);
}
void print(stringQueue *queue){
	queueNode *start=queue->head;
	queueNode *stop=queue->tail;
	if(queue->head==NULL)
		printf("[Print Failed] Queue is empty!!");
	else{
	while(start!=stop){
		printf("%s->",start->data);
		start=start->next;
	}
	printf("%s",start->data);
	}
}
int main(){
	int choice;
	char str[strMax];
	stringQueue *queue=malloc(sizeof(stringQueue));
	initializeQueue(queue);
	while(1){
		printf("\n1.Eneueue\n2.Dequeue\n3.Print\n4.Exit");
		printf("\nEnter Choice:");
		scanf("%d",&choice);
		if(choice==1){
			printf("\nEnter String:");
			scanf("%s",str);
			printf("\n%d length string added",enqueue(queue,str));
		}
		else if(choice==2){
			printf("\nDequeued String is %s",dequeue(queue));
		}
		else if(choice==3){
			print(queue);
		}
		else if(choice==4){
			break;
		}
	}
	return(0);
}
