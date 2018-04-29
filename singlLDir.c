#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c=0;			//no of files
struct 
{
	char dir[10],file[10][10];
	
}dir;
void dis()
{
	int i;
	printf("directory : %s\n",dir.dir);
	for(i=0;i<c;i++)
	{
		printf("\t%s\n",dir.file[i]);
	}
		
}
void srchFile(char *fl)
{
	int i;
	for(i=0;i<c;i++)
	{
		if(strcmp(dir.file[i],fl)==0)
		{
			printf("File %s is found \n ",fl);
			break;			
		}
	}
	if(i==c)
	{
		printf("File is not found");
	}
}
int  srchDelete(char *fl,int f)
{
	int i;
	for(i=0;i<c;i++)
	{
		if(strcmp(fl,dir.file[i])==0)
		{
			//printf("File %s is found 2 delete:\n ",fl);
			f=9;
		}
		if(f==9)
		{
			if(i!=c-1)
			{
				strcpy(dir.file[i],dir.file[i+1]);
			}
		}
	}
	if(i==c&&f!=9)
	{
		printf("file is not found");
	}
	else 
	return(c--);
}
int main()
{
	int nD,nF,ch,i=0,f,e=0;
	char fl[10];
	printf("Enter the directory Name: ");
	scanf("%s",dir.dir);
	while(1)
	{	ch=0;
		printf("1.create File\n2.Delete File\n3.search\n4.Display \n5.exit\n");
		scanf("%d",&ch);
		f=0;
		switch(ch)
		{
			case 1: printf("Enter the name of file: ");
				scanf("%s",dir.file[c]);
				c++;
				break;
			case 2: printf("Enter the name of file to delete: ");
				scanf("%s",fl);
				srchDelete(fl,f);
				break;
			case 3:	printf("Enter the name of file to search: ");
				scanf("%s",fl);
				srchFile(fl);
			case 4: dis();
				break;
				
			case 5: exit(0);
				break;
		      default : printf("Wrong input:( ");
				//e=8;		//this is for exit
				exit(0);
					//break;
		
	
		};
		
	}
}
