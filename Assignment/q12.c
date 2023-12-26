//Write a C program to construct an expression tree for a given postfix expression and evaluate the expression and print the result.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50

struct node{
    char data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE stack[SIZE];
int top = -1;

NODE createNode(char item)
{
    NODE root = (NODE)malloc(sizeof(struct node));
    root -> data = item;
    root -> left = NULL;
    root -> right = NULL;
    return root;
}

NODE createExpTree(char postfix[])
{
    char ch;
    NODE op1, op2, temp;
    int i, len = strlen(postfix);
    for(i = 0; i < len; i++)
    {
        ch = postfix[i];
        temp = createNode(ch);
        if(isalnum(ch))
        {
            stack[++top] =  temp;
        }
        else
        {
            op2 = stack[top--];
            op1 = stack[top--];
            temp -> left = op1;
            temp -> right = op2;
            stack[++top] = temp;
        }
    }
    return stack[top--];
}

int evaluateExpTree(NODE root)
{
    if(root == NULL) return 0;
    if(isdigit(root -> data))
        return root -> data - '0';
    int op1 = evaluateExpTree(root -> left);
    int op2 = evaluateExpTree(root -> right);
    switch(root -> data)
    {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
    }
}

void inorderPrint(NODE root)
{
    if(root == NULL) return;
    inorderPrint(root -> left);
    printf("%c", root -> data);
    inorderPrint(root -> right);
}


void preorderPrint(NODE root)
{
    if(root == NULL) return;
    printf("%c", root -> data);
    preorderPrint(root -> left);
    preorderPrint(root -> right);
}


void postorderPrint(NODE root)
{
    if(root == NULL) return;
    postorderPrint(root -> left);
    postorderPrint(root -> right);
    printf("%c", root -> data);
}

int main()
{
    char postfix[SIZE];
    printf("Enter a valid postfix expression: ");
    scanf("%s", postfix);
    NODE root = createExpTree(postfix);
    printf("\nInorder:\n");
    inorderPrint(root);
    printf("\nPreorder:\n");
    preorderPrint(root);
    printf("\nPostorder:\n");
    postorderPrint(root);
    printf("\n");
    printf("The result of the expression is: %d\n", evaluateExpTree(root));
}