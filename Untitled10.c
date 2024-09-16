#include<stdio.h>
void main()
{
	int n,org,rev=0,rem=0,num;
	printf("Enter a number:\n");
	scanf("%d",&num);
	n=num;
	while(n!=0)
	{
		rem=n%10;
		rev=rev*10+rem;
		n=n/10;
	}
	printf("\nreversed num is %d",rev);
	if(num==rev)
	printf("\n%d is palindrome",num);
	else
	printf("\n %d os not palindrome",num);
}
