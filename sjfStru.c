#include<stdio.h>
struct process
{
	int p,at,bt,wt,tat,ct;
};
void times(struct process t[],int s)
{
	int sum=0;
	float avg;
	printf("\n\tCompleteTime\tTAT\tWaitingTime\n");
	for(int i=0;i<s;i++)
	{
		printf("\n\t%d\t\t%d\t%d",t[i].ct,t[i].ct-t[i].at,t[i].ct-t[i].at-t[i].bt);
		sum=sum+t[i].ct-t[i].at-t[i].bt;
	}
	printf("\n\tThe average waiting time is %d/%d= %f",sum,s,avg); 	
}
void sjf(struct process t[],int s)
{
	int p[s],q[s],time=0;
	int i,j,sum=0,temp,pre,min,k=0,pos;
	int w[s],tat[s],com[s];
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(t[i].bt>t[j].bt)
			{
				temp=t[i].at;
				t[i].at=t[j].at;
				t[j].at=temp;
				temp=t[i].bt;
				t[i].bt=t[j].bt;
				t[j].bt=temp;
			}
			
		}
	}
	min=t[0].at;
	for(i=0;i<s;i++)
	{
		if(min>t[i].at)
		{
			min=t[i].at;
			pos=i;
		}
	}
	t[pos].ct=t[pos].at+t[pos].bt;
	for(i=0;i<s;i++)
	{
		p[i]=t[i].at;
		q[i]=t[i].bt;
	}
	q[pos]=0;
	p[pos]=0;
	pre=t[pos].ct;
	sum=pre;
	time=sum;
	for(i=0;i<s;i++)
	{
		if(i!=pos)
		{
			if(pre>p[i])
			{
				sum=sum+q[i];
				t[i].ct=sum;
			}
			else
			{
				sum=p[i]+q[i];
				t[i].ct=sum;
			}
			pre=t[i].ct;
		}
	}
	printf("\n\tPROCESS_NO\tSTATE_TIME\tUSAGE_TIME(in min)\tcompleteTime\n");
	for(i=0;i<s;i++)
	{
		printf("\t%d\t\t%d\t\t%d\t\t\t%d\n",i+1,t[i].at,t[i].bt,t[i].ct);
	}
	times(t,s);
}
void processBegins()
{
	int i,size;
	printf("Enter the # process which are : ");
	scanf("%d",&size);
	struct process t[size];
	for(i=0;i<size;i++)
	{
		printf("Enter the Arrival time and usage time for process%d: ",i+1);
		scanf("%d %d",&t[i].at,&t[i].bt);
	}
	sjf(t,size);		
}	
int main()
{
	processBegins();
}	

