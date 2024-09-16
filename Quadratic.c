#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
	float a,b,c,d,r1,r2,real,imag;
	printf("enter coefficients");
	scanf("%f%f%f",&a,&b,&c);
	if(a==0)
	{
		printf("invlaid coefficients");
		exit(0);
	}
	d=(b*b)-(4*a*c);
	if(d>0)
	{
		r1=(-b-sqrt(d))/(2*a);
	    r2=(-b+sqrt(d))/(2*a);
	    printf("The roots are real and distinct");
	    printf("r1=%f and r2=%f",r1,r2);
	}
	else if(d==0)
	{
		r1=r2=-b/(2*a);
		printf("The roots are real and equal");
		printf("r1=%f and r2=%f",r1,r2);
	}
	else
	{
		real=-b/(2*a);
		imag=(sqrt(fabs(d)))/(2*a);
		printf("complex and imaginary");
		printf("r1=%f+i%f and r2=%f-i%f",real,imag,real,imag);
	}
	
	
	
}
