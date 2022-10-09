//Name : Omkar santosh Gavhane
//Roll no : 2111MC08
//MC504-Assignment-3
//gcc 7.4.0
// program to find largest substring
// having count of 0s more than count
// count of 1s.

#include  <stdio.h>
int main()
{
	char bin[100001];long long int len,i,j,c_1,c_0,k,l,r,maxlen=0;
    printf("Enter length of string:");
    scanf("%lld",&len);
    printf("enter Binary string:");
    scanf("%s",bin);
	printf("Binary String is %s and its length is %lld",bin,len);
	for(i=0;i<len;i++){
	    for(j=i;j<len;j++){//index i too j is subarray i.e A[i...j]
	        c_1=0,c_0=0;
	        for(k=i;k<=j;k++){//iterate over subarray A[i...j]
	            if(bin[k]=='1') //check if value is '1'
                    c_1+=1;
                if(bin[k]=='0')//check if value is '0'
                    c_0+=1;
	        }
	        //if count of zero is greater than count of 1 and length of current subarray is 
	        //greater than max subarray length then make max sub array length equal to current sub array length
            if(c_0>c_1 && (j-i+1)>maxlen){
                l=i;
                r=j;
                maxlen=r-l+1;
            }
        }
	}
	printf("\nlength of Maximum Subarray witn count(0)>count(1):%lld",r-l+1);
	return 0;
}