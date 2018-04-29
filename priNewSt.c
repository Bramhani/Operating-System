#include<stdio.h> 
int n,i,j,total_time=0;
float avgtat=0,avgwt=0;
struct data
{
	int at,st,ct,tat,wt;
	char pname[20],tempc[20];
	float ntat;
	int pr;//priority
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
	printf("pririty\tpname\tat\tst\tct\ttat\twt\tntat\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%f\n",a[i].pr,a[i].pname,a[i].at,a[i].st,a[i].ct,a[i].tat,a[i].wt,a[i].ntat);
	}
	printf("avgtat=%f\navgwt=%f\n",avgtat,avgwt);

}

void finding(struct data a[])
{
	//if(n==1)sum_st+=a[0].at;//coz the sum of all sevice time also includes waiting time
	int time=0,x,c=0;//,procs[n];x for storing rh selected process
	//c is for counter and procs is to atore the processes that arived
	while(time<total_time)
	{
		j=0;
		for(i=0;i<n;i++)
		{
			if(a[i].at<=time)
			{
			j=i+1;
			}//storing the list of processes that have arrived

		}
		if(j>0)
		{//printf("	j=%d time=%d\n",j,time);
			int x=0,min_pr=a[0].pr;//min priority
			for(i=1;i<j;i++)
			{
				if(min_pr>a[i].pr)
				{
					x=i;
					min_pr=a[i].pr;
				}
				/*else if(min_pr==a[i].pr)		//when same priorities
				{
					if(a[x].at>a[i].at)
					{
						x=i;
						min_pr=a[i].pr;
					}
					else if(a[x].at==a[i].at)
					{
						if(a[x].st>a[i].st)
						{
						x=i;
						min_pr=a[i].pr;
						}
					}
				}*/
			}
			time+=a[x].st;//x is the process with min service time
			a[x].ct=time;
			a[x].pr+=1000;//so that it not selected again
			a[x].at+=1000;//so that it not selected again based on arival time if its the only process

		}
		else
		{
			time++;//printf("	 time=%d\n",time);
			//sum_st++;
		}
			//printf("%d\n",time);
	}
	for(i=0;i<n;i++)
	{
		a[i].pr-=1000;
		a[i].at-=1000;
	}//so that its values return ack to narmal
	display(a);
}
int main()
{
	printf("enter the no of process\n");
	scanf("%d",&n);
	struct data aa[n];
	for(i=0;i<n;i++)
	{
		printf("enter the priority,name of process%d,at,st\n",i);
		scanf("%d%s",&aa[i].pr,aa[i].pname);
		scanf("%d%d",&aa[i].at,&aa[i].st);
		//	 sum_st+=aa[i].st;//to find the total st
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
}


