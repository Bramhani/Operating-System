#include<stdio.h>

struct process
{
	int p,bt,wt,tat,ct;
};
struct process t[10];
void times(int s)
{
	int sum=0;
	float avg;
	printf("\n\tCompleteTime\tTAT\tWaitingTime\n");
	sum=0;
	for(int i=0;i<s;i++)
	{
		printf("\n\t%d\t\t%d\t%d",t[i].ct,t[i].ct,t[i].ct-t[i].bt);
		sum=sum+t[i].ct-t[i].bt;
	}
	avg=sum/s;
	printf("\n\tThe average waiting time is %d/%d= %f",sum,s,avg); 	
}
void sjf(int s)
{
	int i,j,sum=0,temp,pre,min,k=0,pos;
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			
			if(t[i].bt>t[j].bt)	
			{
				temp=t[i].bt;
				t[i].bt=t[j].bt;
				t[j].bt=temp;
			}
			 
		}
	}
	for(i=0;i<s;i++)
	{
		sum=sum+t[i].bt;
		t[i].ct=sum;
	}
	times(s);
}
	
void processBegins()
{
	int size,i;
	printf("Enter the # process which are <10: ");
	scanf("%d",&size);
	printf("WELCOME TO SJF WITHOUT AT \n");
	for(i=0;i<size;i++)
	{
		printf("Enter the %d process  burst time(in min): ",i+1);
		scanf("%d",&t[i].bt);
	}
	sjf(size);
		
}	
int main()
{
	processBegins();
}	

