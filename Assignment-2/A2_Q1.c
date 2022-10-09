//Name : Omkar Santosh Gavhane
//Roll No : 2111MC08
//MC504 Assignment-2

#include<stdio.h>

void display_array(int *arr,int noe){
	for(int i=0;i<noe;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main(){
	int arr[100],noe,i,j,key;
	printf("Enter number of elements:");
	scanf("%d",&noe);
	printf("Enter %d numbers,press ENTER after each number\n",noe);
	for(i=0;i<noe;i++)
		scanf("%d",&arr[i]);
	printf("[Before Sorting] Elements in an array\n");
	display_array(arr,noe);
	for(i=1;i<noe;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
		
	}
	printf("[After Sorting] Elements in an array\n");
	display_array(arr,noe);
	return(0);
}
