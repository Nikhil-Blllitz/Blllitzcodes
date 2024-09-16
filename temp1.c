#include<stdio.h>
void main()
{
	int i,j,m,n,p,q,k,a[10][10],b[10][10],c[10][10];
	printf("Enter order of matrix a\n");
	scanf("%d%d",&m,&n);
	printf("Enter order of matrix b\n");
	scanf("%d%d",&p,&q);
	if(n!=p)
	{
		printf("Multiplication not possible");
		exit(0);
	}
	printf("Enter elements of matrix a\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("Enter elements of matrix b\n");
    for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
		    scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	printf("The resultant matrix is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<q;j++)
		{
			printf("%d",c[i][j]);
		}
	}	
}
