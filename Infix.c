#include<stdio.h>
#include<string.h>
#include<ctype.h>
void push(char ele,char s[100],int *t);
char pop(char s[100],int *t);
int is_operator(char s);
int precedence(char s);
int main()
{
	char stack[100], infix[100], postfix[100], x;
	int i=0, j=0, top=-1;
	printf("Enter the Infix Expression:  \t");
	scanf("%s",infix);
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
		{
			push(infix[i], stack, &top);
		}
		else if(infix[i] == ')')
		{
			x = pop(stack, &top);
			while(x != '(')
			{
				postfix[j] = x;
				j++;
				x = pop(stack,&top);
			}
		}
		else if(isdigit(infix[i]) || isalpha(infix[i]))
		{
			postfix[j] = infix[i];
			j++;
		}
		else if(is_operator(infix[i]) == 1)
		{
		    x = infix[i];
		    while(top!=-1&&precedence(x)<precedence(stack[top]))
			{
				postfix[j] = pop(stack, &top);
				j++;
            }
			push(infix[i],stack,&top);
		}
		else
		{
			printf("Invalid input\n");
		}
		i++;
        }
		while(top!=-1)
		{
				x=pop(stack,&top);
				postfix[j]=x;
				j++;
        }
		postfix[j] = '\0';
		printf("The Postfix Expression is:\t");
		puts(postfix);
		return 0;
}

void push(char ele, char s[100], int *t)
{
	
	if((*t)<99)
	{
	    (*t) = (*t) + 1;
		s[(*t)] = ele;
	}
	else
	{
		printf("Stack overflow!!");
	}
}

char pop(char s[100],int *t)
{
	char item;
	if(*t>-1)
	{
		item = s[*t];
		(*t) = (*t) - 1;
		return item;
	}
	else
	{
		printf("Stack underflow");
		return ' ';	
	}
}
int is_operator(char s)
{
	if(s=='*'||s=='/'||s=='+'||s=='-'||s=='^')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int precedence(char s)
{
	if(s == '^')
		return 3;
	else if(s == '*' || s == '/')
		return 2;
	else if(s == '+' || s == '-')
		return 1;
	else
		return 0;
}
