//Name : Omkar santosh Gavhane
//Roll no : 2111MC08
//MC504-Assignment-3
//gcc 7.4.0
//Number of subarrays whose sum is an even number.

#include  <stdio.h>
int main()
{
	int bin[100001];long long int len,i,j,k,tsum,cnt=0;
    printf("Enter length of array:");
    scanf("%lld",&len);
    printf("Enter elements and press ENTER:\n");
    for(i=0;i<len;i++)
        scanf("%d",&bin[i]);
	for(i=0;i<len;i++){
	    for(j=i;j<len;j++){
	        //index A[i...j] is subarray
	        tsum=0;
	        for(k=i;k<=j;k++)//iterate over the subarray A[i...j]
	            tsum+=bin[k];//find sum of subarray
            if(tsum%2==0)//check if sum is even or not
                cnt+=1;
	    }
	}
	printf("\nNumber of subarrays whose sum is an even number:%lld",cnt);
	return 0;
}