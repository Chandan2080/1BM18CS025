//PUSH, POP and DISPLAY the elements of the stack Without Global Variables!
#include<stdio.h>
int pop(int s[100],int *t);
void push(int ele, int s[100], int *t);
void display(int s[100], int t);
int main()
{
	int stack[100];
	int top = -1;
	int x, y, z;
	push(1,stack,&top);
	push(2,stack,&top);
	display(stack,top);
	x = pop(stack,&top);
	y = pop(stack,&top);
	z = pop(stack,&top);
	if(x!=-99999)
		printf("Popped element is %d\n",x);
	if(y!=-99999)
		printf("Popped element is %d\n",y);
	if(z!=-99999)
		printf("Popped element is %d\n",z);

	display(stack,top);
	return 0;
}
int pop(int s[100], int *t)
{
	int ele;
	if((*t)==-1)
	{
		//printf("Stack underflow\n");
		return -99999;
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
	printf("The stack elements are:\n");
	if(t==-1)
	{
		printf("Stack underflow\n");
		return;
	}
	for(int i=t;i>-1;i--)
		printf("\t%d\n",s[i]);
}
