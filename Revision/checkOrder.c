// Write a C function ChkOrd(struct stud [], int) to check whether the array of structures of student records of size N is in asscending order of USN or not
#include<string.h>
#include<stdio.h>
#define SIZE 50

struct stud{
    char name[30];
    char USN[11];
    int rollno;
};

void readDetails(struct stud s[], int n)
{
    int i;
    printf("Enter the student details:\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter the name, USN, rollno of student %d: ", i + 1);
        scanf("%s %s %d", s[i].name, s[i].USN, &s[i].rollno);
    }
}

int ChkOrd(struct stud s[], int n)
{
    int i;
    for(i = 0; i < n - 1; i++)
    {
        if(strcmp(s[i].USN, s[i + 1].USN) > 0) return 0;
    }
    return 1;
}

int main()
{
    int n;
    struct stud s[SIZE];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    readDetails(s, n);
    if(ChkOrd(s, n))
    {
        printf("\nThe details are in ascending order of USN\n");
        return 0;
    }
    printf("\nThe details are not in ascending order of USN\n");
    return 1;
}