//Name : Omkar Santosh Gavhane
//Roll No : 2111MC08
//MC504_A7_PP
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
int member(int element,int arr[],int size){
	int j;
	for(int i=0;i<size;i++)
		if(arr[i]==element){
			for(j=i+1;j<size;j++)
				arr[j-1]=arr[j];
			return(1);
		}
	return(0);
}
void main()
{
	int arr[MAX],dep[MAX],timeline[MAX*2],noe,i,ptr=0,emp,max_emp=0,time_max_emp,size_arr,size_dep;
	printf("Enter number of employe:");
	scanf("%d",&noe);
	size_arr=noe;
	size_dep=noe;
	for(i=0;i<noe;i++)
	{
		printf("Arrival time of employee %d:",i+1);
		scanf("%d",&arr[i]);
		timeline[ptr++]=arr[i];
		printf("Deaprture time of employee %d:",i+1);
		scanf("%d",&dep[i]);
		timeline[ptr++]=dep[i];
	}
	quickSort(timeline,0,noe*2-1);//sort the entire timeline using quick sort [from A7_Q1]
	printf("[STATISTICS ACCORDING TO TIMELINE]\n");
	for(i=0;i<noe*2;i++) 
	{
		//iterate over time line array
		//if it is member of arrival array then remove that from arrival
		//increase the emp by 1 and compare it with max_emp set max_emp to emp
		//if emp>max_emp set the time_max_emp=timeline[i] that is current time 
		if(member(timeline[i],arr,size_arr))		{
			size_arr-=1;
			emp+=1;
			if(emp>max_emp){
				max_emp=emp;
				time_max_emp=timeline[i];
			}
		}
		else if(member(timeline[i],dep,size_dep))
		{
			//if member of departure array decrement emp by 1
			size_dep-=1;
			emp-=1;
		}
		printf("%d] emp %d,max_emp %d,time_max_emp %d\n",timeline[i],emp,max_emp,time_max_emp);
	}
	printf("[CONCLUSION]\nTime %d at which there are maximum(%d) employees in the company\n",time_max_emp,max_emp);
}
