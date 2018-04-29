#include<stdio.h>
void prio(int *a,int *b,int *x,int s)
{
	int p[s],q[s];
	int i,j,sum=0,temp,pre,min,k=0,pos;
	int w[s],tat[s],com[s];
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(x[i]>x[j])
			{
				temp=x[i];
				x[i]=x[j];
				x[i]=temp;
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
				temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
			
		}
	}
	min=a[0];
	for(i=0;i<s;i++)
	{
		if(min>a[i])
		{
			min=a[i];
			pos=i;
		}
	}
	com[pos]=a[pos]+b[pos];
	for(i=0;i<s;i++)
	{
		p[i]=a[i];
		q[i]=b[i];
	}
	q[pos]=0;
	p[pos]=0;
	pre=com[pos];
	sum=pre;
	for(i=0;i<s;i++)
	{
		if(i!=pos)
		{
			if(pre>p[i])
			{
				sum=sum+q[i];
				com[i]=sum;
			}
			else
			{
				sum=p[i]+q[i];
				com[i]=sum;
			}
			pre=com[i];
		}
	}
	printf("\n\tPROCESS_NO\tSTATE_TIME\tUSAGE_TIME(in min)\tcompleteTime\tpriorty\n");
	for(i=0;i<s;i++)
	{
		printf("\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",i+1,a[i],b[i],com[i],x[i]);
	}
}
void processBegins()
{
	int size,i;
	printf("Enter the # process: ");
	scanf("%d",&size);
	int arTm[size],brTm[size],pr[size];
	printf("Enter AT ,BT and PRIority for %d processes \n",size);
	for(i=0;i<size;i++)
	{
		printf("Enter the %d process state usage time(in min) and priority: ",i+1);
		scanf("%d %d %d",&arTm[i],&brTm[i],&pr[i]);
	}
	printf("\n\tPROCESS_NO\tSTATE_TIME\tUSAGE_TIME(in min)\tpriority\n");
	for(i=0;i<size;i++)
	{
		printf("\t%d\t\t%d\t\t%d\t\t%d\n",i+1,arTm[i],brTm[i],pr[i]);
	}
	prio(arTm,brTm,pr,size);
		
}
int main()
{
	processBegins();
}
