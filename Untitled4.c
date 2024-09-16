#include<stdio.h>
void main()
{
	int i,n,a[10],b[10],c[10];
	printf("Enter size of array\n");
	scanf("%d",&n);
	printf("\nEnter array elements of a\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("array a is");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\nEnter array elements of b\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	printf("array b is");
	for(i=0;i<n;i++)
	{
		printf("%d",b[i]);
	}
	for(i=0;i<n;i++)
	{
		c[i]=a[i]+b[i];
	}
	printf("The array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",c[i]);
	}
}
