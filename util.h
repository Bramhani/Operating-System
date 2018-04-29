void sjf(struct process t[],int s)
{
	int time=0,i,j,temp,count=0,sum=0,f=0,sche=0;
	for(i=0;i<s;i++)
	{
		for(j=i+1;j<s;j++)
		{
			if(t[i].bt>t[j].bt)
			{
				temp=t[i].bt;
				t[i].bt=t[j].bt;
				t[j].bt=temp;
				temp=t[i].p;
				t[i].p=t[j].p;
				t[j].p=temp;
				temp=t[i].at;
				t[i].at=t[j].at;
				t[j].at=temp;
			}
		}
	}
	for(time=0; ;)
	{
		for(i=0;i<s;i++)
		{
			if(t[i].at==time)
			{
				sum=sum+t[i].at+t[i].bt;
				t[i].ct=sum;
				time++;
				sche++;
			}
			else
			count++;
		}
		if(count==s-1)
		time++;
		if(sche==s-1)
		break;
	}
	for(int i=0;i<s;i++)
	{
		printf("\n\t%d\t\t%d\t%d",t[i].at,t[i].bt,t[i].ct);
		
	}
	times(t,s);
}
