#include<stdio.h>
#define SIZE 10
void insert(int item, int *r, int q[])
{
	if((*r)== SIZE-1)
	{
		printf("Queue overflow!!\n");
		return;
	}
	(*r) = (*r) + 1;
	q[(*r)] = item;
}
int delete(int q[SIZE], int *f, int *r)
{
	int item;
	if((*f)>(*r))
	{
		printf("Queue underflow!!\n");
		return -99999;
	}
	item = q[(*f)];
	(*f) = (*f) + 1;
	return item;
}
void display(int q[SIZE], int r, int f)
{
	int i;
	if(f>r)
	{
		printf("Queue is empty!!\n");
		return;
	}
	printf("Contents of queue are :\n");
	for(i=f;i<=r;i++)
		printf(" %d",q[i]);
	printf("\n");
}
int main()
{
	int ele, q[SIZE];
	int f = 0;
	int r = -1;
	int ch;
	do
	{
		printf("Enter your choise:\n");
		printf("1 : Insert an element\n");
		printf("2 : Delete an element\n");
		printf("3 : Display the elements\n");
		printf("4 : Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the element to be inserted:\t");
					scanf("%d",&ele);
					insert(ele,&r,q);
					break;
			case 2: ele = delete(q,&f,&r);
					if(ele != -99999)
						printf("The deleted element is: %d",ele);
					break;
			case 3:	display(q, r,f);
					break;
			case 4: break;
			default:printf("Invalid choise!!!!\n");
		}
	}while(ch!=4);
	return 0;
}
