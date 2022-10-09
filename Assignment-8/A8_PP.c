//Name : Omkar Gavhane
//Roll No : 2111MC08
//Assignment-8-PP

#include<stdio.h>
int temp;  
//Function Heapify:
void HEAPIFY(int arr[], int size, int i)  
{  
	int largest = i;    
	int left = 2*i + 1;    
	int right = 2*i + 2;    
  
	if (left < size && arr[left] <arr[largest])  
		largest = left;  
  
	if (right < size && arr[right] < arr[largest])  
		largest = right;  
  
	if (largest != i)  
	{  
		temp = arr[i];  
		arr[i]= arr[largest];   
		arr[largest] = temp;  
		HEAPIFY(arr, size, largest);  
	}  
}  

//Function HeapSort:
void HEAPSORT(int arr[], int size)  
{  
	int i;  
	for (i = size / 2 - 1; i >= 0; i--)  
		HEAPIFY(arr, size, i);  
	for (i=size-1; i>=0; i--)  
	{  
	temp = arr[0];  
	arr[0]= arr[i];   
	arr[i] = temp;  
	HEAPIFY(arr, i, 0);  
	}  
}
void main()
{
	int i,j,noe,arr[100],arr1[100];
	printf("enter number of elements:");
	scanf("%d",&noe);
	for(i=0;i<noe;i++)
	{
		scanf("%d",&arr[i]);
		arr1[i]=arr[i];
	}
	HEAPSORT(arr,noe);//sort array in decresing order using heap sort
	for(i=0;i<noe;i++)
		printf("%d ",arr1[i]);
	printf("\n");
	//iterate over original array and find its index in sorted array
	//if index found to be 0 then it is gold medal
	//if index found to be 1 trhen it is silver medal
	//if index found to be 2 then it is bronze medal
	//if other than (0,1,2) any index is found then print the index+1 that is the position or ranking  of player
	for(i=0;i<noe;i++)
	{
		for(j=0;j<noe;j++)
		{
			if(arr1[i]==arr[j])
			{
				if(j==0)
				printf("Gold Medal,");
				else if(j==1)
				printf("Silver Medal,");
				else if(j==2)
				printf("Bronze Medal,");
				else
				printf("%d,",j+1);

			}
		}
	}
	printf("\n");

}

