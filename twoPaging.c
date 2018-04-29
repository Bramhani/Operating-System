#include<stdio.h>
struct 
{
	char  dirName[10],fileName[10][10];
	int fcnt;
}dir[10];
int main()
{
	int i,j,nd,nf;
	char *fN;
	int file[10];
	printf("Enter the No of directories: ");
	scanf("%d",&nd);
	for(i=0;i<nd;i++)
	{
		printf("Enter the name of directory:\n new line*******8");
		scanf("%s/n",dir[i].dirName);
		printf("Enter the no of files in %s directory",dir[i].dirName);
		scanf("%d",&file[i]);
		for(j=0;j<file[i];j++)
		{
			printf("Enter the name of file:");
			scanf("%s",dir[i].fileName[j]);
		}
	}
	for(i=0;i<nd;i++)
	{
		printf("\nIn dir %s: ",dir[i].dirName);
		for(j=0;j<file[i];j++)
		printf("%s\n",dir[i].fileName[j]);
	}
}
