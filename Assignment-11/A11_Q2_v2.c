#define MAX 100
#include<stdio.h>
void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionsort(float arr[],float ts[],float tn[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] > arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
	swap(&ts[min_idx], &ts[i]);
	swap(&tn[min_idx], &tn[i]);

    }
}
void main()
{
	int i,j,nop,capacity;
	float length[MAX],price[MAX],price_per_length[MAX],cur_length=0,max_price=0;
	printf("enter capacity:");
	scanf("%d",&capacity);
	printf("Enter no of pieces:");
	scanf("%d",&nop);
	printf("Enter length of pieces:\n");
	for(i=0;i<nop;i++)
		scanf("%f",&length[i]);
	printf("Enter price of pieces:\n");
	for(i=0;i<nop;i++)
		scanf("%f",&price[i]);
	for(i=0;i<nop;i++)
		price_per_length[i]=price[i]/length[i];
	selectionsort(price_per_length,length,price,nop);
	for(i=0;i<nop;i++)
	{
		printf("\n%f %f %f",price_per_length[i],price[i],length[i]);
	}
	for(i=0;i<nop;i++)
	{
		if(cur_length+length[i]<=capacity)
		{
			cur_length+=length[i];
			max_price+=price[i];
		}
	}
	printf("\n%f\n",max_price);


}

