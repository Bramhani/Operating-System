#include<stdio.h>
int main()
{
	int refStr[30],fault[30],pgFt=0,count[10],nf,ns,i,m[10],next=1,j,min;
	printf("Enter the no of refStrings anf frames: ");
	scanf("%d%d",&ns,&nf);
	for(i=0;i<ns;i++)
	{
		scanf("%d",&refStr[i]);
		fault[i]=0;
		
		
		
	}
	
	for(j=0;j<nf;j++)
	{
		m[j]=-1;
		
	}
	for(i=0;i<ns;i++)
	{
		for(j=0;j<nf;j++)
		{
			if(refStr[i]==m[j])
			{
				fault[i]=1;
				count[j]=next;
				next++;
			}
		}
			 if(fault[i]==0)
			{
				if(i<nf)
				{
					m[i]=refStr[i];
					count[i]=next;
					next++;
				}
				else
				{
					min=0;
					for(int k=1;k<nf;k++)
					{
						if(count[min]>count[k])
						min=k;
					}
					m[min]=refStr[i];
					count[min]=next;
					next++;
				}
				pgFt++;
			}
			
		
		for(j=0;j<nf;j++)
		printf("%d\t", m[j]);
		printf("\n");
	}
	printf("pageflt = %d",pgFt);
	
					
}
