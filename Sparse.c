#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct TERM
{
	int row;
	int col;
	int val;
}a[MAX];
void main()
{
	int i;
	printf("Enter the size(2d)and value of matrix: \n");
	scanf("%d%d%d",&a[0].row,&a[0].col,&a[0].val);
	printf("Enter the location and value of element: \n");
	for(i=1;i<=a[0].val;i++)
	{
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
	}
	printf("Non-zero elements are: \nrow\tcol\tval\n");
	for(i=0;i<=a[0].val;i++)
	{
		printf("%d\t%d\t%d\n",a[i].row,a[i].col,a[i].val);
	}
}
