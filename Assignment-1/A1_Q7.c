/*Name : Omkar Santosh Gavhane
Roll No : 2111MC08
MC504-Assignment 1
*/
#include<stdio.h>
int main(){
	int no;
	printf("Enter number:");
	scanf("%d",&no);
	while(no>0){
		printf("%d",no%10);//find remainder
		no=no/10;//update the number by truncating last digit by use of division operator
	}
	return(0);
}
