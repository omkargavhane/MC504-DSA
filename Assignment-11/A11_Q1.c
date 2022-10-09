#define MAX 100
#include<stdio.h>
int temp;  
//Function Heapify:
void HEAPIFY(int arr[], int size, int i)  
{  
	int largest = i;    
	int left = 2*i + 1;    
	int right = 2*i + 2;    
  	if (left < size && arr[left] > arr[largest])  
		largest = left;  
  	if (right < size && arr[right] > arr[largest])  
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
	int i,j,g[MAX],s[MAX],nos,noc,cnt=0;
	printf("Number of students:");
	scanf("%d",&nos);
	for(i=0;i<nos;i++)
		scanf("%d",&g[i]);
	printf("Number of cookies:");
	scanf("%d",&noc);
	for(i=0;i<noc;i++)
		scanf("%d",&s[i]);
	HEAPSORT(g,nos);
	HEAPSORT(s,noc);
	for(i=0;i<nos;i++)
	for(j=0;j<noc;j++)
		if(s[j]>=g[i])
		{
			cnt+=1;
			s[j]=-9999;
			break;
		}
	printf("\n%d",cnt);

}

