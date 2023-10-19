//Write a C program to check whether a given expression is balanced expression or not
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 30

int top = -1;
char stack[MAX];
void push(char);
char pop();
int match(char a, char b);
int check(char[]);

int main()
{
    char exp[MAX];
    int valid;
    printf("Enter an expression: ");
    scanf("%s", exp);
    valid = check(exp);
    if(valid == 1)
    {
        printf("Valid/balanced expression\n");
    }
    else
    {
        printf("Invalid/unbalanced expression\n");
    }
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
    if(top == -1)
    {
        printf("Balanced parenthesis\n");
        return 1;
    }
    else
    {
        printf("Left parenthesis are more than right parenthesis\n");
        return 0;
    }
}

char pop()
{
    if(top == -1)
    {
        printf("Stack underflow\n");
        exit(0);
    }
    return (stack[top--]);
}

int match(char a, char b)
{
    if(a == '[' && b == ']')
        return 1;
    if(a == '{' && b == '}')
        return 1;
    if(a == '(' && b == ')')
        return 1;
    return 0;
}

void push(char item)
{
    if(top == (MAX - 1))
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}