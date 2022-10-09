/*Name : Omkar Santosh Gavhane
Roll No : 2111MC08
MC504-Assignment 1
*/
#include<stdio.h>
int main(){
	int no,sum=0,r,tmp;
	printf("enter number:");
	scanf("%d",&no);
	tmp=no;  //make copy of no
	while(no>0){
		r=no%10; //find remainder
		no=no/10; //update the number i.e truncate the last digit by use of division operator 
		sum+=r*r*r; //find the cube of remainder and add it to sum variable
	}
	if(tmp==sum) //compare sum with tmp 
		printf("%d is Armstrong number",tmp);
	else
		printf("%d is not an Armstrong number",tmp);
	return(0);
}
