#include<stdio.h>
int main()
{
	int MemS,pageSz,noPages,noProcess,remPages,flag=0;
	int p[10];	//this is for each process how many pages??
	int proces,pageNo,offset;
	printf("Enter the memory size ,page size,#process: ");
	scanf("%d%d%d/n",&MemS,&pageSz,&noProcess);
	
	noPages=MemS/pageSz;
	printf("%d is the no of pages available\n",noPages);
	remPages=noPages;
	int f[noProcess][noPages]; //this is for mainmemory
	for(int i=0;i<noProcess;i++)
	{
		printf("Enter the pages for process %d : ",i+1);
		scanf("%d/n",&p[i]);
		if(p[i]>remPages)
		{
			printf("Memory is full");
			flag=2;	//this is for knowing
			if(remPages==0)
				break;
		}
		else
		{
			remPages-=p[i];
			
		}
		if(flag!=2)
		{
			printf("Enter the  pagetable for process %d: ",i+1);
			for(int j=0;j<p[i];j++)
			{
				scanf("%d",&f[i][j]);
			}
		}
	}
	printf("Enter the LA for PA :");
	scanf("%d%d%d",&proces,&pageNo,&offset);
	if(proces>noProcess||pageNo>p[noProcess]||offset>pageSz)
		printf("Invalid input");
	else
		printf("%d",f[proces][pageNo]*pageSz+offset);
}
		
	
		
	
	
