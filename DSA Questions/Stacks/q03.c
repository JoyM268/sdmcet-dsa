/* Write a C subroutine to determine if an input string is of the form x C y where x is a string consisting of letters A and B and y is the reverse of x. 
Implement using stacks. [Examples: ABBCBBA and ABBACABBA are some of the strings of the given form. BCAB and BAACABA are some of the strings not of the 
given form.] */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

int checkXCY(char str[])
{
    char stack[SIZE], popItem;
    int len = strlen(str), i, top = -1;
    for(i = 0; i < len; i++)
    {
        if(str[i] == 'A' || str[i] == 'B')
            stack[++top] = str[i];
        else if(str[i] == 'C')
            break;
    }
    if(i == len) return 0;
    i++;
    while(i < len)
    {
        popItem = stack[top--];
        if(str[i] != popItem)
            return 0;
        i++;
    }
    if(top == -1) return 1;
    return 0;
}

int main()
{
    char str[SIZE];
    printf("Enter the input string: ");
    scanf("%s", str);
    if(checkXCY(str))
        printf("The string %s is of the form xCy\n");
    else
        printf("The string %s is not of the form xCy\n");
    return 0;
}