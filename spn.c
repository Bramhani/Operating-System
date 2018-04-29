#include<stdio.h> 
int n,i,j,total_time=0;
float avgtat=0,avgwt=0;
struct data
{
	int at,st,ct,tat,wt;
	char pname[20],tempc[20];
	float ntat;

}temp;
void display(struct data a[])
{
	for(i=0;i<n;i++)
	{
		a[i].tat=a[i].ct-a[i].at;
		a[i].wt=a[i].tat-a[i].st;
		a[i].ntat=(float)a[i].tat/a[i].st;
	}
	for(i=0;i<n;i++)
	{
		avgtat+=a[i].tat;
		avgwt+=a[i].wt;
	}
	avgtat=avgtat/n;
	avgwt=avgwt/n;
	printf("pname\tat\tst\tct\ttat\twt\tntat\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t%d\t%d\t%d\t%d\t%d\t%f\n",a[i].pname,a[i].at,a[i].st,a[i].ct,a[i].tat,a[i].wt,a[i].ntat);
	}
	printf("avgtat=%f\navgwt=%f\n",avgtat,avgwt);
}
void finding(struct data a[])
{
	
	int time=0,c;//c is for counter and procs is to atore the processes that arived
	while(time<total_time)
	{
		c=0;
		j=0;
		for(i=0;i<n;i++)
		{	if(a[i].at<=time)
			{
				j=i+1;
			}//storing the list of processes that have arrived
		}
		if(j>0)
		{
			int x=0,min_st=a[0].st;
			for(i=1;i<j;i++)
			{
				if(min_st>a[i].st)
				{
					x=i;
					min_st=a[i].st;
				}
			}
			time+=a[x].st;//x is the process with min service time
			a[x].ct=time;
			a[x].st+=1000;//so that it not selected again
		}
		else
			time++;
	}
	for(i=0;i<n;i++)
	{
		a[i].st-=1000;
	}//so that its values return ack to narmal
display(a);
}

int  main()
{
	//int temp;
	printf("enter the no of process\n");
	scanf("%d",&n);
	struct data aa[n];
	for(i=0;i<n;i++)
	{
		printf("enter the name of process %d,at,st\n",i+1);
		scanf("%s",aa[i].pname);
		scanf("%d%d",&aa[i].at,&aa[i].st);
	}
//sorting
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(aa[i].at>aa[j].at)
			{
			temp=aa[i];
			aa[i]=aa[j];
			aa[j]=temp;
			}
		}
	}
	
//finding the total time
	total_time+=aa[0].at+aa[0].st;
	for(i=1;i<n;i++)
	{
		if(aa[i].at>total_time)
		total_time=aa[i].at;//coz if the next process arives after a while after the b4 process has //complted
		total_time+=aa[i].st;
	}
	printf("%d\n",total_time);
//finding the ct
	finding(aa);
	return 0;
}

