/*Name : Omkar Santosh Gavhane
Roll No : 2111MC08
MC504-Assignment 1
*/
#include<stdio.h>
int main(){
	int fno=1,sno=1,n,i,no;
	printf("enter number:");
	scanf("%d",&n);
	for(i=3;i<=n;i++){//start the loop from 3 as first and second number is available
		no=fno+sno;//calculate the no as sum of previous two numbers
		fno=sno;//make n-2 variable value as n-1 variable value
		sno=no;//make n-1 variable value as no variable value
	}
	printf("%d",no%100);//as we want last two digit so make mod 100
	return(0);
}
