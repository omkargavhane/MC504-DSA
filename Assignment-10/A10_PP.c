//Name : Omkar Gavhane
//Roll NO : 2111MC08
//A10-PP
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
	printf("I consider teamname as number rather than charcters so inputs and outps are accordingly\n");
	int not,i,nom,j,index_a,index_b;
	float team_name[MAX];
	float team_a[MAX];
	float team_b[MAX];
	float score_a[MAX]={0};
	float score_b[MAX]={0};
	float total_score[MAX]={0};
	float net_score[MAX]={0};
	scanf("%d",&not);
	for(i=0;i<not;i++)
		scanf("%f",&team_name[i]);
	for(i=0;i<not;i++)
		printf("%f\n",team_name[i]);
	scanf("%d",&nom);
	for(i=0;i<nom;i++)
	{
		printf("Details of Match %d\n",i+1);
		scanf("%f",&team_a[i]);
		scanf("%f",&score_a[i]);
		scanf("%f",&team_b[i]);
		scanf("%f",&score_b[i]);
		for(j=0;j<not;j++)
		{
			if(team_name[j]==team_a[i])
				index_a=j;
			if(team_name[j]==team_b[i])
				index_b=j;
		}
		net_score[index_a]+=score_a[i];
		net_score[index_b]+=score_b[i];
		if(score_a[i]>score_b[i])
			total_score[index_a]+=2;
		else if(score_a[i]<score_b[i])
			total_score[index_b]+=2;
		else
		{
			total_score[index_b]+=1;
			total_score[index_a]+=1;
		}

	}
	selectionsort(net_score,total_score,team_name,not);
	printf("Output:\n");
	for(i=0;i<not;i++)
	{
		printf("%f %f %f\n",team_name[i],total_score[i],net_score[i]);
	}
}

