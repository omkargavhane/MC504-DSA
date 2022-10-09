/*Name : Omkar Santosh Gavhane
Roll No : 2111MC08
MC504-Assignment 1
*/
#include<stdio.h>

int main()
{	
	//used ternary operator for finding largest and smallest value 
	float no1,no2,no3,largest,smallest;
	printf("First number:");
	scanf("%f",&no1);
	printf("second number:");
	scanf("%f",&no2);
	printf("Third number:");
	scanf("%f",&no3);
	largest=no1 > no2 ? (no1 > no3 ? no1 : no3) : (no2 > no3 ? no2 : no3);
	smallest=no1 < no2 ? (no1 < no3 ? no1 : no3) : (no2 < no3 ? no2 : no3);
	printf("Largest number:%f",largest);
	printf("\nsmallest number:%f",smallest);
	return 0;
}

