#include<stdio.h>
void main()
{
	int i,n,a[10],even=0,odd=0;
	printf("enter size");
	scanf("%d",&n);
	for(i=0,i<n;i++)
	{
		scanf("%d",%a[i]);
	}
	for(i=0;i<n;i=i+2)
	{
		even=a[i]+even;
	}
	for(i=1;i<n;i=i+2)
	{
		odd=a[i]+odd;
	}
	printf("The sum of odd and even numbers are %d and %d respectively",odd,even);
}
