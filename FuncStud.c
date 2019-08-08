#include<stdio.h>
#include<conio.h>
struct Student
{
	int id;
	int age;
	int marks;
};
int validate(struct Student s);
int qualify(struct Student s);
int main()
{
    struct Student st[100];
    int i, n;
    printf("Enter the number of students:  ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      printf("\nEnter ID, Age, Marks of student %d",i+1);
      scanf("%d%d%d",&st[i].id,&st[i].age,&st[i].marks);
      if(qualify(st[i]))
      {
        printf("\nStudent %d is eligible for admission");
        else
        printf("\nStudent %d is not eligible for admission",i+1);
      }
    }
    return 0;
}

int validate(struct Student s)
{
    if(s.age>20 && s.marks>=0 && s.marks<=0)
    return 1;
    else
    return 0;
}

int qualify(struct Student s)
{
    if(validate(s))
    {
        if(s.marks>=65)
        return 1;
        else 
        return 0;
    }
    else
    printf("\n\nDetails not valid");   
}
