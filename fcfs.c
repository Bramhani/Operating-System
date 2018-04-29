#include<stdio.h>
/* 
	AUTHOR:BRAMHANIMULUGOJU .
	DATE:14 AUG 2017
	THIS CODE IS WORKS FOR WITH PREEMPTION ALSO****
*/
	
void fcfs(int *a,int *b,int s)
{
	int i,j,sum=0,temp,pre;
	int w[s],tat[s],com[s];
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
			
		}
		
	}
	sum=a[0];
	for(i=0;i<s;i++)
	{
		if(i==0)
		{
		sum=sum+b[i];
		com[i]=sum;
		}
		else
		{
			if(pre<a[i])
			{
				sum=a[i]+b[i];
				com[i]=sum;
			}
			else
			{
			sum=sum+b[i];
			com[i]=sum;
			}
		}
		pre=com[i];
	}
	for(i=0;i<s;i++)
	printf("%3d",com[i]);
	printf("\n\tPROCESS_NO\tSTATE_TIME\tUSAGE_TIME(in min)\tcompleteTime\n");
	for(i=0;i<s;i++)
	{
		printf("\t%d\t\t%d\t\t%d\t\t%3d\n",i+1,a[i],b[i],com[i]);
	}
}
	
void processBegins()
{
	int size,i;
	printf("Enter the # process: ");
	scanf("%d",&size);
	int arTm[size],brTm[size];
	printf("Enter the details for respective process: \n");
	for(i=0;i<size;i++)
	{
		printf("Enter the %d process state and usage time(in min): ",i+1);
		scanf("%d %d",&arTm[i],&brTm[i]);
	}
	printf("\n\tPROCESS_NO\tSTATE_TIME\tUSAGE_TIME(in min)\n");
	for(i=0;i<size;i++)
	{
		printf("\t%d\t\t%d\t\t%d\n",i+1,arTm[i],brTm[i]);
	}
	fcfs(arTm,brTm,size);
		
}
int main()
{
	processBegins();
}
