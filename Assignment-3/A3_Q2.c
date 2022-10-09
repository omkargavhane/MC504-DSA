//Name : Omkar santosh Gavhane
//Roll no : 2111MC08
//MC504-Assignment-3
//gcc 7.4.0
//C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
		arr[k++]=L[i++];

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
		arr[k++]=R[j++];
}

/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
        // Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
	}
}

void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
int main()
{
	int arr[100],i,len;
	printf("Enter number of elements:");
	scanf("%d",&len);
	printf("Enter elements and press enter:\n");
	for(i=0;i<len;i++)
	    scanf("%d",&arr[i]);
	printf("Given array is \n");
	printArray(arr, len);
    mergeSort(arr,0,len-1);
    printf("\nSorted array is \n");
	printArray(arr, len);
	return 0;
}
/*Space complexity is O(n)
Time complexity 
Best case,average case,worst case:O(nlogn)
*/
