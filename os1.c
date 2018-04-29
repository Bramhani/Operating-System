#include<stdio.h>
void waiTme(int a[],int b[],int s)
{
	int c[s],Tat[s],w[s],sum=0,x,y;
	float avg=0;
	c[0]=b[0];
	sum=c[0];
	for(int i=1;i<s;i++)
	{
		if(a[i]==(a[i-1]+1))
		{
			sum=sum+b[i];
			c[i]=sum;
		}
		else
		{
			c[i]=a[i]+b[i];
			sum=c[i];
		}
	}
	for(int i=0;i<s;i++)
	{
		Tat[i]=c[i]-a[i];
	}
	for(int i=0;i<s;i++)
	{
		w[i]=Tat[i]-b[i];
	}
	printf("\n\tCompleteTime\tTAT\tWaitingTime\n");
	for(int i=0;i<s;i++)
	{
		printf("\n\t%d\t\t%d\t%d",c[i],Tat[i],w[i]);
	}
	sum=0;
	for(int i=0;i<s;i++)
	{
		sum=sum+w[i];
	}
	avg=sum/s;
	printf("\n\tThe average waiting time is %d/%d= %f",sum,s,avg); 	
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
	waiTme(arTm,brTm,size);
		
}
int main()
{
	processBegins();
}
