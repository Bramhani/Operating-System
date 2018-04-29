#include<stdio.h>
int RamSz,osSz,blkSize,NoPrcs,usrSz;
int i,j,n,count=0;
void mvt()
{
	int ram[n];
	printf("Enter the size of the processes :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ram[i]);
	}
	for(i=0;i<n;i++)
	{
		if(usrSz-ram[i]>=0)		//here = tells whether no fragmentation  
		{
			usrSz-=ram[i];
			printf("\tThe process %d of size %d is fit & available is %d\n ",i+1,ram[i],usrSz);
			
		}
		else
		{
			if(usrSz>0&&ram[i]>usrSz)
			{
				printf("Here for process %d of size %d is not  available \n ",i,ram[i]);
				count=1;
			}
		}
	}
	if(count==1&&usrSz!=0)
		printf("External fragmentation occured is %d\n",usrSz);
	else if(usrSz>0)
		printf("The available space is %d",usrSz);
	else if(usrSz<=0&&count==1)
		printf("No Space is available ");
}
int main()
{	
	printf("Enter the size of the Ram,Os in kb  :");
	scanf("%d%d",&RamSz,&osSz);
	usrSz=RamSz-osSz;
	printf("The User program size is: %d\n",usrSz);
	printf("Enter the No of the process : ");
	scanf ("%d",&n);
	mvt();
}

		
					
	
	
