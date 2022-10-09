/*Name : Omkar Santosh Gavhane
Roll No : 2111MC08
MC504-Assignment 1
*/
#include<stdio.h>
int main(){
	int no,i,sum=0;
	printf("Enter number:");
	scanf("%d",&no);
	//for loop to print the each number and sum it
	for(i=1;i<no;i++)
		printf("%d+",i,sum+=i);
	printf("%d=%d",i,sum+i);
	//or we can use direct formula for sum of n natural numbers
	//printf("sum of natural numbers %d",(no*(no+1))/2);
	return(0);
}
