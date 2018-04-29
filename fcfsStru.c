#include<stdio.h>
struct process
{
	int p,at,bt,wt,tat,ct,dup;
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
		printf("\n\t%d\t\t%d\t%d",t[i].ct,t[i].ct-t[i].at,t[i].ct-t[i].at-t[i].dup);
		sum=sum+t[i].wt;
	}
	avg=sum/s;
	printf("\n\tThe average waiting time is %d/%d= %f",sum,s,avg); 	
}
void fcfs(int s)
{
	int i,j,sum=0,temp,pre;
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(t[i].at>t[j].at)
			{
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
				
			}
			
		}
		
	}
	sum=t[0].at;
	for(i=0;i<s;i++)
	{
		if(i==0)
		{
		sum=sum+t[i].bt;
		t[i].ct=sum;
		}
		else
		{
			if(pre<t[i].at)
			{
				sum=t[i].at+t[i].bt;
				t[i].ct=sum;
			}
			else
			{
			sum=sum+t[i].bt;
			t[i].ct=sum;
			}
		}
		pre=t[i].ct;
	}
	for(i=0;i<s;i++)
	printf("%3d",t[i].ct);
	printf("\n\tPROCESS_NO\tSTATE_TIME\n");
	for(i=0;i<s;i++)
	{
		printf("\t%d\t\t%d\t\t%d\t\n",i+1,t[i].at,t[i].bt);
	}
	times(s);
}
void processBegins()
{
	int size,i;
	printf("Enter the # process: ");
	scanf("%d",&size);
	printf("Enter the process Arrival time and burst time: \n");
	for(i=0;i<size;i++)
	{
		scanf("%d %d",&t[i].at,&t[i].bt);
		t[i].dup=t[i].bt;
	}
	fcfs(size);
		
}
int main()
{
	int i,j;
	processBegins();
}
	
