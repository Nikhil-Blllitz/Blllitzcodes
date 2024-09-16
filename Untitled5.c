#include<stdio.h>
void main()
{
	int i,n,a[10],big=0;
	printf("enter size of array\n");
	scanf("%d",&n);
	printf("enter elements of array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]>big)
		big=a[i];
	}
	printf("biggest element is %d",big);
}
