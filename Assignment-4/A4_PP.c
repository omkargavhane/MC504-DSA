#include<stdio.h>

int sumofdigit(int no){
	int sum=0;
	while(no){
	sum+=no%10;
	no=no/10;
	}
	return(sum);
}
int main(){
	int noi,noq,arr[100],que[100],i,j,ai,aj;
	printf("Enter number of integers:");
	scanf("%d",&noi);
	printf("Enter number of queries:");
	scanf("%d",&noq);
	for(i=0;i<noi;i++){
		printf("Enter number:");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<noq;i++){
		printf("Enter Query index:");
		scanf("%d",&que[i]);
	}
	for(i=0;i<noq;i++){
		ai=arr[que[i]-1];
		for(j=que[i];j<noi;j++){
			aj=arr[j];
			if(sumofdigit(ai)>sumofdigit(aj) && ai<=aj){
				printf("\n%d",j+1);
				break;
			}

		}
		if(j==noi)
			printf("\n-1");
	}
	printf("\n");
	return(0);
}
