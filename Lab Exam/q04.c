/* Write a C program to determine if an input string is of the form xCy where x is a string consisting of letters A and B and y is the reverse of x.
Implement using stacks. [Examples: ABBCBBA and ABBACABBA are some of the strings of the given form. ABCAB and BAACABA are some of the strings not of the given form.] */
#include<stdio.h>
#include<string.h>

int isPalindromexcy(char str[])
{
    char s[30], stkItem;
    int i, top = -1;
    for(i = 0; i < strlen(str); i++)
    {
        if(str[i] == 'A' || str[i] == 'B')
        {
            s[++top] = str[i];
        }
        else if(str[i] == 'C')
        {
            break;
        }
    }
    if(i == strlen(str))
    {
        return 0;
    }
    i++;
    while(i < strlen(str))
    {
        stkItem = s[top--];
        if(str[i] != stkItem)
        {
            return 0;
        }
        i++;
    }
    if(top == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char str[30];
    printf("Enter the string: ");
    scanf("%s", str);
    if(isPalindromexcy(str) == 1)
    {
        printf("String is of the form xCy and is a palindrome\n");
    }
    else
    {
        printf("String is not of the form xCy and is not a palindrome\n");
    }
    return 0;
}