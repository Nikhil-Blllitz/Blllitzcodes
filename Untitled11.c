#include<stdio.h>
void main()
{
	int i,n,f=1;
	printf("enter number\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		f=f*i;
	}
	printf("factorial is %d",f);
}
