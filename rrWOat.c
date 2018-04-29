#include<stdio.h>
struct process
{
	int p,bt,wt,tat,ct,dup;
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
		printf("\n\t%d\t\t%d\t%d",t[i].tat,t[i].tat,t[i].tat-t[i].dup);
		sum=sum+t[i].tat-t[i].dup;
	}
	avg=sum/s;
	printf("\n\tThe average waiting time is %d/%d= %f",sum,s,avg); 	
}
void rr(int s,int tq)
{
	int i,j,sum=0,temp,pre,min,max=0,k=0,pos;
	for(i=0;i<s;i++)
	{
		if(max<t[i].bt)
		max=t[i].bt;
	}
	for(i=0;i<(max/tq)+1;i++)			//here v r taking max timez to decrease the bt's
	{
		for(j=0;j<s;j++)
		{
			if(t[j].bt!=0)
			{
				if(t[j].bt<=tq)
				{
					t[j].tat=temp+t[j].bt;
					temp=temp+t[j].bt;
					t[j].bt=0;
				}
				else
				{
					t[j].bt=t[j].bt-tq;
					temp=temp+tq;
				}
			}
		}
	}
	printf("The tat is: ");
	/*for(i=0;i<s;i++)
	{
		printf("\t %d ",t[i].tat);
	}
	*/	
	times(s);
}
	
void processBegins()
{
	int size,i,tq;
	printf("Enter the # process which are <10 and TimeQuantum: ");
	scanf("%d%d",&size,&tq);
	printf("WELCOME TO RR WITHOUT AT \n");
	for(i=0;i<size;i++)
	{
		printf("Enter the %d process  burst time(in min): ",i+1);
		scanf("%d",&t[i].bt);
		t[i].dup=t[i].bt;
	}
	rr(size,tq);
		
}	
int main()
{
	processBegins();
}	

