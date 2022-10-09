/*Name : Omkar Santosh Gavhane
Roll No : 2111MC08
MC504-Assignment 1
*/

#include<stdio.h>

int main(){
	int x,y,t;
	printf("x:");
	scanf("%d",&x);
	printf("y:");
	scanf("%d",&y);
	//here swappping is done by use of temporary variable t
	t=x;
	x=y;
	y=t;
	printf("x=%d,y=%d",x,y);
	return(0);
}
