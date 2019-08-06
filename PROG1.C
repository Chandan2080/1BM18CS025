#include<conio.h>
#include<stdio.h>
struct mark
{
  int sub1;
  int sub2;
  int sub3;
};
void main()
{
     struct mark s1;
     clrscr();
     printf("Enter the marks of Student 1: \n");
     printf("Subject 1: ");
     scanf("%d",&s1.sub1);
     printf("Subject 2: ");
     scanf("%d",&s1.sub2);
     printf("Subject 3: ");
     scanf("%d",&s1.sub3);

     printf("The marks of Student 1 are:");
     printf("\nSubject 1: %d",s1.sub1);
     printf("\nSubject 2: %d",s1.sub2);
     printf("\nSubject 3: %d",s1.sub3);

     getch();
}
