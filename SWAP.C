#include<stdio.h>
#include<conio.h>
void swap(int *p1,int *p2);
void main()
{
	int a, b, *p1, *p2;
	p1 = &a;
	p2 = &b;
	printf("Enter value of a & b:  ");
	scanf("%d%d",p1,p2);
	printf("\nBefor swapping:  ");
	printf("a=%d  b=%d",*p1,*p2);
	printf("\nValues after swapping are  ");
	swap(p1,p2);
	printf("  a=%d\n  b=%d",*p1,*p2);
	getch();
}
void swap(int *p1,int *p2)
{
	*p1 = *p1 + *p2;
	*p2 = *p1 - *p2;
	*p1 = *p1 - *p2;
}