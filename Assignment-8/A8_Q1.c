//Name : Omkar Gavhane
//Roll No : 2111MC08
//Assignment-8-Q1

#define MAX_STRING_SIZE 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int temp;  
//Heapify:
void HEAPIFY(char arr[], int size, int i)  
{  
	int largest = i;    
	int left = 2*i + 1;    
	int right = 2*i + 2;    
  	if (left < size && arr[left] <arr[largest])  
		largest = left;  
  	if (right < size && arr[right] < arr[largest])  
		largest = right;  
  	if(largest != i)  
	{  
		temp = arr[i];  
		arr[i]= arr[largest];   
		arr[largest] = temp;  
		HEAPIFY(arr, size, largest);  
	}  
}  

//HeapSort:
void HEAPSORT(char arr[], int size)  
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
void revstr(char *str1)  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  
void main()
{
	int i,j,k,notc,*keys,string_len,ptr;
	char arr1[MAX_STRING_SIZE],arr2[MAX_STRING_SIZE];
	char new_arr1[MAX_STRING_SIZE],new_arr2[MAX_STRING_SIZE];
	char output[MAX_STRING_SIZE],new_output[MAX_STRING_SIZE];
	printf("Enter number of testcases:");
	scanf("%d",&notc);
	//declaring an 2D char array to hold testcases
	char **testcases=(char**)calloc(notc,sizeof(char*));
	for(i=0;i<notc;i++)
		testcases[i]=(char*)calloc(MAX_STRING_SIZE,sizeof(char));
	//define key array according to testcases
	keys=(int*)calloc(notc,sizeof(int));
	//take input from user i.e string and key
	for(i=0;i<notc;i++)
	{
		printf("[%d]Enter Encrypted String:",i+1);
		scanf("%s",testcases[i]);
		printf("[%d]Enter Key:",i+1);
		scanf("%d",&keys[i]);
	}
	//for(i=0;i<notc;i++)
	//	printf("%s,%d\n",testcases[i],keys[i]);
	//Iterating over all testcases
	for(i=0;i<notc;i++)
	{
		printf("[%d]Encrypted Message=%s\n",i+1,testcases[i]);
		ptr=0;//pointer to store characters in new_output array i.e result array
		strcpy(arr1,testcases[i]);//make copy of current string into arr1
		strcpy(arr2,arr1);//make copy of current string into arr2
		string_len=strlen(testcases[i]);//length of current string
		arr1[string_len]='\0';//appending end character to arr1
		arr2[string_len]='\0';//appending end character to arr2
		printf("string length=%d\n",string_len);
		HEAPSORT(arr1,strlen(arr1));//sort the arr1 that is current string(encrypted string) in  reverse lexigrophical order
		printf("arr1=%s,arr2=%s\n",arr1,arr2);
		new_arr1[0]=arr1[0];//initializing new_arr1's oth index with arr1's first charcter
		new_arr2[0]=arr2[0];//initializing new_arr2's oth index with arr2's first charcter
		new_arr1[string_len]='\0';//appending end charcter to new_arr1
		new_arr2[string_len]='\0';//appending end charcter to new_arr2
		//we need to make the cyclic arrangement from given first and last charcters of string we have
		//for that will search last character of previous string in arr1 if found append it to new arr 
		for(j=1;j<string_len;j++)
		{
			for(k=1;k<string_len;k++)
				if(arr1[k]==new_arr2[j-1])
					break;
			new_arr1[j]=arr1[k];
			new_arr2[j]=arr2[k];
		}
		printf("new_arr1=%s,new_arr2=%s\n",new_arr1,new_arr2);
		revstr(new_arr1);//reverse of new_arr1
		strcpy(output,new_arr1);//copy new_arr1 to output because we have successfully finded the orderr among the letter
		output[string_len]='\0';//appending end character to output 
		printf("Output=%s\n",output);
		for(j=0;j<string_len;j++)//find the index(k) of first character of encrypted string in output string
			if(output[j]==testcases[i][0])
				k=j-(keys[i]-1);
		printf("k=%d\n",k);
		//copy the value at index from k to string length of output array to new_output array
		for(j=k;j<string_len;j++)
			new_output[ptr++]=output[j];
		printf("new_Output=%s\n",new_output);
		//copy the valur at index from 0 to k-1 of output array to new_output array
		for(j=0;j<k;j++)
			new_output[ptr++]=output[j];
		new_output[ptr++]='\0';//appending end character to new_output
		printf("[%d]Decrypted Message=%s\n\n",i+1,new_output);
	}
	
}
