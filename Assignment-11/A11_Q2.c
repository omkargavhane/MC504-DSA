#define MAX 100
#include<stdio.h>

void main()
{
	int i,j,nop,capacity,mat[MAX][MAX],length[MAX],price[MAX],ft,st;
	printf("enter capacity:");
	scanf("%d",&capacity);
	printf("Enter no of pieces:");
	scanf("%d",&nop);
	printf("Enter length of pieces:\n");
	for(i=1;i<=nop;i++)
		scanf("%d",&length[i]);
	printf("Enter price of pieces:\n");
	for(i=1;i<=nop;i++)
		scanf("%d",&price[i]);
	for(i=0;i<=capacity;i++)
		mat[0][i]=0;
	for(i=0;i<nop;i++)
		mat[i][0]=0;
	for(i=0;i<=nop;i++)
	{
		for(j=0;j<=capacity;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=nop;i++)
	{
		for(j=1;j<=capacity;j++)
		{
				ft=mat[i-1][j];
				if(j-length[i]>=0 && j-length[i]<=capacity)
					st=mat[i-1][j-length[i]]+price[i];
				else
					st=0;
				if(ft>st)
					mat[i][j]=ft;
				else
					mat[i][j]=st;
		}
	}
	for(i=0;i<=nop;i++)
	{
		for(j=0;j<=capacity;j++)
			printf("%d ",mat[i][j]);
		printf("\n");
	}		
	printf("\nMaximum Price we get : %d\n",mat[nop][capacity]);	

}

