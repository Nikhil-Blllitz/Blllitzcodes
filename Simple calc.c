#include<stdio.h>
#include<stdlib.h>
void main()
{
	int a,b,res;
	char op;
	printf("enter simple arithmetic operation");
	scanf("%d%c%d",&a,&op,&b);
	switch(op)
	{
		case'+':res=a+b;
		break;
		case'-':res=a-b;
		break;
		case'%':res=a%b;
		break;
		case'*':res=a*b;
	    break;
	    case'/':if(b!=0)
	                res=a/b;
	            else
	            {
	            	printf("division by 0 not possible");
	            	exit(0);
				}
	printf("%d%c%d=%d",a,op,b,res);
				
	}
}

