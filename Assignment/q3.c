//Write a C program to convert a given postfix expression to infix expression. (Expression includes operators +, -, * and /)
//Method 1
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

char stack[SIZE][SIZE];
int top = -1;

void push(char item[])
{
    strcpy(stack[++top], item);
}

void pop(char item[])
{
    strcpy(item, stack[top--]);
}

int main()
{
    int i = 0;
    char postfix[SIZE], left[SIZE], right[SIZE], result[SIZE], item[2], ch;
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    while(postfix[i] != '\0')
    {
        ch = postfix[i++];
        item[0] = ch, item[1] = '\0';
        if(isalpha(ch) || isdigit(ch))
        {
            push(item);
        }
        else
        {
            pop(right);
            pop(left);
            strcpy(result, "(");
            strcat(result, left);
            strcat(result, item);
            strcat(result, right);
            strcat(result, ")");
            push(result);
        }
    }
    pop(result);
    if(top != -1)
    {
        printf("Invalid expression\n");
        return 0;
    }
    printf("The infix of postfix expression %s is %s\n", postfix, result);
    return 0;
}

//Method 2 (Using sprintf())
/*
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
        if(isalpha(postfix[i]) || isdigit(postfix[i]))
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
*/