#include<stdio.h>
void main()
{
	int i,j,n;
	printf("enter the number of rows");
	scanf("d",&n);
	for(i=0;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			printf(" ");
		}
		for(j=1;j>=i;j--)
		{
			printf("%d",j);
		}
		printf("\n");
	}
}
