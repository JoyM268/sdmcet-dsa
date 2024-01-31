// Write a c function int is_palindrome(char str[]) to check whether given string is a palindrome or not using stacks.
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

int is_palindrome(char str[])
{
    char stack[SIZE];
    int top = -1, i = 0;
    while(str[i] != '\0')
    {
        stack[++top] = str[i];
        i++;
    }
    i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != stack[top--])
            return 0;
        i++;
    }
    return 1;
}

int main()
{
    char str[SIZE];
    printf("Enter the input string: ");
    scanf("%s", str);
    if(is_palindrome(str))
        printf("The string %s is a palindrome\n", str);
    else
        printf("The string %s is not a palindrome\n", str);
    return 0;
}