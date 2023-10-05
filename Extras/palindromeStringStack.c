//Check if a string is palindrome using stack
#include<stdio.h>
#include<string.h>
#define SIZE 50

struct stack{
    int stk[SIZE];
    int top;
} s;

void push(int);
int pop(void);
int isPalindrome(char *); 
main()
{
    s.top = -1;
    char str[SIZE];
    printf("Enter the input string: ");
    scanf("%[^\n]", str);
    if(isPalindrome(str))
    {
        printf("%s is a palindrome\n", str);
    }
    else
    {
        printf("%s is not a palindrome\n", str);
    }
}

void push(int item)
{
    if(s.top == SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    s.stk[++s.top] = item;
}

int pop()
{
    if(s.top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return s.stk[s.top--];
}

int isPalindrome(char *str)
{
    int len = strlen(str), i;
    for(i = 0; i < len/2; i++)
    {
        push(str[i]);
    }
    if(len % 2) i++;
    while(str[i])
    {
        if(str[i] != pop())
        {
            return 0;
        }
        i++;
    }
    return 1;
}