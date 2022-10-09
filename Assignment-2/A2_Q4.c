//Name : Omkar Santsoh Gavhane
//Roll no : 2111MC08
//MC504 Assignment -1


#include<stdio.h>

void display_array(int *arr,int noe){
        for(int i=0;i<noe;i++)
		printf("%d ",arr[i]);
         printf("\n");
}
int *insertion_sort(int *arr,int noe){
	int i,j,key;
	for(i=1;i<noe;i++){
		key=arr[i];
 		j=i-1;
 		while(j>=0 && arr[j]>key){
 		arr[j+1]=arr[j];
 		j--;
 		}
 		arr[j+1]=key;
 	}
	return(arr);
}
int main(){
	int arr[100],noe,i,*arr1,sum=0,tsum=0,j,cnt=0;
	printf("Enter number of elements:");
	scanf("%d",&noe);
	printf("Enter %d numbers,press ENTER after each number\n",noe);
	for(i=0;i<noe;i++)
		scanf("%d",&arr[i]);
	printf("Elements in an array\n");
 	display_array(arr,noe);
	arr1=insertion_sort(arr,noe); // insertion sort complexity O(n^2)
	//display_array(arr1,noe);
	i=0;
	while(i<noe){  // while loops complexity is O(n)
		j=i+1;
		cnt=1;
		tsum=arr1[i];
		while(arr1[j]==arr1[i]){
			cnt+=1;
			tsum+=arr1[j++];
		}
		if(cnt%2!=0)
			sum+=tsum;
		i=j;
	}
	printf("sum is %d",sum);
	return(0);
}
//Overall complexity is O(n^2) but we can use merge sort instead of insertion sort
//to reduce the complexity from O(n^2) to O(nlogn) 
//instead of sorting we can use hash map to further reduce the complexity to O(n)
