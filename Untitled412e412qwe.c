#include<stdio.h>
#define SIZE 5
int s[SIZE],top=-1;
int main()
{
	int flag=1;
	int ch;
	printf("1.Push\n2.Pop\n3.Display\n4.Palindrome check\n");
	while(flag==1)
	{
	printf("Enter choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:push();
		break;
		case 2:pop();
		break;
		case 3:display();
		break;
		case 4:palindrome();
		default: flag=0;
		return;
	}
}
}
int push()
	{
		int item;
		if(top==SIZE-1)
		{
			printf("Stack overflow\n");
			return;
		}
		printf("Enter item to insert\n");
		scanf("%d",&item);
		s[++top]=item;
		return(0);
}
	int pop()
	{
		if(top==-1)
		{
			printf("Stack underflow\n");
			return;
		}
		printf("Deleted item is %d\n",s[top--]);
		return(0);
}
	int display()
	{
		int i;
		if(top==-1)
		{
			printf("Stack is empty\n");
		}
		for(i=top;i>=0;i--)
		{
			printf("\t%d\n",s[i]);
		}
		return(0);
}
void palindrome()
{
	int x=1;
	int p[SIZE],i,j;
	for(j=top,i=0;j>=0,i<=top;j--,i++)
	    {
		   p[i]=s[j];
	    }	    

for(i=top;i>=0;i--)
{
	if(p[i]==s[i])
	{
		continue;
	}
	else
	{
		x=0;
		break;
	}
}
printf("Not a palindrome\n");
}

