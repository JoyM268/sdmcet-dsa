//Write a C program to check if the string is palindrome or not using stacks
#include<stdio.h>
#include<string.h>

int isPalindrome(char str[])
{
    int i, top = -1;
    char s[30], stkItem;
    for(i = 0; i < strlen(str); i++)
    {
        s[++top] = str[i];
    }
    for(i = 0; i < strlen(str); i++)
    {
        stkItem = s[top--];
        if(str[i] != stkItem)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str[30];
    printf("Enter the string: ");
    scanf("%s", str);
    if(isPalindrome(str) == 1)
    {
        printf("String is palindrome\n");
    }
    else
    {
        printf("String is not palindrome\n");
    }
    return 0;
}