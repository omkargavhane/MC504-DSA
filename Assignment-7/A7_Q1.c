//Name : Omkar Santosh Gavhane
//Roll No : 2111MC08
//MC504_A7
#define MAX 100
#include<stdio.h>
void swap(int* a, int* b)
{	
	//swap function which uses call by reference
	int t = *a;
	*a = *b;
	*b = t;
}

int partition (int arr[], int low, int high)
{
	int pivot_index=(low+high)/2;//select middle element as pivot index
	swap(&arr[pivot_index],&arr[high]);//replace it with inde high
	int pivot = arr[high];//pivot element
	//i pointer is for the left subarray it acts as upper index of left subarray
	//i.e index [low,i] will have element <= pivot element
	//j pointer is for the right subarray it acts as upper index of right subarray
	//i.e index[i+1,j] will have element >= pivot element
	//after the for loop we will swap i+1 element with high index element 
	int i = (low - 1);
	for (int j=low; j<=high- 1; j++)
		if (arr[j]<=pivot)
			swap(&arr[++i],&arr[j]);
	swap(&arr[i+1],&arr[high]);
	return(i+1);
}
void quickSort(int arr[], int low, int high)
{
	if(low<high)
	{	//call to partition to place middle element of array in its correct position
		int pi = partition(arr, low, high);
		//recursicvely solve the left part 
		quickSort(arr, low, pi - 1);
		//recursively solve the right part
		quickSort(arr, pi + 1, high);
	}

}

int main()
{
	int arr[MAX],n,i;
	printf("Enter number of elements:");
	scanf("%d",&n);
	printf("Enter %d elements hit <ENTER> after each element\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	quickSort(arr, 0, n-1);
	printf("The sorted array is:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;

}
//Space complexity : BigOh(n)
//Time Complexity:
//Best case :BigOh(nlogn)
//Average case : BigOh(nlogn)
//Worst case : BigOh(n^2)
