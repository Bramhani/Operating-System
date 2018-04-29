#include<stdio.h>
int RamSz,osSz,blkSize,NoPrcs,usrSz,nblks;
int i,j,n,count=0;
void mft()
{
	int ram[n],intrnl[n];
	int intFlag=0,sum=0;
	printf("Enter the size of the processes :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ram[i]);
	}
	printf("\tProcessNO\tSize\tfit/stored\tInternalFrag....\n");
	for(i=0;i<n;i++)
	{
		if(ram[i]<=blkSize)		
		{
			usrSz-=blkSize;
			printf("\t%d\t\t%d\tYES\t\t",i+1,ram[i]);
			if(blkSize>=ram[i])
			{
				intrnl[i]=blkSize-ram[i];
				printf("%d",intrnl[i]);
				intFlag=9;
			}
			
			
		}
		else
		{
			if(usrSz>0&&ram[i]>blkSize)
			{
				printf("\t%d\t\t%d\tNO\t\t---",i+1,ram[i]);
				count=1;
				intrnl[i]=0;
			}
		}
		printf("\n");
	}
	if(count==1&&usrSz!=0)
		printf("\nExternal fragmentation occured is %d\n",usrSz);
	else if(usrSz>0)
		printf("\nThe available space is %d",usrSz);
	else if(usrSz<=0&&count==1)
		printf("\no Space is available ");
	if(intFlag==9)
	{
		for(i=0;i<n;i++)
		{
			sum=sum+intrnl[i];
		}
		printf("\nTotal Internal Fragmentation:%d\n",sum);
	}
}
int main()
{	
	printf("Enter the size of the Ram,Os in kb  :");
	scanf("%d%d",&RamSz,&osSz);
	usrSz=RamSz-osSz;
	printf("The User program size is: %d\nEnter the No of blocks :",usrSz);
	scanf("%d",&nblks);
	blkSize=usrSz/nblks;
	printf("The blk size is: %d  ",blkSize); 
	printf("\nEnter the No of the process : ");
	scanf ("%d",&n);
	mft();
}

		
					
	
	
