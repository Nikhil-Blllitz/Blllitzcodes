#include<stdio.h>
#include<stdlib.h>
#define CALLOC(p,n,type)\
p=(type*)calloc(n,sizeof(type));\
if(p==NULL)\
	{\
		printf("Insufficient memory");\
		exit(0);\
	}
void main()
{
	int *a,i;
	CALLOC(a,5,int);
	printf("\nEnter array elements: \n");
	for(i=0;i<5;i++)
	{
		scanf("%d",a+i);
	}
	printf("\nArray elements are: \n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",*a+i);
	}
}
