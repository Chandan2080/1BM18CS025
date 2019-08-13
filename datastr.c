#include<stdio.h>
int pop(int s[100],int *t);
void push(int ele, int s[100], int *t);
void display(int s[100], int t);
int main()
{
	int stack[100];
	int top = -1;
	int x;
	push(1,stack,&top);
	push(2,stack,&top);
	push(3,stack,&top);
	display(stack,top);
	x = pop(stack,&top);
	if(x!=-99999)
		printf("Popped element is %d\n",x);
	display(stack,top);
	return 0;
}
int pop(int s[100], int *t)
{
	int ele;
	if((*t)==-1)
	{
		printf("\nStack underflow\n");
		return -9999;
	}
	ele = s[(*t)];
	(*t) = (*t) - 1;
	return ele;
}
void push(int ele, int s[100], int *t)
{
	if((*t)==99)
	{
		printf("Stack overflow\n\n");
		return;
	}
	(*t) = (*t) + 1;
	s[(*t)] = ele;
}
void display(int s[100],int t)
{
	if(t==-1)
	{
		printf("Stack underflow\n");
		return;
	}
	for(int i=t;i>-1;i--)
		printf("%d\n",s[i]);
}

