//Name : Omkar Santosh Gavhane
//Roll No : 2111MC08
//MC504 Assignment-1 
#include<stdio.h>

void display_array(int *arr,int noe){
        for(int i=0;i<noe;i++)
		printf("%d ",arr[i]);
         printf("\n");
}
int main(){
	int arr[100],noe,i,j,k=0,arr1[100],flag;
	printf("Enter number of elements:");
	scanf("%d",&noe);
	printf("Enter %d numbers,press ENTER after each number\n",noe);
	for(i=0;i<noe;i++)
		scanf("%d",&arr[i]);
	printf("[with duplicate] Elements in an array\n");
 	display_array(arr,noe);
	for(i=0;i<noe;i++){ // tc of these nested for loop is O(n^2)
		flag=0;
		for(j=0;j<i;j++)
			if(arr[i]==arr[j]){
				flag=1;
				break;
			}
		if(flag==0)
			arr1[k++]=arr[i];	
	}
	printf("[with out duplicates] Elements in an array\n");
	display_array(arr1,k);
}
//tc of these program is O(n^2)
//but by use of hash map tc reduces to O(n)
