#include<stdio.h>
void push(char ele, char s[100], int *t);
int main()
{
	char stack[100], in[100], post[100];
	int i, n, top = -1;
	printf("Enter the size of the Infix Expression: ");
	scanf("%d",&n);
	n++;
	printf("Enter the Infix Expression:  ");
	for(i=0;i<n;i++)
	scanf("%c",&in[i]);
	printf("The Infix Expression you have entered is:  ");
	printf("\n%s",in);
	
	for(i=0;i<n;i++)
	{
		if((in[i]<='A'&&in[i]<='Z')||(in[i]<='a'&&in[i]<='z'))
		{
			push(in[i], post, &top);
		}
		else if((in[i]=='('))
		{
			push(in[i], stack, &top);
		}	
	}
	
	
	
	printf("\n%s",in);
	printf("\n%s",stack);
	printf("\n%s",post);
	return 0;
}

void push(char ele, char s[100], int *t)
{
	s[*t] = ele;
	(*t) = (*t) + (1);
}
