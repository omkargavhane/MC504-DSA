//Name:Omakar Santsoh Gavhane
//Roll No:2111MC08
//Assignment-4-Q1 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(char *stack,int size,char val,int *ptr){
	if(*ptr+1>=size){
		printf("\nOverflow");
		exit(0);
	}
	stack[(*ptr)++]=val;
}
void print_stack(char *stack,int ptr){
	int i;
	for(i=0;i<ptr;i++)
		printf("%c",stack[i]);
}

char pop(char *stack,int *ptr){
	char ret;
	if(*ptr-1<0){
		printf("\nUnderflow");
		exit(0);
	}
	ret=stack[--(*ptr)];
	return(ret);
}

int main(){
	char str[100],stack[100];
	int size,ptr=0,i;
	printf("Enter string :");
	scanf("%s",str);
	size=strlen(str);
	for(i=0;i<size/2;i++)
		push(stack,size,str[i],&ptr);
	for(i=0;i<ptr;i++)
		printf("%c",stack[i]);
	if(size%2!=0)
		i+=1;
	while(i<size)
		if(pop(stack,&ptr)!=str[i++])
			break;
	if(i==size)
		printf("\n%s is Pallindrome",str);
	else
		printf("\n%s is Not Pallindrome",str);
	return(0);
}
