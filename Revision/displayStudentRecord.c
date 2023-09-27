//Write a C program to to display specified student record from an array of records based on the USN.
#include<stdio.h>
#include<string.h>
#define SIZE 50

struct studentDetails{
    char name[30];
    char USN[11];
    int rollno;
};

void readDetails(struct studentDetails s[], int n)
{
    int i;
    printf("Enter the student details:\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter the name, USN, rollno. of student %d: " , i + 1);
        scanf("%s %s %d", s[i].name, s[i].USN, &s[i].rollno);
    }
}

void display(struct studentDetails s[], int index)
{
    printf("\nStudent details:\n");
    printf("Name: %s\n", s[index].name);
    printf("USN: %s\n", s[index].USN);
    printf("Rollno: %d\n", s[index].rollno);
}

int searchStudent(struct studentDetails s[], int n, char str[])
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(!strcmp(s[i].USN, str))
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    struct studentDetails s[SIZE];
    int n, index;
    char USN[11];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    readDetails(s, n);
    printf("Enter the USN: ");
    scanf("%s", USN);
    index = searchStudent(s, n, USN);
    if(index == -1)
    {
        printf("USN does not exist\n");
        return 1;
    }
    display(s, index);
    return 0;
}