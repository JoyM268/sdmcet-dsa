//Write a C program to check whether the given expression is balanced expression or not. Hint: Expression involving ( ), { },[ ]
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 30

char stack[SIZE];
int top = -1;

void push(char item)
{
    if(top == SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    stack[++top] = item;
}

char pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        exit(0);
    }
    return stack[top--];
}

int match(char a, char b)
{
    if(a == '(' && b == ')')
        return 1;
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    return 0;
}

int check(char exp[])
{
    int i;
    char temp;
    for(i = 0; i < strlen(exp); i++)
    {
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if(top == -1)
            {
                printf("Right parenthesis are more than left parenthesis\n");
                return 0;
            }
            else
            {
                temp = pop();
                if(!match(temp, exp[i]))
                {
                    printf("Mismatched parenthesized expression\n");
                    printf("%c and %c\n", temp, exp[i]);
                    return 0;
                }
            }
        }
    }
    if(top != -1)
    {
        printf("Left parenthesis are more than right parenthesis\n");
        return 0;
    }
    return 1;
}

int main()
{
    char exp[SIZE];
    printf("Enter a expression: ");
    scanf("%s", exp);
    if(check(exp))
    {
        printf("It is a balanced expression\n");
    }   
    else
    {
        printf("It is not a balanced expression\n");
    }
    return 0;
}