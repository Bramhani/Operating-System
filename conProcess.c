#include<stdio.h>
#include<string.h>
struct process
{
	int ArtTm;
	int BurstTme;
};
int main()
{
	int size,sum=0;
	printf("Enter the no of processes: ");
	scanf("%d",&size);
	int c[size],temp,btemp;
	char* ctemp[size];
	struct process a[size];
	for(int i=0;i<size;i++)
	{
		printf(" process No %d\t\n",i+1);
		printf("Enter ProcessNAme:");
		scanf("%s",a[i].prss);
		printf("Arrival Time:");
		scanf("%d",&a[i].ArtTm);
		printf("Burst Time :");
		scanf("%d",&a[i].BurstTme);
	}
	printf("\n\tproName\tArriTime\tBurstTime\n");
	for(int i=0;i<size;i++)
	{
		printf("\t%s\t\t%d\t\t%d\n",a[i].prss,a[i].ArtTm,a[i].BurstTme);
	}
	for(int i=0;i<size;i++)
	{
		if(a[i].ArtTm>a[i+1].ArtTm)
		{
			temp=a[i].ArtTm;
			a[i].ArtTm=a[i+1].ArtTm;
			a[i+1].ArtTm=temp;
			btemp=a[i].BurstTme;
			a[i].BurstTme=a[i+1].BurstTme;
			a[i+1].BurstTme=btemp;
		}
	}
	printf("\n\tproName\tArriTime\tBurstTime\tCompleteTime\n");
	c[0]=a[0].BurstTme;
	sum=c[0];
	for(int i=1;i<size;i++)
	{
		sum=sum+c[i];
		c[i]=sum;
	}
	for(int i=0;i<size;i++)
	{
		printf("\t%s\t\t%d\t\t%d\t\t%d\n",a[i].prss,a[i].ArtTm,a[i].BurstTme,c[i]);
	}
		
}
	
