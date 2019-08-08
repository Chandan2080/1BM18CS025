#include<stdio.h>
#include<conio.h>
struct Student
{
     int id;
     int age;
     int marks;
};
void main()
{
    struct Student s;
    clrscr();
    printf("Enter Student ID, Age and Marks:  ");
    scanf("%d%d%d",&s.id,&s.age,&s.marks);
    if(s.age>20 && s.marks>=0 && s.marks <=100)
    {
        printf("student details are valid\n");
        if(s.marks>=65)
           printf("student is eligible for admission");
        else
           printf("student is not eligible for admission");
    }
    else
        printf("student details are not valid");
    getch();
}