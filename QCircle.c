#include<stdio.h>
#define SIZE 3
void insert(int item, int *r, int q[SIZE], int *f)
{
	if(((*f)==(*r)+1)||(((*f)==0)&&(*r==SIZE-1)))
	{
		printf("Queue is full!!\n");
		return;
	}
	if((*f) == (-1))
	{
		(*f) = 0;
	}
	(*r) = (((*r)+1) % SIZE);
	q[(*r)] = item;
}
int delete(int q[SIZE], int *f, int *r)
{
	int item;
	if((*f)==(-1))
	{
		printf("Queue is empty!!!\n");
		return -99999;
	}
	else
	{
		item = q[(*f)];
		if((*f)==(*r))
		{
			(*f) = -1;
			(*r) = -1;
		}
		else
			(*f) = ((*f)+1)%SIZE;
	}
	return item;
}
void display(int f, int r, int q[SIZE])
{
	int i;
	if(f==-1)
	{
		printf("Queue is empty!!\n");
		return;
	}
	printf("The elements are:\t");
	for(int i = f;i!=r;)
	{
		printf("%d\t",q[i]);
		i = ( i + 1 ) % SIZE;
	}
	printf("%d\t",q[r]);
}
int main()
{
	int ele, q[SIZE];
	int f = -1;
	int r = -1;
	int ch;
	do
	{
		printf("\n\n\t1 : Insert an element\n");
		printf("\t2 : Delete an element\n");
		printf("\t3 : Display the elements\n");
		printf("\t4 : Exit\n");
		printf("\n\nEnter your choise:    ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	printf("Enter the element to be inserted:\t");
					scanf("%d",&ele);
					insert(ele,&r,q,&f);
					break;
			case 2: ele = delete(q,&f,&r);
					if(ele != -99999)
						printf("The deleted element is: %d",ele);
					break;
			case 3:	display(f,r,q);
					break;
			case 4: 
					break;
			default:printf("Invalid choise!!!!\n");
		}
	}while(ch!=4);
	return 0;
}
