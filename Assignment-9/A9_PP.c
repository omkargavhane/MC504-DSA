//Name : Omkar Gavhane
//Roll No : 2111MC08
//MC504-Assignment-9-PP

#define MAX_STRING_SIZE 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
	int nopp,i,j,string_len,flag=0;
	char temp[MAX_STRING_SIZE];//temporary variable 
	scanf("%d",&nopp);//no of possible password
	char **pp=(char**)calloc(nopp,sizeof(char*));//allocate char array of pointers
	for(i=0;i<nopp;i++)
	{
		pp[i]=(char*)calloc(MAX_STRING_SIZE,sizeof(char));//allocate character array of size MAX_STRING_SIZE 
		scanf("%s",pp[i]);//take probable passsword from user
	}
	for(i=0;i<nopp;i++)//iterate over all probable passwords
	{
		strcpy(temp,pp[i]);//copy the pssword to temp
		revstr(temp);//reverse the temp string
		for(j=0;j<nopp;j++)//iterate over all passwords
			if(i!=j && strcmp(pp[j],temp)==0)//if iit is not the same index string and temp and current string are equal then print length and middle character and break from lboth loops
			{
				string_len=strlen(pp[i]);
				printf("%d %c\n",string_len,pp[i][string_len/2]);
				flag=1;
				break;
			}
		if(flag)
			break;
	}
}
