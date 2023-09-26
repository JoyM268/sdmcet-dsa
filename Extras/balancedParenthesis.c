//program to examine whether the pairs and the orders of {, }, (, ), [, ] are correct in the given expression.
#include<stdio.h>
#include<string.h>
#define SIZE 50

struct stack{
    char stk[SIZE];
    int top;
} s;

void push(char item)
{
    s.stk[++s.top] = item;
}

char pop()
{
    return s.stk[s.top--];
}

int checkPair(char a, char b)
{
    return ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'));
}

int isBalanced(char *str)
{
    int len = strlen(str), openCount = 0, closeCount = 0;
    char temp;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
        {
            push(str[i]);
            openCount++;
        }
        else if(str[i] == '}' || str[i] == ']' || str[i] == ')')
        {
            if(s.top == -1) return 0;
            temp = pop();
            if(!(checkPair(temp, str[i])))
            {
                return 0;
            }
            closeCount++;
        }
    }
    if(s.top != -1 || (openCount != closeCount))
    {
        return 0;
    }
    return 1;
}

main()
{
    s.top = -1;
    char str[SIZE];
    printf("Enter the input string: ");
    scanf("%s", str);
    if(isBalanced(str))
    {
        printf("It is balanced");
    } 
    else
    {
        printf("It is not balanced");
    }
}
