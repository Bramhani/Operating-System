#include<stdio.h>
struct process
{
	int p,bt,wt,tat,ct,pri,pN;
	 
};
struct process t[10];
void times(int s)
{
	int sum=0;
	float avg;
	printf("\n\tpNo\t\tBT\t\tpri\t\tCT\t\tTAT\t\tWT\n");
	sum=0;
	for(int i=0;i<s;i++)
	{
		printf("\n\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",t[i].pN,t[i].bt,t[i].pri,t[i].ct,t[i].ct,t[i].ct-t[i].bt);
		sum=sum+t[i].ct-t[i].bt;
	}
	avg=sum/s;
	printf("\n\tThe average waiting time is %d/%d= %f",sum,s,avg); 	
}
void pri(int s)
{
	int i,j,sum=0,pre,min,k=0,pos;
	struct process temp;
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			
			if(t[i].pri>t[j].pri)	
			{
				temp=t[i];
				t[i]=t[j];
				t[j]=temp;
				
				
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
	printf("WELCOME TO pri WITHOUT AT \n");
	for(i=0;i<size;i++)
	{
		t[i].pN=i+1;
		printf("Enter the  process %d  burst time(in min) and priority: ",t[i].pN);
		scanf("%d%d",&t[i].bt,&t[i].pri);
	}
	printf("*******************Here Iam taking low Number high priority :)\n ");
	pri(size);
		
}	
int main()
{
	processBegins();
}	

