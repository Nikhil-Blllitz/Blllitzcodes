#include<stdio.h>
void main()
{
	int num,den,a,b,gcd,lcm,t;
	printf("Enter the numbers\n");
	scanf("%d%d",&a,&b);
	num=a;
	den=b;
	while(den!=0)
	{
		t=den;
		den=num%den;
		num=t;
	}
	gcd=num;
	lcm=(a*b)/gcd;
	printf("gcd=%d lcm=%d",gcd,lcm);
}
