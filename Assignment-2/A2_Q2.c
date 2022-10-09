//Name : Omkar Santosh Gavhane
//Roll No : 2111MC08
//MC504 Assignment-2

#include<stdio.h>
int main(){
	int no,cnt=0;
	printf("Enter number:");
	scanf("%d",&no);
	printf("Initial value is %d",no);
	if(no<1)
		printf("\nERROR");
	else
		while(no!=1){
			if(no%2==0)
				no/=2;
			else
				no=no*3+1;
			if(no==1)
				printf("\nfinal value is %d",no);
			else
				printf("\nNext value is %d",no);
			cnt+=1;

		}
	printf("\nNumber of Steps is %d\n",cnt);
	return(0);
}
//these is collatz conjecture and whether these algo convergence is not known
//there may be a input for which these algo never converges 
//therefore tc of these algo is not known or may be we called it as it takes infinite time 
