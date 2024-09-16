# include<stdio.h>
int swap(int *a,int *b)
{
    int temp;
     temp=*a;
     *a=*b;
    *b=temp;
}
int main()
{
   int a,b;
   printf("enter two numbers");
   scanf("%d %d",&a,&b);
   swap(&a,&b);
    printf("after swap value of a:%d  value of b:%d",a,b);
}
