//Write a C program to convert a given postfix expression to infix expression. (Expression includes operators +, -, * and /)
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

struct stack{
    char stk[SIZE][SIZE];    
    int top;
};

void push(struct stack *s, char item[])
{
    strcpy(s -> stk[++(s -> top)], item);
}

char *pop(struct stack *s)
{
    return (s -> stk[(s -> top)--]);
}

int main()
{
    char postfix[SIZE];
    struct stack s;
    s.top = -1;
    int len, i, j = 0;
    char temp1[SIZE], temp2[SIZE], temp[SIZE]; 
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    len = strlen(postfix);
    for(i = 0; i < len; i++)
    {
        sprintf(temp, "%c", postfix[i]);
        if(isalnum(postfix[i]))
        {
            push(&s, temp);
        }
        else
        {
            strcpy(temp2, pop(&s));
            strcpy(temp1, pop(&s));
            sprintf(temp, "(%s%c%s)", temp1, postfix[i], temp2);
            push(&s, temp);
        }
    }
    printf("The infix of postfix expression %s is %s\n", postfix, pop(&s));
    return 0;
}